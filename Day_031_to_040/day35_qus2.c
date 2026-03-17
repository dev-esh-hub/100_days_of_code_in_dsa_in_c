/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 

Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100

typedef struct {
    int stack1[MAX];
    int stack2[MAX];
    int top1;
    int top2;
} MyQueue;

MyQueue* myQueueCreate() {

    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));

    obj->top1 = -1;
    obj->top2 = -1;

    return obj;
}

void myQueuePush(MyQueue* obj, int x) {

    obj->top1 += 1;
    obj->stack1[obj->top1] = x;

    printf("Element %d pushed into queue\n", x);
}

int myQueuePop(MyQueue* obj) {

    if(obj->top1 == -1 && obj->top2 == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }

    if(obj->top2 == -1)
    {
        while(obj->top1 != -1)
        {
            int temp = obj->stack1[obj->top1];
            obj->top1 -= 1;

            obj->top2 += 1;
            obj->stack2[obj->top2] = temp;
        }
    }

    int value = obj->stack2[obj->top2];
    obj->top2 -= 1;

    return value;
}

int myQueuePeek(MyQueue* obj) {

    if(obj->top1 == -1 && obj->top2 == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }

    if(obj->top2 == -1)
    {
        while(obj->top1 != -1)
        {
            int temp = obj->stack1[obj->top1];
            obj->top1 -= 1;

            obj->top2 += 1;
            obj->stack2[obj->top2] = temp;
        }
    }

    return obj->stack2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {

    if(obj->top1 == -1 && obj->top2 == -1)
        return true;

    return false;
}

void myQueueFree(MyQueue* obj) {

    free(obj);
}

int main()
{
    MyQueue* queue = myQueueCreate();

    int choice;
    int value;

    while(1)
    {
        printf("\n---- Queue Using Two Stacks ----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check Empty\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        if(choice == 1)
        {
            printf("Enter value to push: ");
            scanf("%d",&value);

            myQueuePush(queue,value);
        }

        else if(choice == 2)
        {
            int result = myQueuePop(queue);

            if(result != -1)
                printf("Popped element: %d\n",result);
        }

        else if(choice == 3)
        {
            int result = myQueuePeek(queue);

            if(result != -1)
                printf("Front element: %d\n",result);
        }

        else if(choice == 4)
        {
            if(myQueueEmpty(queue))
                printf("Queue is empty\n");
            else
                printf("Queue is not empty\n");
        }

        else if(choice == 5)
        {
            myQueueFree(queue);
            printf("Program terminated\n");
            break;
        }

        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}