#include <stdio.h>
#include <stdbool.h>

int main() {
    bool a = true;
    char b = 'a';
    int c = 1;
    float d = 1.1;

    // This can represent binary
    signed char e = -5; // Currently says: 11111011
    unsigned char e = 5; // Currently says: 00000101

    printf("This signed char in binary says: %d\n", e);

    return 0;
}