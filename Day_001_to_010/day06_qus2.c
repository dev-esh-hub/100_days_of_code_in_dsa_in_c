/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
*/

#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int non_zero = 0;

    // Move non-zero elements forward
    for (int i = 0; i < numsSize; i += 1) {
        if (nums[i] != 0) {
            nums[non_zero] = nums[i];
            non_zero += 1;
        }
    }

    // Fill remaining positions with zero
    while (non_zero < numsSize) {
        nums[non_zero] = 0;
        non_zero += 1;
    }
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &nums[i]);
    }

    moveZeroes(nums, n);

    printf("Result array:\n");
    for (int i = 0; i < n; i += 1) {
        printf("%d ", nums[i]);
    }

    return 0;
}
