#include <stdio.h>
#include <string.h>

typedef struct student{
    int roll;
    char name[30];
    int total;
} st;

int main() {
    st s[20];
    int i, n;
    
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter the roll: ");
        scanf("%d", &s[i].roll);
        
        printf("Enter the name: ");
        getchar();  // To consume the leftover newline character from previous input
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = 0;  // Remove trailing newline
        
        printf("Enter the total marks: ");
        scanf("%d", &s[i].total);
    }
    
    int max = s[0].total;

    // Find the highest marks
    for (i = 1; i < n; i++) {
        if (s[i].total > max) {
            max = s[i].total;
        }
    }

    // Print all students with the highest marks
    printf("The student(s) with the highest marks of %d:\n", max);
    for (i = 0; i < n; i++) {
        if (s[i].total == max) {
            printf("%s\n", s[i].name);
        }
    }

    return 0;
}
