/*
Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the reversed array, space-separated

Example:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1

Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays
*/

#include<stdio.h>

int main(){
    int n;
    printf("\nEnter the number of elements you want to enter in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: \n", n);
    for(int i=0; i<n ; i+=1){
        scanf("%d", &arr[i]);
    }
    printf("\n");
    int left = 0, right = n-1;
    while(left < right){
        arr[left] = arr[left] + arr[right];
        arr[right] = arr[left] - arr[right];
        arr[left] = arr[left] - arr[right];
        left += 1;
        right -= 1;
    }

    printf("The reversed array is:\n");
    for(int i=0; i<n; i+=1){
        printf("%d ", arr[i]);
    }
    return 0;
}