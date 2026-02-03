/*
Delete an Element from an Array

Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left

*/

#include<stdio.h>

int main(){
    int n;
    printf("\nEnter the number of elements you want to enter: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for(int i=0; i<n; i+=1){
        scanf ("%d", &arr[i]);
    }

    int pos;
    printf("\nEnter the position (1-based position) to delete: ");
    scanf("%d", &pos);

    // Deleting the element from position by shifting elements itself:
    for(int i=pos; i<n; i+=1){
        arr[i-1] = arr[i];
    }

    // Printing the updated array:
    printf("\nThe updated array is: \n");
    for(int i=0; i<n-1; i+=1){
        printf("%d ", arr[i]);
    }

    return 0;
}