/*
Problem: A system receives two separate logs of user arrival times from two different servers. 
Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed
*/

#include<stdio.h>

int main(){

    int n1, n2;

    printf("\nEnter the number of elemets for first array: ");
    scanf("%d", &n1);

    int arr1[n1]; 
    printf("\nEnter %d elements for first array in ascending order: ", n1);
    for(int i=0; i<n1; i+=1){
        scanf("%d", &arr1[i]);
    }

    printf("\nEnter the number of elemets for second array: ");
    scanf("%d", &n2);

    int arr2[n2];
    printf("\nEnter %d elements for second array in ascending order: ", n2);
    for(int i=0; i<n2; i+=1){
        scanf("%d", &arr2[i]);
    }

    int i=0, j=0;

    while(i<n1 && j<n2){
        if(arr1[i] < arr2[j]){
            printf("%d ", arr1[i]);
            i+=1;
        }
        else if(arr1[i] > arr2[j]) {
            printf("%d ", arr2[j]);
            j+=1;
        }
        else {
            printf("%d %d ", arr1[i], arr2[j]);
            i+=1;
            j+=1;
        }
    }

    while(i < n1){
        printf("%d ", arr1[i]);
        i+=1;
    }
    while(j < n2){
        printf("%d ", arr2[j]);
        j+=1;
    }

    return 0;
}