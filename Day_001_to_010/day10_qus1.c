/*
Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards
*/

#include<stdio.h>
#include<string.h>

int isPalindrome(char str[], int size){
    int start=0, end=size-1;
    while(start<end){
        if(str[start] != str[end]){
            return -1;
        }
        start+=1;
        end-=1;
    }
    return 1;
}

int main(){
    char string[50];
    printf("\nEnter the string: ");
    scanf("%s", string);

    int size = strlen(string);

    if(isPalindrome(string, size) == 1){
        printf("YES Palindrome!\n");
    }
    else{
        printf("NO Palindrome!\n");
    }

    return 0;
}