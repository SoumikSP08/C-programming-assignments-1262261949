#include <stdio.h>

int main()
{
    FILE *fp1, *fp2;
    char source[50], dest[50];
    int ch;

    printf("Enter source file name: ");
    scanf("%s", source);
    printf("Enter destination file name: ");
    scanf("%s", dest);

    fp1 = fopen(source, "r");
    if (fp1 == NULL)
    {
        printf("Source file cannot be opened\n");
        return 0;
    }

    fp2 = fopen(dest, "w");
    if (fp2 == NULL)
    {
        printf("Destination file cannot be created\n");
        fclose(fp1);
        return 0;
    }

    ch = fgetc(fp1);
    while (ch != EOF)
    {
        fputc(ch, fp2);
        ch = fgetc(fp1);
    }

    printf("File copied successfully\n");

    fclose(fp1);
    fclose(fp2);
    return 0;
}
