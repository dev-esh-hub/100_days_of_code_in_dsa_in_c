/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    int freq[1001] = {0};

    // Count frequency of nums1
    for(int i = 0; i < nums1Size; i += 1){
        freq[nums1[i]] += 1;
    }

    // Allocate maximum possible size
    int* result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    *returnSize = 0;

    // Find intersection
    for(int i = 0; i < nums2Size; i += 1){
        if(freq[nums2[i]] > 0){
            result[*returnSize] = nums2[i];
            *returnSize += 1;
            freq[nums2[i]] -= 1;
        }
    }

    return result;
}

int main() {
    int n1, n2;

    printf("\nEnter size of nums1: ");
    scanf("%d", &n1);

    int nums1[n1];
    printf("\nEnter elements of nums1:\n");
    for(int i = 0; i < n1; i += 1){
        scanf("%d", &nums1[i]);
    }

    printf("\nEnter size of nums2: ");
    scanf("%d", &n2);

    int nums2[n2];
    printf("\nEnter elements of nums2:\n");
    for(int i = 0; i < n2; i += 1){
        scanf("%d", &nums2[i]);
    }

    int returnSize = 0;
    int* ans = intersect(nums1, n1, nums2, n2, &returnSize);

    printf("\nIntersection of arrays: ");
    for(int i = 0; i < returnSize; i += 1){
        printf("%d ", ans[i]);
    }

    free(ans);
    return 0;
}
