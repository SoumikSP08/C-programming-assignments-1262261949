#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int i, n = strlen(s);
    char t;
    for (i = 0; i < n / 2; i++) {
        t = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = t;
    }
}

void upper(char s[]) {
    int i;
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 32;
}

void lower(char s[]) {
    int i;
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;
}

int main() {
    char a[100], b[100], r[200];
    int ch, n;
    do {
        printf("\n1.Length 2.Concatenate 3.Copy 4.Compare 5.Reverse\n");
        printf("6.Uppercase 7.Lowercase 8.Substring 9.Palindrome 0.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter string: ");
            scanf("%s", a);
            n = strlen(a);
            printf("Length = %d\n", n);
            break;
        case 2:
            printf("Enter two strings: ");
            scanf("%s %s", a, b);
            strcpy(r, a);
            strcat(r, b);
            printf("Result = %s\n", r);
            break;
        case 3:
            printf("Enter string: ");
            scanf("%s", a);
            strcpy(b, a);
            printf("Copied string = %s\n", b);
            break;
        case 4:
            printf("Enter two strings: ");
            scanf("%s %s", a, b);
            n = strcmp(a, b);
            if (n == 0)
                printf("Strings are equal\n");
            else if (n < 0)
                printf("First string is smaller\n");
            else
                printf("First string is greater\n");
            break;
        case 5:
            printf("Enter string: ");
            scanf("%s", a);
            reverse(a);
            printf("Reversed = %s\n", a);
            break;
        case 6:
            printf("Enter string: ");
            scanf("%s", a);
            upper(a);
            printf("Uppercase = %s\n", a);
            break;
        case 7:
            printf("Enter string: ");
            scanf("%s", a);
            lower(a);
            printf("Lowercase = %s\n", a);
            break;
        case 8:
            printf("Enter main string and substring: ");
            scanf("%s %s", a, b);
            if (strstr(a, b) != NULL)
                printf("Substring found\n");
            else
                printf("Substring not found\n");
            break;
        case 9:
            printf("Enter string: ");
            scanf("%s", a);
            strcpy(b, a);
            reverse(b);
            if (strcmp(a, b) == 0)
                printf("Palindrome\n");
            else
                printf("Not a palindrome\n");
            break;
        case 0:
            printf("Exiting program\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (ch != 0);
    return 0;
}
