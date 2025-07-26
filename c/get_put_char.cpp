#include <stdio.h>

int main() {
    printf("input a character: ");
    char c = getchar();

    printf("%c\n", c);

    // just prints what c is
    putchar(c);
}