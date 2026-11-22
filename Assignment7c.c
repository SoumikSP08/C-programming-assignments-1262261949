#include <stdio.h>

struct Robot {
    int id;
    char type[30];
    float payload_capacity;
    float actual_load;
    float operating_time;
    float utilization;
};

int main()
{
    struct Robot r[100];
    int n, i, count = 0;

    printf("Enter the number of robotic arms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nRobotic arm %d\n", i + 1);
        printf("Enter robot ID: ");
        scanf("%d", &r[i].id);
        printf("Enter robot type: ");
        scanf("%s", r[i].type);
        printf("Enter payload capacity (kg): ");
        scanf("%f", &r[i].payload_capacity);
        printf("Enter actual load (kg): ");
        scanf("%f", &r[i].actual_load);
        printf("Enter operating time (hrs): ");
        scanf("%f", &r[i].operating_time);

        r[i].utilization = (r[i].actual_load / r[i].payload_capacity) * 100;
    }

    printf("\n%-8s %-15s %-12s %-12s %-12s %-14s\n",
           "ID", "Type", "Payload", "Load", "Time", "Utilization %");

    for (i = 0; i < n; i++) {
        printf("%-8d %-15s %-12.2f %-12.2f %-12.2f %-14.2f\n",
               r[i].id, r[i].type, r[i].payload_capacity,
               r[i].actual_load, r[i].operating_time, r[i].utilization);
    }

    printf("\nRobots operating beyond rated payload:\n");

    for (i = 0; i < n; i++) {
        if (r[i].actual_load > r[i].payload_capacity) {
            printf("ID: %d, Type: %s, Utilization: %.2f%%\n",
                   r[i].id, r[i].type, r[i].utilization);
            count++;
        }
    }

    if (count == 0)
        printf("None\n");

    return 0;
}
