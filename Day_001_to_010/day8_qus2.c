/*
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false
 

Constraints:

-231 <= n <= 231 - 1
*/

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {

    if(n <= 0){
        return false;
    }

    int count = 0;
    
    while(n > 0){
        if(n % 2 == 1){
            count += 1;
        }
        n /= 2;
    }
    
    if(count == 1){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if(isPowerOfTwo(n)){
        printf("\n%d is a power of two!\n", n);
    }
    else{
        printf("\n%d is NOT a power of two!\n", n);
    }

    return 0;
}
