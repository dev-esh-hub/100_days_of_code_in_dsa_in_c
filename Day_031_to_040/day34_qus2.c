/*
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
 

Constraints:

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX 300000

int calculate(char* s)
{
    int stack[MAX];
    int top = -1;

    int num = 0;
    char sign = '+';

    int i = 0;

    while(s[i] != '\0')
    {
        if(isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');
        }

        if((!isdigit(s[i]) && s[i] != ' ') || s[i+1] == '\0')
        {
            if(sign == '+')
            {
                top += 1;
                stack[top] = num;
            }

            else if(sign == '-')
            {
                top += 1;
                stack[top] = -num;
            }

            else if(sign == '*')
            {
                int temp = stack[top];
                stack[top] = temp * num;
            }

            else if(sign == '/')
            {
                int temp = stack[top];
                stack[top] = temp / num;
            }

            sign = s[i];
            num = 0;
        }

        i += 1;
    }

    int result = 0;

    while(top >= 0)
    {
        result = result + stack[top];
        top -= 1;
    }

    return result;
}

int main()
{
    char s[300000];

    printf("Enter the expression: ");
    fgets(s,300000,stdin);

    int ans = calculate(s);

    printf("Result = %d\n", ans);

    return 0;
}