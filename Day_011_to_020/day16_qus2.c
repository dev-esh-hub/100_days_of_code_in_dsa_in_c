/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
*/

#include <stdio.h>

void reverse(int* nums, int start, int end){
    while(start < end){
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start += 1;
        end -= 1;
    }
}

void rotate(int* nums, int numsSize, int k) {
    if(numsSize == 0) return;

    k %= numsSize;

    // Reversing entire array:
    reverse(nums, 0, numsSize - 1);
    // Reversing first k elements:
    reverse(nums, 0, k - 1);
    // Reversing remaining elements:
    reverse(nums, k, numsSize - 1);
}

int main() {
    int n, k;

    printf("\nEnter number of elemets: ");
    scanf("%d", &n);

    int nums[n];

    printf("\nEnter elements: ");
    for(int i = 0; i < n; i += 1){
        scanf("%d", &nums[i]);
    }

    printf("\nEnter index from where to rotate: ");
    scanf("%d", &k);

    rotate(nums, n, k);

    printf("\nRotated array: ");
    for(int i = 0; i < n; i += 1){
        printf("%d ", nums[i]);
    }

    return 0;
}
