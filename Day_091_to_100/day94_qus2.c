/*
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

 

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
Example 2:

Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]
 

Constraints:

1 <= arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
All the elements of arr2 are distinct.
Each arr2[i] is in arr1.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to perform relative sort
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {

    int count[1001] = {0};

    // Step 1: Count frequency of elements in arr1
    for (int i = 0; i < arr1Size; i += 1) {
        count[arr1[i]] += 1;
    }

    // Allocate result array
    int* result = (int*)malloc(arr1Size * sizeof(int));
    int index = 0;

    // Step 2: Place elements according to arr2 order
    for (int i = 0; i < arr2Size; i += 1) {
        int val = arr2[i];

        while (count[val] > 0) {
            result[index] = val;
            index += 1;
            count[val] -= 1;
        }
    }

    // Step 3: Place remaining elements in ascending order
    for (int i = 0; i <= 1000; i += 1) {
        while (count[i] > 0) {
            result[index] = i;
            index += 1;
            count[i] -= 1;
        }
    }

    *returnSize = arr1Size;
    return result;
}

int main() {
    int n, m;

    printf("Enter size of arr1: ");
    scanf("%d", &n);

    int arr1[n];
    printf("Enter elements of arr1:\n");
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of arr2: ");
    scanf("%d", &m);

    int arr2[m];
    printf("Enter elements of arr2:\n");
    for (int i = 0; i < m; i += 1) {
        scanf("%d", &arr2[i]);
    }

    int returnSize;

    int* result = relativeSortArray(arr1, n, arr2, m, &returnSize);

    printf("Relative Sorted Array:\n");
    for (int i = 0; i < returnSize; i += 1) {
        printf("%d ", result[i]);
    }

    // Free allocated memory
    free(result);

    return 0;
}