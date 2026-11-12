#include <stdio.h>
#include <string.h>

void readMarks(int *m1, int *m2, int *m3) {
    do {
        printf("Enter marks for 3 subjects (0-100): ");
        scanf("%d %d %d", m1, m2, m3);
        if (*m1 < 0 || *m1 > 100 || *m2 < 0 || *m2 > 100 || *m3 < 0 || *m3 > 100) {
            printf("Invalid marks entered! Please ensure all marks are between 0 and 100.\n");
        }
    } while (*m1 < 0 || *m1 > 100 || *m2 < 0 || *m2 > 100 || *m3 < 0 || *m3 > 100);
}

void calculateStats(int m1, int m2, int m3, int *total, double *average, int *highest, int *lowest) {
    *total = m1 + m2 + m3;
    *average = *total / 3.0;
    
    *highest = m1;
    if (m2 > *highest) *highest = m2;
    if (m3 > *highest) *highest = m3;

    *lowest = m1;
    if (m2 < *lowest) *lowest = m2;
    if (m3 < *lowest) *lowest = m3;
}

void swapMarks(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void addGraceMarks(int *mark, int grace) {
    if (*mark >= 35 && *mark < 40) {
        *mark += grace;
        if (*mark > 40) *mark = 40;
    }
}

void findGrade(double avg, char *grade, char remarks[]) {
    if (avg >= 85) {
        *grade = 'A';
        strcpy(remarks, "Excellent");
    } else if (avg >= 70) {
        *grade = 'B';
        strcpy(remarks, "Good");
    } else if (avg >= 50) {
        *grade = 'C';
        strcpy(remarks, "Satisfactory");
    } else {
        *grade = 'F';
        strcpy(remarks, "Needs Improvement");
    }
}

void incrementByValue(int x) {
    x += 10;
}

void incrementByReference(int *x) {
    *x += 10;
}

int main() {
    printf("=== Semester Results & Grace Marks System ===\n\n");
    
    for (int student = 1; student <= 5; student++) {
        printf("--- Student %d ---\n", student);
        int m1, m2, m3;
        readMarks(&m1, &m2, &m3);

        addGraceMarks(&m1, 5);
        addGraceMarks(&m2, 5);
        addGraceMarks(&m3, 5);

        if (m1 < m2) swapMarks(&m1, &m2);
        if (m2 < m3) swapMarks(&m2, &m3);
        if (m1 < m2) swapMarks(&m1, &m2);

        int total;
        double average;
        int highest, lowest;
        calculateStats(m1, m2, m3, &total, &average, &highest, &lowest);

        char grade;
        char remarks[30];
        findGrade(average, &grade, remarks);

        printf("Sorted Marks: %d, %d, %d\n", m1, m2, m3);
        printf("Total: %d | Average: %.2f | Grade: %c | Remark: %s\n\n", total, average, grade, remarks);
    }

    printf("\n=== Comparison Demo: Call by Value vs Reference ===\n");
    int val = 20;
    printf("Original value: %d\n", val);
    
    incrementByValue(val);
    printf("After incrementByValue(val): %d (unchanged because function received a copy)\n", val);
    
    incrementByReference(&val);
    printf("After incrementByReference(&val): %d (changed because function received the actual memory address)\n", val);

    return 0;
}