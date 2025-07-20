#include <stdio.h>

void main() {
    constexpr int lower = 0;
    constexpr int upper = 300;
    constexpr int step = 20;

    int fahr = lower;

    while (fahr <= upper) {
        const int celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
