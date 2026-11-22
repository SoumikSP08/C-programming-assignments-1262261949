#include <stdio.h>

struct Record {
    int x, y;
    float dist;
    int obstacle;   // 1 = obstacle, 0 = clear
    char dir;       // F, B, L, R
};

int main() {
    FILE *fp;
    struct Record r[100];
    int n, i, j, total = 0, times, printed, found = 0;

    // writing navigation data into the file
    fp = fopen("navigation.txt", "a");
    if (fp == NULL) {
        printf("File cannot be opened\n");
        return 1;
    }

    printf("How many records? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nRecord %d\n", i + 1);
        printf("Enter x y: ");
        scanf("%d %d", &r[0].x, &r[0].y);
        printf("Enter distance: ");
        scanf("%f", &r[0].dist);
        printf("Obstacle (1/0): ");
        scanf("%d", &r[0].obstacle);
        printf("Direction (F/B/L/R): ");
        scanf(" %c", &r[0].dir);

        fprintf(fp, "%d %d %.1f %d %c\n", r[0].x, r[0].y,
                r[0].dist, r[0].obstacle, r[0].dir);
    }
    fclose(fp);

    // reading the history back from the file
    fp = fopen("navigation.txt", "r");
    while (total < 100 &&
           fscanf(fp, "%d %d %f %d %c", &r[total].x, &r[total].y,
                  &r[total].dist, &r[total].obstacle, &r[total].dir) == 5) {
        total++;
    }
    fclose(fp);

    printf("\nNavigation history (%d records):\n", total);
    for (i = 0; i < total; i++)
        printf("(%d,%d) dist=%.1f obstacle=%d dir=%c\n", r[i].x, r[i].y,
               r[i].dist, r[i].obstacle, r[i].dir);

    // finding repeated obstacles
    printf("\nRepeated obstacles:\n");
    for (i = 0; i < total; i++) {
        if (r[i].obstacle == 0)
            continue;

        printed = 0;
        for (j = 0; j < i; j++)
            if (r[j].obstacle == 1 && r[j].x == r[i].x && r[j].y == r[i].y)
                printed = 1;
        if (printed == 1)
            continue;

        times = 1;
        for (j = i + 1; j < total; j++)
            if (r[j].obstacle == 1 && r[j].x == r[i].x && r[j].y == r[i].y)
                times++;

        if (times > 1) {
            printf("Obstacle at (%d,%d) found %d times\n", r[i].x, r[i].y, times);
            found = 1;
        }
    }
    if (found == 0)
        printf("No repeated obstacles\n");

    return 0;
}
