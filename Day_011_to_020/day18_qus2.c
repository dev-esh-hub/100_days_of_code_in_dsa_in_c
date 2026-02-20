/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
*/

#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    // Allocating memory for result array: 
    int* answer = (int*)malloc(numsSize * sizeof(int));
    answer[0] = 1;

    // For prefix elements:
    for(int i = 1; i < numsSize; i += 1){
        answer[i] = answer[i-1] * nums[i-1];
    }

    // For suffix elements:
    int suffix = 1;
    for(int i = numsSize - 2; i >= 0; i -= 1){
        suffix *= nums[i+1];
        answer[i] *= suffix;
    }

    return answer;
}

int main() {
    int n;
    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("\nEnter %d elements:\n", n);
    for(int i = 0; i < n; i += 1){
        scanf("%d", &nums[i]);
    }

    int returnSize;

    int* result = productExceptSelf(nums, n, &returnSize);

    printf("\nResultant array:\n");
    for(int i = 0; i < returnSize; i += 1){
        printf("%d ", result[i]);
    }

    // Free allocated memory
    free(result);

    return 0;
}