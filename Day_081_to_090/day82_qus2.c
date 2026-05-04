/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/

#include <stdio.h>

// Function to find insert position
int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int ans = numsSize;  // default position (end)

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] >= target) {
            ans = mid;
            right = mid - 1;  // move left
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    // Input sorted array
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &nums[i]);
    }

    int target;

    // Input target
    printf("Enter target value: ");
    scanf("%d", &target);

    // Function call
    int index = searchInsert(nums, n, target);

    // Output
    printf("Insert/Search Position Index: %d\n", index);

    return 0;
}