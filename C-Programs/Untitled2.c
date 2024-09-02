#include <stdio.h>
#include <ctype.h>

void createPoly(int arr[], int size) {
    char ch = 'Y';
    int p, c;

    while (toupper(ch) == 'Y') {
        printf("Enter exponent: ");
        scanf("%d", &p);
        printf("Enter co-efficient: ");
        scanf("%d", &c);
        arr[p] = c;
        printf("Continue (Y/N)?\n");
        while ((getchar()) != '\n'){};  // Clear the input buffer
        scanf("%c", &ch);  // Read the next character
    }
}

int main() {
    int size = 10,i; // Example size, you can change as needed
    int arr[size];
    
    // Initialize array to 0
    for (i = 0; i < size; i++) {
        arr[i] = 0;
    }
    
    createPoly(arr, size);
    
    // Display polynomial for verification
    for (i = size-1; i >=0; i--) {
        if (arr[i] != 0)
            printf("%dx^%d+", arr[i], i);
    }
    
    printf("\b ");  // Remove the last + and add a newline

    return 0;
}
