#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("=== Weather Station Temperature Recorder ===\n");
    printf("Enter number of days to record (1 to 10): ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Invalid number of days! Please run again with a value between 1 and 10.\n");
        return 1;
    }

    double *temp = (double *)malloc(n * sizeof(double));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        do {
            printf("Enter temperature for Day %d (-10 to 55): ", i + 1);
            scanf("%lf", &temp[i]);
            if (temp[i] < -10 || temp[i] > 55) {
                printf("Error: Temperature must be between -10 and 55. Try again.\n");
            }
        } while (temp[i] < -10 || temp[i] > 55);
    }

    printf("\n--- Recorded Temperatures & Addresses ---\n");
    double *ptr = temp;
    for (int i = 0; i < n; i++) {
        printf("Day %d: %.1f C at address %p\n", i + 1, *ptr, (void*)ptr);
        ptr++;
    }

    ptr = temp;
    double hottest = *ptr;
    double coldest = *ptr;
    int hotCount = 0;

    for (int i = 0; i < n; i++) {
        if (*ptr > hottest) hottest = *ptr;
        if (*ptr < coldest) coldest = *ptr;
        if (*ptr > 40.0) hotCount++;
        ptr++;
    }

    printf("\n--- Summary Report ---\n");
    printf("Hottest temperature: %.1f C\n", hottest);
    printf("Coldest temperature: %.1f C\n", coldest);
    printf("Number of days hotter than 40 C: %d\n", hotCount);

    free(temp);
    temp = NULL;
    printf("\n[Notice] Memory has been successfully released.\n");

    return 0;
}