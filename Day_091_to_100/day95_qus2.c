/*
Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.

 

Example 1:

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find maximum gap
int maximumGap(int* nums, int numsSize) {

    if (numsSize < 2) {
        return 0;
    }

    int minVal = nums[0];
    int maxVal = nums[0];

    // Step 1: Find min and max
    for (int i = 1; i < numsSize; i += 1) {
        if (nums[i] < minVal) {
            minVal = nums[i];
        }
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }

    // If all elements same
    if (minVal == maxVal) {
        return 0;
    }

    int n = numsSize;

    // Step 2: Calculate bucket size and count
    int bucketSize = (maxVal - minVal) / (n - 1);
    if (bucketSize == 0) {
        bucketSize = 1;
    }

    int bucketCount = (maxVal - minVal) / bucketSize + 1;

    // Allocate buckets
    int* bucketMin = (int*)malloc(bucketCount * sizeof(int));
    int* bucketMax = (int*)malloc(bucketCount * sizeof(int));

    // Initialize buckets
    for (int i = 0; i < bucketCount; i += 1) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }

    // Step 3: Fill buckets
    for (int i = 0; i < n; i += 1) {
        int idx = (nums[i] - minVal) / bucketSize;

        if (nums[i] < bucketMin[idx]) {
            bucketMin[idx] = nums[i];
        }
        if (nums[i] > bucketMax[idx]) {
            bucketMax[idx] = nums[i];
        }
    }

    // Step 4: Find maximum gap
    int maxGap = 0;
    int prevMax = minVal;

    for (int i = 0; i < bucketCount; i += 1) {
        if (bucketMin[i] == INT_MAX) {
            continue; // empty bucket
        }

        int gap = bucketMin[i] - prevMax;
        if (gap > maxGap) {
            maxGap = gap;
        }

        prevMax = bucketMax[i];
    }

    // Free memory
    free(bucketMin);
    free(bucketMax);

    return maxGap;
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

    int result = maximumGap(nums, n);

    printf("Maximum gap: %d\n", result);

    return 0;
}