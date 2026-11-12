#include <stdio.h>

int findMax(int *p, int n) {
    int max = *p;
    for (int i = 1; i < n; i++) {
        if (*(p + i) > max) max = *(p + i);
    }
    return max;
}

int findMin(int *p, int n) {
    int min = *p;
    for (int i = 1; i < n; i++) {
        if (*(p + i) < min) min = *(p + i);
    }
    return min;
}

double findAverage(int *p, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(p + i);
    }
    return (double)sum / n;
}

int countAbove(int *p, int n, double avg) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (*(p + i) > avg) count++;
    }
    return count;
}

void reverseArray(int *p, int n) {
    int *start = p;
    int *end = p + n - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int searchMark(int *p, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (*(p + i) == key) return i;
    }
    return -1;
}

int main() {
    int marks[10];
    printf("=== Student Marks Analysis System ===\n");
    for (int i = 0; i < 10; i++) {
        do {
            printf("Enter mark for student %d (0-100): ", i + 1);
            scanf("%d", &marks[i]);
            if (marks[i] < 0 || marks[i] > 100) {
                printf("Invalid mark! Range is 0 to 100.\n");
            }
        } while (marks[i] < 0 || marks[i] > 100);
    }

    int maxMark = findMax(marks, 10);
    int minMark = findMin(marks, 10);
    double avgMark = findAverage(marks, 10);
    int aboveAvgCount = countAbove(marks, 10, avgMark);

    int passCount = 0;
    for (int i = 0; i < 10; i++) {
        if (marks[i] >= 40) passCount++;
    }

    printf("\n--- Class Statistics ---\n");
    printf("Highest Mark: %d\n", maxMark);
    printf("Lowest Mark: %d\n", minMark);
    printf("Average Mark: %.2f\n", avgMark);
    printf("Students scoring above average: %d\n", aboveAvgCount);
    printf("Total Pass Count (>= 40): %d\n", passCount);

    printf("\nMarks before reversing: ");
    for (int i = 0; i < 10; i++) printf("%d ", marks[i]);
    printf("\n");

    reverseArray(marks, 10);

    printf("Marks after reversing:  ");
    for (int i = 0; i < 10; i++) printf("%d ", marks[i]);
    printf("\n");

    int key;
    printf("\nEnter a mark to search in the class: ");
    scanf("%d", &key);
    int pos = searchMark(marks, 10, key);
    if (pos != -1) {
        printf("Mark %d found at position index %d (reversed array).\n", key, pos);
    } else {
        printf("Mark %d not found in the class records.\n", key);
    }

    return 0;
}