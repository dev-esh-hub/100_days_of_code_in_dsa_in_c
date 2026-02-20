/*
Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3
*/

#include<stdio.h>

void reverse(int arr[], int start, int end){
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start += 1;
        end -= 1; 
    }
}

int main(){
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter %d elements: \n", n);
    for(int i=0; i<n; i+=1){
        scanf("%d", &arr[i]);
    }

    int k;
    printf("\nEnter the no of steps you want to rotate: ");
    scanf("%d", &k);

    k %= n; // If k is greater than n so it becomes as per needed.

    reverse(arr, 0, n-1); // Whole array reverse.
    reverse(arr, 0, k-1); // Reversing first k elements in reversed array.
    reverse(arr, k, n-1); // Reversing remaining elements.

    printf("\nThe shifted array is:\n");
    for(int i=0; i<n; i+=1){
        printf("%d ", arr[i]);
    }

    return 0;
}