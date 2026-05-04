/*
Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].

 

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Example 2:

Input: nums = [-1]
Output: [0]
Example 3:

Input: nums = [-1,-1]
Output: [0,0]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

#include <stdio.h>
#include <stdlib.h>

// Pair structure (value + original index)
struct Pair {
    int val;
    int index;
};

// Merge step
void merge(struct Pair arr[], int left, int mid, int right, int count[]) {
    int size = right - left + 1;
    struct Pair temp[size];

    int i = left;
    int j = mid + 1;
    int k = 0;

    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i].val <= arr[j].val) {
            count[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        } else {
            rightCount += 1;
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        count[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back
    for (int x = 0; x < size; x += 1) {
        arr[left + x] = temp[x];
    }
}

// Merge Sort
void mergeSort(struct Pair arr[], int left, int right, int count[]) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid + 1, right, count);
    merge(arr, left, mid, right, count);
}

// Function required by problem
int* countSmaller(int* nums, int numsSize, int* returnSize) {

    *returnSize = numsSize;

    int* result = (int*)malloc(numsSize * sizeof(int));

    struct Pair arr[numsSize];

    // Initialize
    for (int i = 0; i < numsSize; i += 1) {
        arr[i].val = nums[i];
        arr[i].index = i;
        result[i] = 0;
    }

    mergeSort(arr, 0, numsSize - 1, result);

    return result;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &nums[i]);
    }

    int returnSize;
    int* result = countSmaller(nums, n, &returnSize);

    printf("Count of smaller elements on right:\n");
    for (int i = 0; i < returnSize; i += 1) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free memory
    free(result);

    return 0;
}