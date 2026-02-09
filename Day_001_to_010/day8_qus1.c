/*
Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32
*/

#include<stdio.h>

float expo(int a, int b, int count){

    if(count == 0){
        return 1;
    }

    return a * expo(a, b, count-1);
}

int main(){

    float a, b;
    printf("\nEnter the value of base (a) and exponent (b) respectively: ");
    scanf("%f %f", &a, &b);

    int count = b;
    float result = expo(a, b, count);

    printf("\nResult = %.2f", result);

    return 0;
}