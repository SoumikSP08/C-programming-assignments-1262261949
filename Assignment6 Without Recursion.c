#include <stdio.h>


unsigned long long factorial_iterative(int n);

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

    printf("Factorial of number (without recursion) = %llu\n", factorial_iterative(num));

    return 0;
}


unsigned long long factorial_iterative(int n)
{
    unsigned long long fact = 1;
    int i;

    for (i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}
