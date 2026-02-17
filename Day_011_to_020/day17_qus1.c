/*
Problem: Write a program to find the maximum and minimum values present in a given array of integers.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the maximum and minimum elements

Example:
Input:
6
3 5 1 9 2 8

Output:
Max: 9
Min: 1
*/

#include<stdio.h>
#include<stdlib.h>

void max_and_min(int * arr, int n, int *max, int *min){

    *max = arr[0], *min = arr[0];

    for(int i=0; i<n; i+=1){
        if(arr[i] < *min){
            *min = arr[i];
        }
        if(arr[i] > *max){
            *max = arr[i];
        }
    }
}

int main(){

    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter elements:\n");
    for(int i = 0; i < n; i += 1){
        scanf("%d", &arr[i]);
    }

    int max, min;

    max_and_min(arr, n, &max, &min);

    printf("\nMax: %d", max);
    printf("\nMin: %d\n", min);

    free(arr);

    return 0;
}