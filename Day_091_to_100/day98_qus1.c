/*
Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for interval
struct Interval {
    int start;
    int end;
};

// Comparator for sorting by start time
int compare(const void* a, const void* b) {
    struct Interval* x = (struct Interval*)a;
    struct Interval* y = (struct Interval*)b;
    return x->start - y->start;
}

// Function to merge intervals
void mergeIntervals(struct Interval arr[], int n) {

    if (n == 0) return;

    // Step 1: sort intervals
    qsort(arr, n, sizeof(struct Interval), compare);

    // Result array
    struct Interval result[n];
    int idx = 0;

    result[0] = arr[0];

    // Step 2: merge
    for (int i = 1; i < n; i += 1) {

        // If overlapping
        if (arr[i].start <= result[idx].end) {
            if (arr[i].end > result[idx].end) {
                result[idx].end = arr[i].end;
            }
        } else {
            // No overlap → add new interval
            idx += 1;
            result[idx] = arr[i];
        }
    }

    // Step 3: print result
    printf("Merged intervals:\n");
    for (int i = 0; i <= idx; i += 1) {
        printf("[%d, %d] ", result[i].start, result[i].end);
    }
}

int main() {
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    struct Interval arr[n];

    printf("Enter intervals (start end):\n");
    for (int i = 0; i < n; i += 1) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    mergeIntervals(arr, n);

    return 0;
}