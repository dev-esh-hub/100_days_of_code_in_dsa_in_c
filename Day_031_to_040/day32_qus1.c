/*
Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10
*/

#include<stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value){

    if(top == MAX-1){
        printf("Stack Overflow\n");
        return;
    }

    top += 1;
    stack[top] = value;
}

// Pop operation
void pop(){

    if(top == -1){
        printf("Stack Underflow\n");
        return;
    }

    top -= 1;
}

// Display stack from top to bottom
void display(){

    if(top == -1){
        printf("Stack is empty\n");
        return;
    }

    printf("\nRemaining stack elements (top to bottom):\n");

    for(int i = top; i >= 0; i -= 1){
        printf("%d ", stack[i]);
    }

    printf("\n");
}

int main(){

    int n, m, value;

    printf("Enter number of elements to push: ");
    scanf("%d",&n);

    printf("Enter %d elements:\n",n);

    for(int i=0;i<n;i+=1){

        scanf("%d",&value);
        push(value);
    }

    printf("Enter number of pop operations: ");
    scanf("%d",&m);

    for(int i=0;i<m;i+=1){
        pop();
    }

    display();

    return 0;
}