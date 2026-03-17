/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/

#include <stdio.h>
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    int *result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    int *deque = (int*)malloc(sizeof(int) * numsSize);

    int front = 0, rear = -1;
    int index = 0;

    for(int i = 0; i < numsSize; i++)
    {
        /* Remove indices which are out of this window */
        if(front <= rear && deque[front] <= i - k)
            front++;

        /* Remove smaller elements from rear */
        while(front <= rear && nums[deque[rear]] < nums[i])
            rear--;

        /* Insert current index */
        deque[++rear] = i;

        /* Store maximum for valid window */
        if(i >= k - 1)
            result[index++] = nums[deque[front]];
    }

    *returnSize = numsSize - k + 1;

    free(deque);
    return result;
}

int main()
{
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *nums = (int*)malloc(sizeof(int) * n);

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("Enter window size (k): ");
    scanf("%d", &k);

    int returnSize;

    int *result = maxSlidingWindow(nums, n, k, &returnSize);

    printf("\nMaximum elements in each sliding window:\n");

    for(int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }

    printf("\n");

    free(nums);
    free(result);

    return 0;
}