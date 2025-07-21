#include <stdio.h>
#include <string>

void main() {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
        printf("%d", getchar() != EOF);
    }
}
