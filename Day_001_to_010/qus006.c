/*
You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.

Examples:

Input: arr[] = [1, 2, 3, 5]
Output: 4
Explanation: All the numbers from 1 to 5 are present except 4.
Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
Output: 6
Explanation: All the numbers from 1 to 8 are present except 6.
Input: arr[] = [1]
Output: 2
Explanation: Only 1 is present so the missing element is 2.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ arr.size() + 1
*/

#include <stdio.h>

int missingNum(int *arr, int size) {
    int actual_sum = 0, array_sum = 0;

    for(int i = 0; i < size; i+=1) {
        array_sum += arr[i];
    }

    int noe = size + 1;   // total numbers including missing one

    // Sum of first n natural numbers
    actual_sum = (noe * (noe + 1)) / 2;

    int num = actual_sum - array_sum;
    return num;
}

int main() {
    int size;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d elements (from 1 to %d):\n", size, size + 1);
    for(int i = 0; i < size; i+=1) {
        scanf("%d", &arr[i]);
    }

    int missing = missingNum(arr, size);

    printf("Missing number is: %d\n", missing);

    return 0;
}

