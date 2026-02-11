/*
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.
*/

#include <stdio.h>
#include <string.h>

void reverseString(char* s, int sSize) {
    int i = 0;
    int j = sSize - 1;

    while(i < j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        i += 1;
        j -= 1;
    }
}

int main(){

    char s[100005];

    printf("\nEnter the string (no spaces): ");
    scanf("%s", s);

    int length = strlen(s);

    printf("\nOriginal string: %s", s);

    reverseString(s, length);

    printf("\nReversed string: %s", s);

    return 0;
}
