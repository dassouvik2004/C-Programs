#include <stdio.h>

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        // Base case: Only one disk
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Step 1: Move n-1 disks from source to auxiliary, using destination as auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination);

    // Step 2: Move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Step 3: Move the n-1 disks from auxiliary to destination, using source as auxiliary
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n; // Number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}
