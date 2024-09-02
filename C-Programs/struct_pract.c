#include <stdio.h>
#include <string.h>  // Needed for string functions like fgets

typedef struct companies {
    char branch[50];
    int year;
    char dept[50];
    char name[50];
} company;

int main() {
    company em1, em2, em3;
    company *ptr;
    int i;

    // Array of pointers to handle multiple employees
    company *employees[3] = {&em1, &em2, &em3};

    for (i = 0; i < 3; i++) {
        ptr = employees[i];

        printf("Enter the name of %d employee: ", i + 1);
        fgets(ptr->name, sizeof(ptr->name), stdin);
        ptr->name[strcspn(ptr->name, "\n")] = '\0';  // Remove the newline character

        printf("Enter the year of %d employee: ", i + 1);
        scanf("%d", &ptr->year);
        getchar();  // To consume the leftover newline character

        printf("Enter the branch of %d employee: ", i + 1);
        fgets(ptr->branch, sizeof(ptr->branch), stdin);
        ptr->branch[strcspn(ptr->branch, "\n")] = '\0';  // Remove the newline character

        printf("Enter the department of %d employee: ", i + 1);
        fgets(ptr->dept, sizeof(ptr->dept), stdin);
        ptr->dept[strcspn(ptr->dept, "\n")] = '\0';  // Remove the newline character
        getchar();  // To consume the newline character after dept
    }

    for (i = 0; i < 3; i++) {
        ptr = employees[i];

        printf("The name of %d employee: ", i + 1);
        puts(ptr->name);

        printf("The year of %d employee: %d\n", i + 1, ptr->year);

        printf("The branch of %d employee: ", i + 1);
        puts(ptr->branch);

        printf("The department of %d employee: ", i + 1);
		puts(ptr->dept);
        printf("\n");
    }

    return 0;
}

