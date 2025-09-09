#include <cstdio>
#include <cstring>

typedef enum Type {
    CELCIUS,
    FAHRENHEIT
} type;

int main(void) {
    type unit;
    char choice;

    printf("Choose a unit to convert from: CELCIUS (c) or FAHRENHEIT (f)\n");

    scanf("%c", &choice);
    printf("%c\n", choice);

    return 0;
}
