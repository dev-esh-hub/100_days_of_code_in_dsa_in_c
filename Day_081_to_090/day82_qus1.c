/*
Problem: Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.

Lower Bound: The index of the first element in the array that is greater than or equal to x.
Upper Bound: The index of the first element in the array that is strictly greater than x.

Input:
- First line: integer n representing the size of the array
- Second line: n space-separated sorted integers
- Third line: integer x (the target value)

Output:
- Print two integers:
  1) Index of the lower bound of x
  2) Index of the upper bound of x

Example:
Input:
7
1 2 4 4 4 5 7
4

Output:
2 5

Explanation:
For the given array [1, 2, 4, 4, 4, 5, 7] and x = 4:
- The lower bound is at index 2, which is the first occurrence of 4.
- The upper bound is at index 5, which is the first element greater than 4 (i.e., 5).
Binary Search is used to find both bounds efficiently in O(log n) time.
*/

#include <stdio.h>

// Function to find Lower Bound (first index >= x)
int lowerBound(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    int ans = n;  // default if not found

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            right = mid - 1;  // move left to find first occurrence
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

// Function to find Upper Bound (first index > x)
int upperBound(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    int ans = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > x) {
            ans = mid;
            right = mid - 1;  // move left
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input sorted array
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &arr[i]);
    }

    int x;

    // Input target
    printf("Enter target value: ");
    scanf("%d", &x);

    // Function calls
    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    // Output
    printf("Lower Bound Index: %d\n", lb);
    printf("Upper Bound Index: %d\n", ub);

    return 0;
}