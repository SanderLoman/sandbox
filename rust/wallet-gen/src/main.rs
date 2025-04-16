use clap::Parser;
use hex::encode as hex_encode;
use rand::RngCore;
use rayon::prelude::*;
use secp256k1::{PublicKey, Secp256k1, SecretKey};
use std::{
    iter::repeat_with,
    sync::{
        atomic::{AtomicBool, AtomicU64, Ordering},
        Arc,
    },
    time::Instant,
};
use tiny_keccak::{Hasher, Keccak}; // using the thread-local RNG from rand

/// Simple Ethereum vanity wallet generator
#[derive(Parser, Debug)]
#[command(author, version, about, long_about = None)]
struct Args {
    /// Prefix pattern for the Ethereum address (without '0x'), case insensitive
    #[arg(short, long, default_value = "")]
    prefix: String,

    /// Suffix pattern for the Ethereum address (without '0x'), case insensitive
    #[arg(short, long, default_value = "")]
    suffix: String,

    /// Number of threads to use (default: number of logical CPUs)
    #[arg(short, long)]
    threads: Option<usize>,
}

fn keccak256(input: &[u8]) -> [u8; 32] {
    let mut hasher = Keccak::v256();
    let mut output = [0u8; 32];
    hasher.update(input);
    hasher.finalize(&mut output);
    output
}

/// Derive Ethereum address from public key (uncompressed, 65 bytes)
fn eth_address_from_pubkey(pubkey: &PublicKey) -> String {
    let pubkey_bytes = pubkey.serialize_uncompressed();
    let hash = keccak256(&pubkey_bytes[1..]);
    let address = &hash[12..];
    hex_encode(address)
}

fn main() {
    let args = Args::parse();

    let prefix = args.prefix.to_lowercase();
    let suffix = args.suffix.to_lowercase();

    let threads = args.threads.unwrap_or_else(num_cpus::get);
    rayon::ThreadPoolBuilder::new()
        .num_threads(threads)
        .build_global()
        .unwrap();

    let secp = Secp256k1::new();

    // If no prefix or suffix is provided, generate one random wallet and exit.
    if prefix.is_empty() && suffix.is_empty() {
        let mut rng = rand::thread_rng();
        let sk = loop {
            let mut key_bytes = [0u8; 32];
            rng.fill_bytes(&mut key_bytes);
            if let Ok(sk) = SecretKey::from_slice(&key_bytes) {
                break sk;
            }
        };
        let pubkey = PublicKey::from_secret_key(&secp, &sk);
        let address = eth_address_from_pubkey(&pubkey);

        println!("Generated random wallet:");
        println!("Private Key: 0x{}", hex_encode(sk.secret_bytes()));
        println!("Address: 0x{}", address);
        return;
    }

    let found = Arc::new(AtomicBool::new(false));
    let attempts = Arc::new(AtomicU64::new(0));
    let start = Instant::now();

    println!(
        "Starting search with prefix '{}' and suffix '{}' on {} threads...",
        prefix, suffix, threads
    );

    repeat_with(|| {
        // Create a thread-local RNG per iteration, then loop until a valid key is found.
        let mut rng = rand::thread_rng();
        loop {
            let mut key_bytes = [0u8; 32];
            rng.fill_bytes(&mut key_bytes);
            if let Ok(sk) = SecretKey::from_slice(&key_bytes) {
                return sk;
            }
        }
    })
    .take_while(|_| !found.load(Ordering::Relaxed))
    .par_bridge()
    .for_each_with(
        (found.clone(), attempts.clone()),
        |(found_flag, attempts_counter), sk| {
            if found_flag.load(Ordering::Relaxed) {
                return;
            }

            attempts_counter.fetch_add(1, Ordering::Relaxed);

            let pubkey = PublicKey::from_secret_key(&secp, &sk);
            let address = eth_address_from_pubkey(&pubkey);
            // hex::encode already returns lowercase, so we compare directly.
            let prefix_match = prefix.is_empty() || address.starts_with(&prefix);
            let suffix_match = suffix.is_empty() || address.ends_with(&suffix);

            if prefix_match && suffix_match {
                if !found_flag.swap(true, Ordering::Relaxed) {
                    let elapsed = start.elapsed();
                    println!("Found matching wallet!");
                    println!("Private Key: {}", hex_encode(sk.secret_bytes()));
                    println!("Address: 0x{}", address);
                    println!("Attempts: {}", attempts_counter.load(Ordering::Relaxed));
                    println!(
                        "Elapsed time: {:.2?} ({} seconds)",
                        elapsed,
                        elapsed.as_secs()
                    );
                }
            }
        },
    );
}
