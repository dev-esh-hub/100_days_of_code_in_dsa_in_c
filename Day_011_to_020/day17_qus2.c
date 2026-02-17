/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {

    int currsum = 0;
    int maxsum = nums[0];

    for(int i=0; i<numsSize; i+=1){
        currsum += nums[i];
        if(currsum > maxsum){
            maxsum = currsum;
        }
        if (currsum < 0){
            currsum = 0;
        }
    }

    return maxsum;
}

int main() {
    int n;

    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("\nEnter elements: ");
    for(int i = 0; i < n; i += 1){
        scanf("%d", &nums[i]);
    }

    int result = maxSubArray(nums, n);

    printf("\nMaximum subarray sum: %d", result);

    return 0;
}
