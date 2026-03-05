/*
Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.
*/

#include <stdio.h>

int countZeroSumSubarrays(int arr[], int n) {
    int prefix[n];
    int count = 0;

    // Building prefix sum:
    prefix[0] = arr[0];
    for (int i = 1; i < n; i += 1) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    // Checking zero-sum subarrays:
    for (int i = 0; i < n; i += 1) {

        // Subarray from start:
        if (prefix[i] == 0) {
            count += 1;
        }

        // Subarrays between i and j:
        for (int j = i + 1; j < n; j += 1) {
            if (prefix[j] == prefix[i]) {
                count += 1;
            }
        }
    }

    return count;
}

int main() {
    int n;

    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter elements:\n");

    for (int i = 0; i < n; i += 1) {
        scanf("%d", &arr[i]);
    }

    int result = countZeroSumSubarrays(arr, n);
    printf("\nNumber of zero-sum subarrays: %d\n", result);

    return 0;
}