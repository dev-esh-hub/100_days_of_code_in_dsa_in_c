/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/

#include <stdio.h>

// Partition function (Lomuto)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j += 1) {
        if (arr[j] <= pivot) {
            i += 1;

            // swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // place pivot at correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Quickselect function
int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);

        if (pi == k) {
            return arr[pi];
        }
        else if (pi < k) {
            return quickSelect(arr, pi + 1, high, k);
        }
        else {
            return quickSelect(arr, low, pi - 1, k);
        }
    }
    return -1;
}

// Main function to find kth largest
int findKthLargest(int* nums, int numsSize, int k) {
    int targetIndex = numsSize - k; // kth largest → index
    return quickSelect(nums, 0, numsSize - 1, targetIndex);
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &nums[i]);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    int result = findKthLargest(nums, n, k);

    printf("Kth largest element: %d\n", result);

    return 0;
}