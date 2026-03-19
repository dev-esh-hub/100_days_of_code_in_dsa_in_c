// Implement Heap Sort using a Max Heap to sort an array in ascending order. First build a max heap, then repeatedly extract the maximum element and place it at the end of the array.

#include <stdio.h>

// Function to swap two elements:
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function (Max Heap):
void heapify(int arr[], int n, int i) {
    int largest = i;        // assume root is largest
    int left = 2*i + 1;
    int right = 2*i + 2;

    // Check left child:
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check right child:
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root:
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort function:
void heapSort(int arr[], int n) {

    // Step 1: Build Max Heap:
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements one by one:
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);   // move max to end
        heapify(arr, i, 0);       // heapify reduced heap
    }
}

void printArray(int arr[], int n) {
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n);

    printArray(arr, n);

    return 0;
}