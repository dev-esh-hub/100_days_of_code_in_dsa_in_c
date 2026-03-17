/*
Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int *queue = (int*)malloc(sizeof(int)*n);

    int front = 0;
    int rear = -1;

    int i = 0;
    int value;

    printf("Enter %d elements:\n",n);

    // Enqueue operation:
    while(i < n)
    {
        scanf("%d",&value);

        rear += 1;
        queue[rear] = value;

        i += 1;
    }

    // Display queue:
    printf("Queue elements (Front to Rear): ");

    i = front;

    while(i <= rear)
    {
        printf("%d ",queue[i]);
        i += 1;
    }

    free(queue);

    return 0;
}