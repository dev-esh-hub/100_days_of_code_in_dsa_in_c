/*
Insert an Element in an Array

Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right
*/

#include<stdio.h>

int main(){

    int n;
    printf("\nEnter the number of elements you want to enter: ");
    scanf("%d", &n);

    int arr[n+1];
    printf("Enter elements: ");
    for(int i=0; i<n; i+=1){
        scanf ("%d", &arr[i]);
    }

    int x, pos;
    printf("\nEnter the position where  you want to insert the element: ");
    scanf("%d", &pos);
    printf("Enter the element you want to insert: ");
    scanf("%d", &x);

    // Array shifting for inserting element:
    for(int i=n-1; i>=pos-1; i-=1){
        arr[i+1] = arr[i];
    }

    // Inserting the element:
    arr[pos-1] = x;

    // Printing the updated array:
    printf("\nThe updated array is: \n");
    for(int i=0; i<=n; i+=1){
        printf("%d ", arr[i]);
    }

    return 0;
}