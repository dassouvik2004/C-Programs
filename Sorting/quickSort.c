#include <stdio.h>

// Function to perform partition
int partition(int arr[], int left, int right) {
    int pivot = arr[left]; // Choose the leftmost element as pivot
    int i = left;
    int j = right;

    while (i < j) {
        // Move right pointer towards the left while arr[j] > pivot
        while (arr[j] > pivot && i < j) {
            j--;
        }
        
        // Move left pointer towards the right while arr[i] <= pivot
        while (arr[i] <= pivot && i < j) {
            i++;
        }
        
        // Swap arr[i] and arr[j] to maintain the pivot's position
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // Swap the pivot with arr[i] to place it in the correct position
    arr[left] = arr[i];
    arr[i] = pivot;

    return i;  // Return the index of the pivot after partitioning
}

// Function to perform quicksort recursively
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int loc = partition(arr, left, right); // Find partition point
        quickSort(arr, left, loc - 1);  // Recursively sort left subarray
        quickSort(arr, loc + 1, right); // Recursively sort right subarray
    }
}

int main() {
    int arr[100], n, i;
    
    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Input the elements of the array
    printf("Enter the elements of the array: \n");
    for (i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    // Display the array before sorting
    printf("Before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Perform quicksort
    quickSort(arr, 0, n - 1);
    
    // Display the array after sorting
    printf("After sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
