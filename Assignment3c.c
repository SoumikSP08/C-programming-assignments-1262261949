/*
 * Lab Assignment 3 - Programming and Problem Solving
 * Menu-driven program in C to implement basic arithmetic operations.
 */

#include <stdio.h>

int main() {
    int choice;
    float a, b, sum;

    printf("Menu\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 5) {
        printf("Exited program.\n");
        return 0;
    }

    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);

    switch (choice) {
        case 1:
            sum = a + b;
            printf("Addition is %.2f\n", sum);
            break;

        case 2:
            sum = a - b;
            printf("Subtraction is %.2f\n", sum);
            break;

        case 3:
            sum = a * b;
            printf("Multiplication is %.2f\n", sum);
            break;

        case 4:
            if (b != 0) {
                sum = a / b;
                printf("Division is %.2f\n", sum);
            } else {
                printf("Division by zero not allowed.\n");
            }
            break;

        default:
            printf("Invalid Input\n");
    }

    return 0;
}
