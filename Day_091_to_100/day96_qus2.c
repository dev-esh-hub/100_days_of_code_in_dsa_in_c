/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1
*/

#include <stdio.h>
#include <stdlib.h>

// Merge step + count reverse pairs
int mergeAndCount(int arr[], int left, int mid, int right) {
    int count = 0;

    int j = mid + 1;

    // Count reverse pairs
    for (int i = left; i <= mid; i += 1) {
        while (j <= right && (long long)arr[i] > 2LL * arr[j]) {
            j += 1;
        }
        count += (j - (mid + 1));
    }

    // Merge two sorted halves
    int size = right - left + 1;
    int temp[size];

    int i = left;
    j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back to original array
    for (int x = 0; x < size; x += 1) {
        arr[left + x] = temp[x];
    }

    return count;
}

// Merge Sort + count
int mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return 0;
    }

    int mid = (left + right) / 2;

    int count = 0;

    count += mergeSort(arr, left, mid);
    count += mergeSort(arr, mid + 1, right);
    count += mergeAndCount(arr, left, mid, right);

    return count;
}

// Main function
int reversePairs(int* nums, int numsSize) {
    return mergeSort(nums, 0, numsSize - 1);
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

    int result = reversePairs(nums, n);

    printf("Number of reverse pairs: %d\n", result);

    return 0;
}