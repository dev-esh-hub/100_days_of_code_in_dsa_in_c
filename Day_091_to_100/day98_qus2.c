/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
Example 3:

Input: intervals = [[4,7],[1,4]]
Output: [[1,7]]
Explanation: Intervals [1,4] and [4,7] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/

#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting intervals by start time
int compare(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

// Merge function
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {

    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Step 1: Sort intervals
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    // Allocate result
    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    int idx = 0;

    // First interval
    result[0] = (int*)malloc(2 * sizeof(int));
    result[0][0] = intervals[0][0];
    result[0][1] = intervals[0][1];
    (*returnColumnSizes)[0] = 2;

    // Step 2: Merge intervals
    for (int i = 1; i < intervalsSize; i += 1) {

        if (intervals[i][0] <= result[idx][1]) {
            // Overlapping → extend
            if (intervals[i][1] > result[idx][1]) {
                result[idx][1] = intervals[i][1];
            }
        } else {
            // Non-overlapping → new interval
            idx += 1;
            result[idx] = (int*)malloc(2 * sizeof(int));
            result[idx][0] = intervals[i][0];
            result[idx][1] = intervals[i][1];
            (*returnColumnSizes)[idx] = 2;
        }
    }

    *returnSize = idx + 1;
    return result;
}

int main() {
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    // Allocate 2D array
    int** intervals = (int**)malloc(n * sizeof(int*));
    int* intervalsColSize = (int*)malloc(n * sizeof(int));

    printf("Enter intervals (start end):\n");
    for (int i = 0; i < n; i += 1) {
        intervals[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
        intervalsColSize[i] = 2;
    }

    int returnSize;
    int* returnColumnSizes;

    int** result = merge(intervals, n, intervalsColSize, &returnSize, &returnColumnSizes);

    printf("Merged intervals:\n");
    for (int i = 0; i < returnSize; i += 1) {
        printf("[%d, %d] ", result[i][0], result[i][1]);
    }
    printf("\n");

    // Free memory
    for (int i = 0; i < n; i += 1) {
        free(intervals[i]);
    }
    free(intervals);
    free(intervalsColSize);

    for (int i = 0; i < returnSize; i += 1) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}