#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

void main() {
    bool when = true;

    constexpr unsigned int lower = LOWER;
    constexpr unsigned int upper = UPPER;
    constexpr unsigned int step = STEP;

    float fahr = upper;

    if (when) {
        printf("Running while loop\n");
        while (fahr >= lower) {
            printf("%3.0f\t%6.1f\n", fahr, 5.0 / 9.0 * (fahr - 32));
            fahr = fahr - step;
        }
    } else {
        printf("Running for loop\n");
        for (fahr; fahr >= lower; fahr = fahr - step) {
            printf("%3.0f\t%6.1f\n", fahr, 5.0 / 9.0 * (fahr - 32));
        }
    }
}
