#include <stdio.h>

// Global variable to store the last sorting method
char lastSort[20] = "Unsorted";  // Initially, no sorting is applied

// Function to copy the array
void copyArray(int source[], int destination[], int size) {
    for(int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

void bubbleSort(int arr[], int size) {
    int i, j, temp;
    for(i = 0; i < size - 1; i++) {
        for(j = 0; j < size - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    sprintf(lastSort, "Bubble Sort");  // After sorting, store "Bubble Sort" in lastSort
}
void selectionSort(int arr[],int size){
    int i,j,p,temp;
    for(i=0;i<size-1;i++){
        p = i;
        for(j=i+1;j<size;j++){
            if(arr[j]<arr[p])
                p = j;
        }
        temp = arr[i];
        arr[i] = arr[p];
        arr[p] = temp; 
    }
    sprintf(lastSort, "Selection Sort");
}
void insertionSort(int arr[],int size){
    int i,j,temp,key;
    for(i=1;i<size;i++){
        key = arr[i];
        for(j = i - 1;j>=0 && key<arr[j];j--)
            arr[j+1] = arr[j];

        arr[j+1] = key;
    }
    sprintf(lastSort, "Insertion Sort");
}
void displayArray(int arr[], int size) {
    int i;
    printf("The array (sorted by %s): ", lastSort);
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int i, ch, arr[10], originalArr[10], size;
    
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    
    printf("Enter the elements: ");
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        originalArr[i] = arr[i];  // Store the original array
    }

    printf("-----MAIN MENU-----\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Restore Original (Unsorted) Array\n");
    printf("5. Display the array\n");
    printf("6. Exit\n");
    printf("-------------------\n");

    while(1) {
        printf("Enter the operation: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                bubbleSort(arr, size);  // Sort the array using bubble sort
                break;
            case 2:
                insertionSort(arr,size);
                break;
            case 3:
                selectionSort(arr,size);
                break;
            case 4:
                copyArray(originalArr, arr, size);  // Restore the original (unsorted) array
                sprintf(lastSort, "Unsorted");
                break;
            case 5:
                displayArray(arr, size);  // Display the current array
                break;
            case 6:
                printf("Exiting..\n");
                return 0;
            default:
                printf("Invalid Operation. Please try again\n");
        }
    }
}