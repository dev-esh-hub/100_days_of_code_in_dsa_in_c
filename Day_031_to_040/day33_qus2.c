/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 

Constraints:

1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10000

int evalRPN(char tokens[][20], int tokensSize)
{
    int stack[MAX];
    int top = -1;

    int i = 0;

    while(i < tokensSize)
    {
        if(strcmp(tokens[i], "+") == 0 ||
           strcmp(tokens[i], "-") == 0 ||
           strcmp(tokens[i], "*") == 0 ||
           strcmp(tokens[i], "/") == 0)
        {
            int b = stack[top];
            top -= 1;

            int a = stack[top];
            top -= 1;

            int result;

            if(strcmp(tokens[i], "+") == 0)
                result = a + b;

            else if(strcmp(tokens[i], "-") == 0)
                result = a - b;

            else if(strcmp(tokens[i], "*") == 0)
                result = a * b;

            else
                result = a / b;

            top += 1;
            stack[top] = result;
        }
        else
        {
            top += 1;
            stack[top] = atoi(tokens[i]);
        }

        i += 1;
    }

    return stack[top];
}

int main()
{
    int n;

    printf("Enter number of tokens: ");
    scanf("%d",&n);

    char tokens[n][20];

    printf("Enter the tokens (separated by space):\n");

    int i = 0;

    while(i < n)
    {
        scanf("%s", tokens[i]);
        i += 1;
    }

    int result = evalRPN(tokens,n);

    printf("\nResult of Reverse Polish Expression: %d\n",result);

    return 0;
}