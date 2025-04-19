#include <stdio.h>

void function()
{
    printf("Hello from function!\n");
}

int increment(int num)
{
    return num++;
}

void addTwo(int a, int b)
{
    printf("Sum of the equasion: %d\n", a + b);
}

int main(void)
{
    int myAge = 21;    // An int variable
    int *ptr = &myAge; // A pointer variable, with the name ptr, that stores the address of myAge

    // Output the value of myAge (21)
    printf("%d\n", myAge);

    // Output the memory address of myAge (0x7ffe5367e044)
    printf("%p\n", &myAge);

    // Output the memory address of myAge with the pointer (0x7ffe5367e044)
    printf("%p\n", ptr);

    return 0;
}