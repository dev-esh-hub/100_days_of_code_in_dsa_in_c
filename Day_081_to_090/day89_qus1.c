/*
Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113

Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible).
*/

#include <stdio.h>

// function to check if allocation is possible
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for(int i = 0; i < n; i += 1) {

        // if single book > maxPages → impossible
        if(arr[i] > maxPages) return 0;

        if(pagesSum + arr[i] <= maxPages) {
            pagesSum += arr[i];
        } else {
            students += 1;
            pagesSum = arr[i];
        }

        if(students > m) return 0;
    }

    return 1;
}

// main function
int findMinPages(int arr[], int n, int m) {
    int sum = 0;
    int max = 0;

    for(int i = 0; i < n; i += 1) {
        sum += arr[i];
        if(arr[i] > max) max = arr[i];
    }

    int low = max;
    int high = sum;
    int ans = -1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1; // minimize
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

// driver code
int main() {
    int n, m;

    printf("Enter number of books and students: ");
    scanf("%d %d", &n, &m);

    int arr[n];

    printf("Enter pages in books: ");
    for(int i = 0; i < n; i += 1) {
        scanf("%d", &arr[i]);
    }

    int result = findMinPages(arr, n, m);

    printf("Minimum possible maximum pages: %d\n", result);

    return 0;
}