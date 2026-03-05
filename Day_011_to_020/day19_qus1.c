/*
Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Function to find pair whose sum is closest to zero
int* pairSum(int n, int arr[]){
    int* result = (int*)malloc(2 * sizeof(int));

    int minSum = INT_MAX;   // store closest sum to zero

    for(int i = 0; i < n - 1; i += 1){
        for(int j = i + 1; j < n; j += 1){

            int sum = arr[i] + arr[j];

            if(sum < 0){
                sum = -sum;
            }

            if(sum < minSum){
                minSum = sum;
                result[0] = arr[i];
                result[1] = arr[j];
            }
        }
    }

    return result;
}

int main(){
    int n;
    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter %d elements:\n", n);
    for(int i = 0; i < n; i += 1){
        scanf("%d", &arr[i]);
    }

    int* ans = pairSum(n, arr);

    printf("\nPair closest to zero sum: %d %d\n", ans[0], ans[1]);

    free(ans);
    return 0;
}