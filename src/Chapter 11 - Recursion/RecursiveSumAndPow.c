#include "stdio.h"
/*
 * Recursive function for the sum of the elements of an array
 */
int recursive_sum(int *array, int index)
{
    if(index < 0) return 0;
    return array[index] + recursive_sum(array, index - 1);
}
/*
 * Recursive function for finding the power of x^n
 */
int recursive_pow(int base, int exp)
{
    if(exp == 0) return 1;
    return base * recursive_pow(base, exp - 1);
}

int main()
{
    int array[] = {2, 3, 4, 5};
    int array_len = sizeof(array) / sizeof(int);
    printf("Sum: %d.\n", recursive_sum(array, array_len - 1));
    printf("Power: %d.\n", recursive_pow(2, 5));
    return 0;
}
