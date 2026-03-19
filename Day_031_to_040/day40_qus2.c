/*
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
*/

#include <stdio.h>
#include <stdlib.h>

// Function to compute daily temperatures
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {

    int* answer = (int*)malloc(sizeof(int) * temperaturesSize);
    int* stack = (int*)malloc(sizeof(int) * temperaturesSize); // stack for indices

    int top = -1;

    // Initialize answer array with 0
    for (int i = 0; i < temperaturesSize; i++) {
        answer[i] = 0;
    }

    for (int i = 0; i < temperaturesSize; i++) {

        // Check for warmer temperature
        while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int prevIndex = stack[top];
            top -= 1;

            answer[prevIndex] = i - prevIndex;
        }

        // Push current index
        top += 1;
        stack[top] = i;
    }

    *returnSize = temperaturesSize;

    free(stack);
    return answer;
}

int main() {
    int n;

    printf("Enter number of days: ");
    scanf("%d", &n);

    int* temperatures = (int*)malloc(sizeof(int) * n);

    printf("Enter %d temperatures:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temperatures[i]);
    }

    int returnSize;
    int* result = dailyTemperatures(temperatures, n, &returnSize);

    printf("Result (days to wait for warmer temperature):\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(temperatures);
    free(result);

    return 0;
}