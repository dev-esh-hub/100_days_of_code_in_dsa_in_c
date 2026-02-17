/*
Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1
*/

#include<stdio.h>

int main(){
    int n;
    printf("\nEnter the number of elements you want to enter in the array: ");
    scanf("%d", &n);


    int arr[n];
    printf("\nEnter %d elements:\n", n);
    for(int i=0; i<n; i+=1){
        scanf("%d", &arr[i]);
    }

    int freq[101] = {0};
    for(int i=0; i<n; i+=1){
        freq[arr[i]] += 1;
    }

    printf("\nFrequencies of elements:\n");
    for(int i=0; i<n; i+=1){
         if(freq[arr[i]] != 0){
            printf("%d:%d ", arr[i], freq[arr[i]]);
            freq[arr[i]] = 0;
        }
    }
    return 0;
}