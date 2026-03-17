/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int *stack;
    int *minStack;
    int top;
    int capacity;
} MinStack;

// Function to create stack
MinStack* minStackCreate(int capacity){

    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));

    obj->capacity = capacity;
    obj->stack = (int*)malloc(sizeof(int)*capacity);
    obj->minStack = (int*)malloc(sizeof(int)*capacity);
    obj->top = -1;

    return obj;
}

// Push operation
void minStackPush(MinStack* obj, int val){

    if(obj->top == obj->capacity - 1){
        printf("Stack Overflow\n");
        return;
    }

    obj->top += 1;

    obj->stack[obj->top] = val;

    if(obj->top == 0){
        obj->minStack[obj->top] = val;
    }
    else{
        if(val < obj->minStack[obj->top-1])
            obj->minStack[obj->top] = val;
        else
            obj->minStack[obj->top] = obj->minStack[obj->top-1];
    }

    printf("Element %d pushed into stack\n", val);
}

// Pop operation
void minStackPop(MinStack* obj){

    if(obj->top == -1){
        printf("Stack Underflow\n");
        return;
    }

    printf("Element %d popped\n", obj->stack[obj->top]);
    obj->top -= 1;
}

// Top element
int minStackTop(MinStack* obj){

    if(obj->top == -1){
        printf("Stack Empty\n");
        return -1;
    }

    return obj->stack[obj->top];
}

// Get minimum
int minStackGetMin(MinStack* obj){

    if(obj->top == -1){
        printf("Stack Empty\n");
        return -1;
    }

    return obj->minStack[obj->top];
}

// Free memory
void minStackFree(MinStack* obj){

    free(obj->stack);
    free(obj->minStack);
    free(obj);
}

// MAIN FUNCTION
int main(){

    int capacity;
    printf("Enter stack capacity: ");
    scanf("%d",&capacity);

    MinStack* obj = minStackCreate(capacity);

    int choice;
    int value;

    while(1){

        printf("\n--- MIN STACK OPERATIONS ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top Element\n");
        printf("4. Get Minimum\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        if(choice == 1){

            printf("Enter value to push: ");
            scanf("%d",&value);

            minStackPush(obj,value);
        }

        else if(choice == 2){

            minStackPop(obj);
        }

        else if(choice == 3){

            int top = minStackTop(obj);

            if(top != -1)
                printf("Top element is: %d\n",top);
        }

        else if(choice == 4){

            int min = minStackGetMin(obj);

            if(min != -1)
                printf("Minimum element is: %d\n",min);
        }

        else if(choice == 5){

            minStackFree(obj);
            printf("Stack memory freed. Program Ended.\n");
            break;
        }

        else{
            printf("Invalid choice\n");
        }
    }

    return 0;
}