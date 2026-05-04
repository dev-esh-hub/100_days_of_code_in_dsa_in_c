/*
Problem: Implement merge sort (divide, sort halves, merge).
Print sorted array.
*/

#include <stdio.h>

// Function to merge two sorted halves
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    // Copy data to temp arrays
    for (i = 0; i < n1; i += 1) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j += 1) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    // Merge the temp arrays back
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i += 1;
        } else {
            arr[k] = R[j];
            j += 1;
        }
        k += 1;
    }

    // Copy remaining elements
    while (i < n1) {
        arr[k] = L[i];
        i += 1;
        k += 1;
    }

    while (j < n2) {
        arr[k] = R[j];
        j += 1;
        k += 1;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);       // left half
        mergeSort(arr, mid + 1, right);  // right half

        merge(arr, left, mid, right);    // merge both
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

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i += 1) {
        printf("%d ", arr[i]);
    }

    return 0;
}