#include <stdio.h>

unsigned long long factorial_recursive(int n);

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    if (num > 20)
    {
        printf("Number too large: result overflows unsigned long long (max n = 20).\n");
        return 1;
    }

    printf("Factorial of number (with recursion) = %llu\n", factorial_recursive(num));

    return 0;
}

unsigned long long factorial_recursive(int n)
{
    if (n == 0 || n == 1)                        /* base case */
        return 1;
    else
        return n * factorial_recursive(n - 1);   /* recursive case */
}
