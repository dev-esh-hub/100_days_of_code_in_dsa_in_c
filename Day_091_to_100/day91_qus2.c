/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
*/

#include <stdio.h>

// Function to sort array of 0s, 1s, and 2s
void sortColors(int* nums, int numsSize) {
    int low = 0;
    int mid = 0;
    int high = numsSize - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            // swap nums[low] and nums[mid]
            int temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;

            low += 1;
            mid += 1;
        }
        else if (nums[mid] == 1) {
            mid += 1;
        }
        else { // nums[mid] == 2
            // swap nums[mid] and nums[high]
            int temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;

            high -= 1;
        }
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements (only 0, 1, 2):\n");
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &nums[i]);
    }

    sortColors(nums, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i += 1) {
        printf("%d ", nums[i]);
    }

    return 0;
}