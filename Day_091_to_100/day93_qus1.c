/*
Problem: Sort an array using insertion sort.
Stable sort. Good for nearly sorted arrays.
*/

#include <stdio.h>

// Insertion Sort function
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i += 1) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key to right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }

        // Place key at correct position
        arr[j + 1] = key;
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i += 1) {
        printf("%d ", arr[i]);
    }

    return 0;
}