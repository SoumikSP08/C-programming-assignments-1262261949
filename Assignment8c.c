#include <stdio.h>

/* Call by reference: receives the addresses of the two speeds */
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int motor1, motor2;      /* speeds of the two robot motors */
    int *p1, *p2;            /* pointers to the motor speeds   */
    int old1, old2;          /* copies kept only to verify the swap */

    printf("Enter the first motor speed: ");
    scanf("%d", &motor1);
    printf("Enter the second motor speed: ");
    scanf("%d", &motor2);

    /* store the addresses of the motors in the pointers */
    p1 = &motor1;
    p2 = &motor2;

    old1 = motor1;
    old2 = motor2;

    printf("\nBefore Swapping:\n");
    printf("First motor speed=%d, Second motor speed=%d\n", *p1, *p2);
    printf("Address of first motor  = %p\n", (void *)p1);
    printf("Address of second motor = %p\n", (void *)p2);

    /* pass the addresses to swap() */
    swap(p1, p2);

    printf("\nAfter Swapping:\n");
    printf("First motor speed=%d, Second motor speed=%d\n", motor1, motor2);
    printf("Address of first motor  = %p\n", (void *)p1);
    printf("Address of second motor = %p\n", (void *)p2);

    /* verify the swap */
    if (motor1 == old2 && motor2 == old1)
        printf("\nVerification: Swap successful (addresses unchanged, values exchanged).\n");
    else
        printf("\nVerification: Swap failed.\n");

    return 0;
}
