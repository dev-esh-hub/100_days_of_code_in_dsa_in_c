/*
Problem: Implement Insertion Sort - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64
*/

#include <stdio.h>

int main() {
    int n;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &arr[i]);
    }

    // Insertion Sort Logic
    for (int i = 1; i < n; i += 1) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }

        arr[j + 1] = key;
    }

    // Output sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i += 1) {
        printf("%d ", arr[i]);
    }

    return 0;
}