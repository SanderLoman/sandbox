#include <stdio.h>
#include <string>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
        printf("%d", getchar() != EOF);
    }
}
