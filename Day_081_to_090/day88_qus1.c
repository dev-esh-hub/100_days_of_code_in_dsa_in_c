/*
Problem Statement
Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.

This is an optimization problem where binary search on the answer is required.

Input Format
n k
n space-separated integers representing stall positions

Output Format
Print the maximum possible minimum distance between any two cows.

Sample Input
5 3
1 2 8 4 9

Sample Output
3

Explanation
Cows can be placed at positions 1, 4, and 8. The minimum distance between any two cows is 3, which is the maximum possible.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to compare for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Check if cows can be placed with minimum distance = mid
int canPlace(int stalls[], int n, int k, int mid) {
    int count = 1; // first cow placed
    int lastPos = stalls[0];

    for(int i = 1; i < n; i += 1) {
        if(stalls[i] - lastPos >= mid) {
            count += 1;
            lastPos = stalls[i];
        }
        if(count >= k) return 1;
    }
    return 0;
}

int main() {
    int n, k;

    printf("Enter number of stalls and cows: ");
    scanf("%d %d", &n, &k);

    int stalls[n];

    printf("Enter stall positions: ");
    for(int i = 0; i < n; i += 1) {
        scanf("%d", &stalls[i]);
    }

    // Sort stalls
    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n-1] - stalls[0];
    int ans = 0;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(canPlace(stalls, n, k, mid)) {
            ans = mid;
            low = mid + 1; // try bigger distance
        } else {
            high = mid - 1;
        }
    }

    printf("Maximum minimum distance: %d\n", ans);

    return 0;
}