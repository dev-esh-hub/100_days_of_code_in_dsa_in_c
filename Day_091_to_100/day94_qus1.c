/*
Problem: Sort array of non-negative integers using counting sort.
Find max, build freq array, compute prefix sums, build output.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to find maximum element
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i += 1) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Counting Sort
void countingSort(int arr[], int n) {
    int max = findMax(arr, n);

    // Frequency array
    int count[max + 1];

    // Initialize count array
    for (int i = 0; i <= max; i += 1) {
        count[i] = 0;
    }

    // Store frequencies
    for (int i = 0; i < n; i += 1) {
        count[arr[i]] += 1;
    }

    // Prefix sum (cumulative)
    for (int i = 1; i <= max; i += 1) {
        count[i] += count[i - 1];
    }

    // Output array
    int output[n];

    // Build output array (reverse traversal for stability)
    for (int i = n - 1; i >= 0; i -= 1) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]] -= 1;
    }

    // Copy back to original array
    for (int i = 0; i < n; i += 1) {
        arr[i] = output[i];
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter non-negative elements:\n");
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i += 1) {
        printf("%d ", arr[i]);
    }

    return 0;
}