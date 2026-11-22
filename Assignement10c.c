
#include <stdio.h>

#define FILE_NAME "nav_history.txt"
#define MAX_OBSTACLES 500

typedef struct {
    int   x, y;      
    float distance; 
    int   obstacle;
    char  direction;
} Record;

typedef struct {
    int x, y;        
    int count;     
} ObstacleCount;

void addRecord(void)
{
    Record r;
    FILE *fp;

    printf("Enter x coordinate: ");
    scanf("%d", &r.x);
    printf("Enter y coordinate: ");
    scanf("%d", &r.y);

    do {
        printf("Enter sensor distance (cm, >= 0): ");
        scanf("%f", &r.distance);
    } while (r.distance < 0);

    do {
        printf("Obstacle detected? (1 = yes, 0 = no): ");
        scanf("%d", &r.obstacle);
    } while (r.obstacle != 0 && r.obstacle != 1);

    do {
        printf("Movement direction (F/B/L/R): ");
        scanf(" %c", &r.direction);
    } while (r.direction != 'F' && r.direction != 'B' &&
             r.direction != 'L' && r.direction != 'R');

    fp = fopen(FILE_NAME, "a");
    if (fp == NULL) {
        printf("Error: could not open file for writing.\n");
        return;
    }
    fprintf(fp, "%d %d %.2f %d %c\n",
            r.x, r.y, r.distance, r.obstacle, r.direction);
    fclose(fp);

    printf("Record saved successfully.\n");
}

void displayHistory(void)
{
    Record r;
    int n = 0;
    FILE *fp = fopen(FILE_NAME, "r");

    if (fp == NULL) {
        printf("No navigation history found.\n");
        return;
    }

    printf("\n%-5s %-5s %-5s %-10s %-9s %-9s\n",
           "No.", "X", "Y", "Distance", "Obstacle", "Direction");
    printf("--------------------------------------------------\n");

    while (fscanf(fp, "%d %d %f %d %c",
                  &r.x, &r.y, &r.distance, &r.obstacle, &r.direction) == 5) {
        n++;
        printf("%-5d %-5d %-5d %-10.2f %-9s %-9c\n",
               n, r.x, r.y, r.distance,
               r.obstacle ? "Yes" : "No", r.direction);
    }

    if (n == 0)
        printf("File is empty.\n");

    fclose(fp);
}


void findRepeatedObstacles(void)
{
    Record r;
    ObstacleCount list[MAX_OBSTACLES];
    int total = 0, i, found, repeated = 0;
    FILE *fp = fopen(FILE_NAME, "r");

    if (fp == NULL) {
        printf("No navigation history found.\n");
        return;
    }

    while (fscanf(fp, "%d %d %f %d %c",
                  &r.x, &r.y, &r.distance, &r.obstacle, &r.direction) == 5) {
        if (r.obstacle == 1) {
            found = 0;
            for (i = 0; i < total; i++) {
                if (list[i].x == r.x && list[i].y == r.y) {
                    list[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found && total < MAX_OBSTACLES) {
                list[total].x = r.x;
                list[total].y = r.y;
                list[total].count = 1;
                total++;
            }
        }
    }
    fclose(fp);

    printf("\nRepeated obstacles:\n");
    for (i = 0; i < total; i++) {
        if (list[i].count > 1) {
            printf("Obstacle at (%d, %d) seen %d times\n",
                   list[i].x, list[i].y, list[i].count);
            repeated++;
        }
    }
    if (repeated == 0)
        printf("No repeated obstacles found.\n");
}

int main(void)
{
    int choice;

    do {
        printf("\Robot Navigation System\n");
        printf("1. Record new navigation data\n");
        printf("2. Display navigation history\n");
        printf("3. Find repeated obstacles\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addRecord();             break;
            case 2: displayHistory();        break;
            case 3: findRepeatedObstacles(); break;
            case 4: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
