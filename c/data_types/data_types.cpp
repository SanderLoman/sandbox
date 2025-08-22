/*
 * ---------------------------------------------
 * C Fundamental Type Sizes on Common Platforms (complete)
 * (sizes in bytes)
 *
 * Type                | Win 32-bit (ILP32) | Win 64-bit (LLP64) | Linux/macOS 32-bit (ILP32) | Linux/macOS 64-bit (LP64)
 * -----------------------------------------------------------------------------------------------------------------------
 * char                | 1                  | 1                  | 1                          | 1
 * signed char         | 1                  | 1                  | 1                          | 1
 * unsigned char       | 1                  | 1                  | 1                          | 1
 * _Bool / bool        | 1                  | 1                  | 1                          | 1
 * short               | 2                  | 2                  | 2                          | 2
 * unsigned short      | 2                  | 2                  | 2                          | 2
 * int                 | 4                  | 4                  | 4                          | 4
 * unsigned int        | 4                  | 4                  | 4                          | 4
 * long                | 4                  | 4                  | 4                          | 8
 * unsigned long       | 4                  | 4                  | 4                          | 8
 * long long           | 8                  | 8                  | 8                          | 8
 * unsigned long long  | 8                  | 8                  | 8                          | 8
 * void *              | 4                  | 8                  | 4                          | 8
 * size_t              | 4                  | 8                  | 4                          | 8
 * ptrdiff_t           | 4                  | 8                  | 4                          | 8
 * intptr_t            | 4                  | 8                  | 4                          | 8
 * uintptr_t           | 4                  | 8                  | 4                          | 8
 * float               | 4                  | 4                  | 4                          | 4
 * double              | 8                  | 8                  | 8                          | 8
 * long double         | 8                  | 8                  | 12                         | 16
 * int8_t / uint8_t    | 1                  | 1                  | 1                          | 1
 * int16_t / uint16_t  | 2                  | 2                  | 2                          | 2
 * int32_t / uint32_t  | 4                  | 4                  | 4                          | 4
 * int64_t / uint64_t  | 8                  | 8                  | 8                          | 8
 *
 * Data models:
 * - ILP32  : int, long, and pointers are 32-bit (4 bytes)
 * - LLP64  : long is 32-bit, long long is 64-bit, pointers are 64-bit (8 bytes)
 * - LP64   : long and pointers are 64-bit, int is 32-bit
 *
 * Notes:
 * - All sizes are in bytes. (On virtually all modern systems, 1 byte == 8 bits.)
 * - long double varies a lot: Windows (MSVC) = 8; Linux x86-64 SysV = 16 (80-bit ext in 16B storage);
 *   Linux 32-bit often 12; macOS x86-64 typically 16, macOS arm64/iOS = 8.
 * - Fixed-width types (int8_t, uint32_t, etc.) come from <stdint.h>.
 * - ptrdiff_t is the signed counterpart to size_t and tracks pointer width on these ABIs.
 */

 /*
 * ---------------------------------------------
 * Supplemental: Historical / Niche C Data Models (sizes in bytes)
 *
 * Type / Model        |   LP32   |  ILP32  |   LP64   |  LLP64  |  ILP64  |  SILP64
 * ----------------------------------------------------------------------------------
 * char                |    1     |    1    |    1     |    1    |    1    |    1
 * signed/unsigned char|    1     |    1    |    1     |    1    |    1    |    1
 * _Bool / bool        |    1     |    1    |    1     |    1    |    1    |    1
 * short               |    2     |    2    |    2     |    2    |    2    | **8**  (*rare*)
 * unsigned short      |    2     |    2    |    2     |    2    |    2    | **8**
 * int                 | **2**    | **4**   | **32→4** | **4**   | **8**   | **8**
 * unsigned int        | **2**    | **4**   | **4**    | **4**   | **8**   | **8**
 * long                | **4**    | **4**   | **8**    | **4**   | **8**   | **8**
 * unsigned long       | **4**    | **4**   | **8**    | **4**   | **8**   | **8**
 * long long           |    8     |    8    |    8     | **8**   |    8    |    8
 * unsigned long long  |    8     |    8    |    8     | **8**   |    8    |    8
 * void * (pointer)    | **4**    | **4**   | **8**    | **8**   | **8**   | **8**
 * size_t / ptrdiff_t  |    4     |    4    |    8     |    8    |    8    |    8
 * intptr_t/uintptr_t  |    4     |    4    |    8     |    8    |    8    |    8
 * float               |    4     |    4    |    4     |    4    |    4    |    4
 * double              |    8     |    8    |    8     |    8    |    8    |    8
 * long double         |  8–12    |  8–12   |  8–16    |    8    |  8–16   |  8–16
 *
 * Where seen (typical):
 * - LP32   : 16-bit era with 32-bit long & flat 32-bit pointers (some 32-bit embedded/old compilers)
 * - ILP32  : 32-bit Unix/*BSD/Linux, old macOS/iOS/Android, 32-bit ARM
 * - LP64   : 64-bit Unix/*BSD/Linux, macOS, iOS/Android on arm64, RISC-V64, AArch64
 * - LLP64  : 64-bit Windows (x86-64/ARM64)
 * - ILP64  : rare HPC/older 64-bit Unixes (historical Cray, niche scientific stacks)
 * - SILP64 : extremely rare, mostly academic/historical; 64-bit short/int/long/pointer
 *
 * Notes:
 * - Bold entries are the defining differences of each model.
 * - long double is ABI-specific; check your toolchain docs if you rely on it.
 */


#include <stdio.h>
#include <cstdbool>
#include <stdbool.h>
#include <stdint.h>
#include <cstdint>

int main(void) {
    // char type
    printf("Size of CHAR     : %zu bytes\n", sizeof(char));

    // int type
    printf("Size of INT      : %zu bytes\n", sizeof(int));

    // float type
    printf("Size of FLOAT    : %zu bytes\n", sizeof(float));

    // long type
    printf("Size of LONG     : %zu bytes\n", sizeof(long));

    // short type
    printf("Size of SHORT    : %zu bytes\n", sizeof(short));

    // double type
    printf("Size of DOUBLE   : %zu bytes\n", sizeof(double));

    // bool type
    printf("Size of BOOL     : %zu bytes\n", sizeof(bool));

    // long long type
    printf("Size of LONG LONG: %zu bytes\n", sizeof(long long));
    return 0;
}
