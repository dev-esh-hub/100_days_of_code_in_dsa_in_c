/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)
*/

#include <stdio.h>

// Function to check if we can split into <= k subarrays
// such that maximum subarray sum does not exceed maxSum
int canSplit(int nums[], int n, int k, int maxSum) {
    int subarrays = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i += 1) {
        // If adding current element stays within maxSum
        if (currentSum + nums[i] <= maxSum) {
            currentSum += nums[i];
        } else {
            // Create new subarray
            subarrays += 1;
            currentSum = nums[i];

            // If subarrays exceed k → not possible
            if (subarrays > k) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to find minimized largest sum
int splitArray(int nums[], int n, int k) {
    int low = nums[0];
    int high = 0;

    // Find max element and total sum
    for (int i = 0; i < n; i += 1) {
        if (nums[i] > low) {
            low = nums[i];
        }
        high += nums[i];
    }

    int answer = high;

    // Binary Search
    while (low <= high) {
        int mid = (low + high) / 2;

        if (canSplit(nums, n, k, mid)) {
            answer = mid;
            high = mid - 1;   // try smaller value
        } else {
            low = mid + 1;    // increase value
        }
    }

    return answer;
}

int main() {
    int n, k;

    printf("Enter number of elements and k: ");
    scanf("%d %d", &n, &k);

    int nums[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &nums[i]);
    }

    int result = splitArray(nums, n, k);

    printf("Minimum largest subarray sum: %d\n", result);

    return 0;
}