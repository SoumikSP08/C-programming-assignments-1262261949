#include <stdio.h>

{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int motor1, motor2;
    int *p1, *p2;       
    int old1, old2;

    printf("Enter the first motor speed: ");
    scanf("%d", &motor1);
    printf("Enter the second motor speed: ");
    scanf("%d", &motor2);

    p1 = &motor1;
    p2 = &motor2;

    old1 = motor1;
    old2 = motor2;

    printf("\nBefore Swapping:\n");
    printf("First motor speed=%d, Second motor speed=%d\n", *p1, *p2);
    printf("Address of first motor  = %p\n", (void *)p1);
    printf("Address of second motor = %p\n", (void *)p2);

    swap(p1, p2);

    printf("\nAfter Swapping:\n");
    printf("First motor speed=%d, Second motor speed=%d\n", motor1, motor2);
    printf("Address of first motor  = %p\n", (void *)p1);
    printf("Address of second motor = %p\n", (void *)p2);

    if (motor1 == old2 && motor2 == old1)
        printf("\nVerification: Swap successful (addresses unchanged, values exchanged).\n");
    else
        printf("\nVerification: Swap failed.\n");

    return 0;
}
