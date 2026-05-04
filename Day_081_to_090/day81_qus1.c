/*
Problem: Implement Bubble Sort - Implement the algorithm.

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

    // Taking size input
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Taking array input
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i += 1) {
        scanf("%d", &arr[i]);
    }

    // Bubble Sort Logic
    for(int i = 0; i < n - 1; i += 1) {
        for(int j = 0; j < n - i - 1; j += 1) {
            if(arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Printing sorted array
    printf("Sorted array:\n");
    for(int i = 0; i < n; i += 1) {
        printf("%d ", arr[i]);
    }

    return 0;
}