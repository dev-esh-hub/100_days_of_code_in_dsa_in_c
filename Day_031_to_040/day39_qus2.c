/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]

 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
*/

#include <stdio.h>
#include <stdlib.h>

struct Pair {
    int num;
    int freq;
};

// Compare function (descending frequency):
int compare(const void *a, const void *b) {
    struct Pair *p1 = (struct Pair *)a;
    struct Pair *p2 = (struct Pair *)b;
    return p2->freq - p1->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {

    struct Pair* freq = (struct Pair*)malloc(sizeof(struct Pair) * numsSize);
    int uniqueCount = 0;

    for (int i = 0; i < numsSize; i += 1) {
        int found = 0;

        for (int j = 0; j < uniqueCount; j += 1) {
            if (freq[j].num == nums[i]) {
                freq[j].freq += 1;
                found = 1;
                break;
            }
        }

        if (!found) {
            freq[uniqueCount].num = nums[i];
            freq[uniqueCount].freq = 1;
            uniqueCount += 1;
        }
    }

    qsort(freq, uniqueCount, sizeof(struct Pair), compare);

    int* result = (int*)malloc(sizeof(int) * k);

    for (int i = 0; i < k; i += 1) {
        result[i] = freq[i].num;
    }

    *returnSize = k;

    free(freq);
    return result;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *nums = (int*)malloc(sizeof(int) * n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &nums[i]);
    }

    int k;
    printf("Enter value of k: ");
    scanf("%d", &k);

    int returnSize;

    int* result = topKFrequent(nums, n, k, &returnSize);

    printf("Top %d frequent elements are: ", k);
    for (int i = 0; i < returnSize; i += 1) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(nums);
    free(result);

    return 0;
}