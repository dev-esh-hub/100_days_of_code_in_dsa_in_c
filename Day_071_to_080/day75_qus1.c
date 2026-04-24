/*
Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.
*/

#include <stdio.h>

#define MAX 1000
#define OFFSET 100000   // To handle negative sums

int main() {

    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[MAX];

    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int hash[2 * OFFSET + 1];

    // Initialize hash table
    for(int i = 0; i < 2 * OFFSET + 1; i++) {
        hash[i] = -1;
    }

    int sum = 0;
    int maxLen = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum is zero
        if(sum == 0) {
            maxLen = i + 1;
        }

        // Case 2: sum seen before
        if(hash[sum + OFFSET] != -1) {
            int len = i - hash[sum + OFFSET];
            if(len > maxLen) {
                maxLen = len;
            }
        } else {
            hash[sum + OFFSET] = i;
        }
    }

    printf("Length of longest zero-sum subarray: %d\n", maxLen);

    return 0;
}
