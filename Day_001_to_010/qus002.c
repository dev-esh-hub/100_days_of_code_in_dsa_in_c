/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

* Note: The returned array must be malloced, assume caller calls free().
*/


#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    *returnSize = 2;
    int *resultant_arr = (int*)malloc((*returnSize) * sizeof(int));

    for(int i = 0; i<numsSize; i+=1){
        for(int j=i+1; j<numsSize; j+=1){
            if(nums[i]+nums[j] == target){
                resultant_arr[0] = i;
                resultant_arr[1] = j;
                return resultant_arr;
            }
        }
    }
    free(resultant_arr);
    return NULL;
}

int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter elements:\n");
    for(int i = 0; i < n; i+=1){
        scanf("%d", &nums[i]);
    }

    int target;
    printf("Enter target sum: ");
    scanf("%d", &target);

    int returnSize;
    int *result = twoSum(nums, n, target, &returnSize);

    if(result != NULL){
        printf("Indices are: ");
        for(int i = 0; i < returnSize; i+=1){
            printf("%d ", result[i]);
        }
        free(result);
    } else {
        printf("No valid pair found.");
    }

    return 0;
}