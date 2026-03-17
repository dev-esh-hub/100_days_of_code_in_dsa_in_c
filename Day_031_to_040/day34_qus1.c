/*
Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Node structure for stack
struct node
{
    int data;
    struct node* next;
};

// Push function
void push(struct node** top, int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = *top;
    *top = newnode;
}

// Pop function
int pop(struct node** top)
{
    if(*top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    struct node* temp = *top;
    int value = temp->data;

    *top = temp->next;
    free(temp);

    return value;
}

int main()
{
    struct node* top = NULL;

    char postfix[100];
    char *token;

    printf("Enter Postfix Expression (space separated): ");
    fgets(postfix,100,stdin);

    token = strtok(postfix," ");

    while(token != NULL)
    {
        // If operand
        if(isdigit(token[0]) || 
          (token[0] == '-' && isdigit(token[1])))
        {
            int num = atoi(token);
            push(&top,num);
        }
        else
        {
            int b = pop(&top);
            int a = pop(&top);

            int result;

            if(token[0] == '+')
                result = a + b;

            else if(token[0] == '-')
                result = a - b;

            else if(token[0] == '*')
                result = a * b;

            else if(token[0] == '/')
                result = a / b;

            push(&top,result);
        }

        token = strtok(NULL," ");
    }

    int finalResult = pop(&top);

    printf("Result of Postfix Expression: %d\n", finalResult);

    return 0;
}