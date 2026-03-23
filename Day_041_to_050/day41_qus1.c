/*
Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node Node;

Node* front = NULL;
Node* rear = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(int data) {
    Node* newNode = createNode(data);

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

int dequeue() {
    if (front == NULL) {
        return -1;  // Queue empty
    }

    Node* temp = front;
    int value = temp->data;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    return value;
}

int main() {
    int n;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    printf("Enter operations (1 x for enqueue, 2 for dequeue):\n");

    for (int i = 0; i < n; i++) {
        int choice, value;

        scanf("%d", &choice);

        if (choice == 1) {
            scanf("%d", &value);
            enqueue(value);
        } 
        else if (choice == 2) {
            int result = dequeue();
            printf("%d\n", result);
        }
    }

    return 0;
}