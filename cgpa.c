#include <stdio.h>

// Function to convert grade to grade point
int getGradePoint(char grade) {
    switch (grade) {
        case 'O': return 10;
        case 'A': return 9;
        case 'B': return 8;
        case 'C': return 7;
        case 'D': return 6;
        case 'E': return 5;
        case 'U': return 0;  // Fail grade
        default: return -1;  // Invalid grade
    }
}
// Function to calculate GPA for a single semester
float calculateGPA(int grades[], int credits[], int n) {
    int totalCredits = 0,Sum = 0;
    for (int i = 0; i < n; i++) {
        Sum += grades[i] * credits[i];
        totalCredits += credits[i];
    }
    return Sum / totalCredits;
}
// Function to calculate CGPA across multiple semesters
float calculateCGPA(float gpas[], int semesters) {
    float totalGPA = 0.0;
    for (int i = 0; i < semesters; i++) {
        totalGPA += gpas[i];
    }
    return totalGPA / semesters;
}
// Function to display the result
void displayResult(float gpa, float cgpa) {
    printf("\nYour GPA is: %.2f\n", gpa);
    printf("Your CGPA is: %.2f\n", cgpa);
}

// Main function
int main() {
    int n, semesters, i, j;

    // GPA Calculation for one semester
    printf("Enter the number of subjects for the semester: ");
    scanf("%d", &n);

    int credits[n];
    char grades[n];
    int gradePoints[n];

    for (i = 0; i < n; i++) {
        printf("Enter grade (O/A/B/C/D/E/U) for subject %d: ", i + 1);
        scanf(" %c", &grades[i]);
        printf("Enter credit for subject %d: ", i + 1);
        scanf("%d", &credits[i]);

        gradePoints[i] = getGradePoint(grades[i]);
        if (gradePoints[i] == -1) {
            printf("Invalid grade entered. Exiting...\n");
            return 1;
        }
    }

    float gpa = calculateGPA(gradePoints, credits, n);

    // CGPA Calculation
    printf("\nEnter the number of semesters: ");
    scanf("%d", &semesters);

    float gpas[semesters];
    for (j = 0; j < semesters; j++) {
        printf("Enter GPA for semester %d: ", j + 1);
        scanf("%f", &gpas[j]);
    }

    float cgpa = calculateCGPA(gpas, semesters);

    displayResult(gpa, cgpa);

    return 0;
}
