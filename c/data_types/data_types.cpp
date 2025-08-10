/*
 * This file is a practise exercise.
 * I will be displaying all C types and the combination of those C types.
 * And how you can use them.
 *
 * And also the context behind the keyword.
 */

#include <stdio.h>

int main(void) {
    // Types can differ in size depending on what OS is being used.
    //
    // I'll show a table that displays how big each data type can be depending
    // on what OS compiles the program.

    // C Fundamental Type Sizes on Common Platforms
    // ---------------------------------------------
    //
    // Type               | Win 32-bit (ILP32) | Win 64-bit (LLP64) | Linux/macOS 32-bit (ILP32) | Linux/macOS 64-bit (LP64)
    // -----------------------------------------------------------------------------------------------------------------------
    // char                | 1                  | 1                  | 1                          | 1
    // signed char         | 1                  | 1                  | 1                          | 1
    // unsigned char       | 1                  | 1                  | 1                          | 1
    // _Bool / bool        | 1                  | 1                  | 1                          | 1
    // short               | 2                  | 2                  | 2                          | 2
    // unsigned short      | 2                  | 2                  | 2                          | 2
    // int                 | 4                  | 4                  | 4                          | 4
    // unsigned int        | 4                  | 4                  | 4                          | 4
    // long                | 4                  | 4                  | 4                          | 8
    // unsigned long       | 4                  | 4                  | 4                          | 8
    // long long           | 8                  | 8                  | 8                          | 8
    // unsigned long long  | 8                  | 8                  | 8                          | 8
    // void *              | 4                  | 8                  | 4                          | 8
    // size_t              | 4                  | 8                  | 4                          | 8
    // intptr_t            | 4                  | 8                  | 4                          | 8
    // uintptr_t           | 4                  | 8                  | 4                          | 8
    // float               | 4                  | 4                  | 4                          | 4
    // double              | 8                  | 8                  | 8                          | 8
    // long double         | 8                  | 8                  | 12                         | 16
    // int8_t / uint8_t    | 1                  | 1                  | 1                          | 1
    // int16_t / uint16_t  | 2                  | 2                  | 2                          | 2
    // int32_t / uint32_t  | 4                  | 4                  | 4                          | 4
    // int64_t / uint64_t  | 8                  | 8                  | 8                          | 8
    //
    // Data models:
    // - ILP32  : int, long, and pointers are 32-bit
    // - LLP64  : long is 32-bit, long long is 64-bit, pointers are 64-bit
    // - LP64   : long and pointers are 64-bit, int is 32-bit
    //
    // Notes:
    // - All sizes are in bytes.
    // - `long double` varies: on macOS it is 8 bytes (same as double), on Linux x86-64 it is 16 bytes, and on Linux 32-bit often 12 bytes.
    // - Fixed-width types (int8_t, uint32_t, etc.) are defined in <stdint.h> and have the same size on all modern mainstream platforms.
    // - Linux and macOS share the LP64 model in 64-bit mode.
    // - Linux and older macOS (before ~2007) shared the ILP32 model in 32-bit mode.

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
