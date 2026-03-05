/*
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
 

Constraints:

n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
*/

#include <stdio.h>

// Function remains exactly the same
int maxSubarraySumCircular(int* nums, int numsSize) {
    int n = numsSize;
    int totalSum = 0;

    int maxSum = nums[0];
    int currMax = 0;

    int minSum = nums[0];
    int currMin = 0;

    for(int i = 0; i < n; i += 1){

        // For max subarray:
        currMax += nums[i];

        if(currMax > maxSum){
            maxSum = currMax;
        }

        if(currMax < 0){
            currMax = 0;
        }

        // For min subarray:
        currMin += nums[i];

        if(currMin < minSum){
            minSum = currMin;
        }

        if(currMin > 0){
            currMin = 0;
        }

        totalSum += nums[i];
    }

    // If all numbers are negative:
    if (maxSum < 0) {
        return maxSum;
    }

    // Returning maximum of normal and circular:
    if (totalSum - minSum > maxSum) {
        return totalSum - minSum;
    }
    return maxSum;
}

int main() {
    int n;

    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("\nEnter %d elements:\n", n);
    for(int i = 0; i < n; i += 1){
        scanf("%d", &arr[i]);
    }

    int result = maxSubarraySumCircular(arr, n);

    printf("\nMaximum Circular Subarray Sum: %d\n", result);

    return 0;
}