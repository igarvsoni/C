#include <stdio.h>

// Function to rotate the array based on direction and positions
void rotateArray(int arr[], int n, int positions, char direction) {
    positions = positions % n;  // Normalize positions to handle larger values
    int temp[positions];

    if (direction == 'L' || direction == 'l') {
        // Left rotation
        for (int i = 0; i < positions; i++) {
            temp[i] = arr[i];
        }
        for (int i = 0; i < n - positions; i++) {
            arr[i] = arr[i + positions];
        }
        for (int i = 0; i < positions; i++) {
            arr[n - positions + i] = temp[i];
        }
    } else if (direction == 'R' || direction == 'r') {
        // Right rotation
        for (int i = 0; i < positions; i++) {
            temp[i] = arr[n - positions + i];
        }
        for (int i = n - 1; i >= positions; i--) {
            arr[i] = arr[i - positions];
        }
        for (int i = 0; i < positions; i++) {
            arr[i] = temp[i];
        }
    } else {
        printf("Invalid direction! Use 'L' for left or 'R' for right.\n");
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, positions;
    char direction;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of positions to rotate: ");
    scanf("%d", &positions);

    printf("Enter the direction (L for left, R for right): ");
    scanf(" %c", &direction);

    // Before Rotation
    printf("Array before rotation:\n");
    printArray(arr, n);

    rotateArray(arr, n, positions, direction);

    // After Rotation
    printf("Array after rotation:\n");
    printArray(arr, n);

    return 0;
}
