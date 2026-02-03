/*
Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)
*/

#include<stdio.h>
#include <stdlib.h>

int *linear_search(int n, int k, int arr[], int *returnsize){

    int *resultant_array = (int*)malloc(*returnsize * sizeof(int));
    resultant_array[0] = -1;
    resultant_array[1] = -1;

    int count=0;

    for(int i=0; i<n; i+=1){
        count += 1;
        if(arr[i] == k){
            resultant_array[0] = i;
            resultant_array[1] = count;
            return resultant_array;
        }
    }
    
    return resultant_array;
}

int main(){

    int n, k;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter %d elements:\n", n);
    for(int i=0; i<n; i+=1){
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the element to search: ");
    scanf("%d", &k);

    // Linear search:
    int return_size = 2; // The returning array will have two elements capacity.
    int *result = linear_search(n, k, arr, &return_size);

    if(result[0] == -1 && result[1] == -1){
        printf("\nThe elements NOT FOUND!");
    }
    else {
        printf("Element found at index: %d\n", result[0]);
        printf("Total number of comparisons: %d\n", result[1]);
    }

    return 0;
}