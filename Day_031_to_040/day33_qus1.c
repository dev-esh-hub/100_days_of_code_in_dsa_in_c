/*
Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char x)
{
    top += 1;
    stack[top] = x;
}

// Pop function
char pop()
{
    char temp = stack[top];
    top -= 1;
    return temp;
}

// Check precedence
int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;

    if(op == '*' || op == '/')
        return 2;

    if(op == '^')
        return 3;

    return 0;
}

int main()
{
    char infix[MAX];
    char postfix[MAX];

    int i = 0;
    int k = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    while(infix[i] != '\0')
    {
        char ch = infix[i];

        // If operand
        if(isalnum(ch))
        {
            postfix[k] = ch;
            k += 1;
        }

        // If '('
        else if(ch == '(')
        {
            push(ch);
        }

        // If ')'
        else if(ch == ')')
        {
            while(stack[top] != '(')
            {
                postfix[k] = pop();
                k += 1;
            }
            pop();
        }

        // If operator
        else
        {
            while(top != -1 && precedence(stack[top]) >= precedence(ch))
            {
                postfix[k] = pop();
                k += 1;
            }
            push(ch);
        }

        i += 1;
    }

    // Pop remaining operators
    while(top != -1)
    {
        postfix[k] = pop();
        k += 1;
    }

    postfix[k] = '\0';

    printf("\nPostfix Expression: %s\n", postfix);

    return 0;
}