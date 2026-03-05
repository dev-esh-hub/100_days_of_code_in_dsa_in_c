/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    
    *returnSize = 0;

    if(numsSize < 3){
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Sorting array:
    qsort(nums, numsSize, sizeof(int), compare);

    int capacity = 1000;
    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    for(int i = 0; i < numsSize - 2; i += 1){

        // Skipping duplicates:
        if(i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = numsSize - 1;

        while(left < right){

            int sum = nums[i] + nums[left] + nums[right];

            if(sum == 0){

                result[*returnSize] = malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                *returnSize += 1;

                // Skipping duplicates:
                while(left < right && nums[left] == nums[left + 1]) left += 1;
                while(left < right && nums[right] == nums[right - 1]) right -= 1;

                left += 1;
                right -= 1;
            }
            else if(sum < 0){
                left += 1;
            }
            else{
                right -= 1;
            }
        }
    }

    return result;
}

int main(){
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));

    printf("Enter elements: ");
    for(int i = 0; i < n; i += 1){
        scanf("%d", &nums[i]);
    }

    int returnSize;
    int* returnColumnSizes;

    int** result = threeSum(nums, n, &returnSize, &returnColumnSizes);

    printf("\nTriplets:\n");
    for(int i = 0; i < returnSize; i += 1){
        printf("[");
        for(int j = 0; j < returnColumnSizes[i]; j += 1){
            printf("%d", result[i][j]);
            if(j < returnColumnSizes[i] - 1) printf(", ");
        }
        printf("]\n");
    }

    // Free the memory:
    for(int i = 0; i < returnSize; i += 1){
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);
    free(nums);

    return 0;
}