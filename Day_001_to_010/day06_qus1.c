/*
Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3
*/

/*
// Using O(n^2) Time Complexity:

#include<stdio.h>

int main(){
    
    int n;
    printf("\nEnter the number of elements to enter in array: ");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter %d elements in sorted order (some elements can come more than 1 time): ", n);
    for(int i=0; i<n; i+=1){
        scanf("%d", &arr[i]);
    }

    int count = n;
    int i = 1;

    while(i < count){

        if(arr[i] == arr[i-1]){
            for(int j=i; j<count-1; j+=1){
                arr[j] = arr[j+1];
            }
            count -= 1;
        }
        else {
            i+=1;
        }
    }

    printf("\nUnique elements are:\n");
    for(int i = 0; i < count; i += 1){
        printf("%d ", arr[i]);
    }

    return 0;
}
*/

/*
// Using O(n) Time Complexity:

#include<stdio.h>

int main(){
    
    int n;
    printf("\nEnter the number of elements to enter in array: ");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter %d elements in sorted order (some elements can come more than 1 time): ", n);
    for(int i = 0; i < n; i += 1){
        scanf("%d", &arr[i]);
    }

    if(n == 0){
        return 0;
    }

    int unique_index = 0;

    for(int i = 1; i < n; i += 1){
        if(arr[i] != arr[unique_index]){
            unique_index += 1;
            arr[unique_index] = arr[i];
        }
    }

    printf("\nUnique elements are:\n");
    for(int i = 0; i <= unique_index; i += 1){
        printf("%d ", arr[i]);
    }

    return 0;
}
*/

