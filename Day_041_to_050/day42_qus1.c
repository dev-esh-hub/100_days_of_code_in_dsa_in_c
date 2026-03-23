/*
Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node Node;

typedef struct node StackNode;

Node* front = NULL;
Node* rear = NULL;

StackNode* top = NULL;

// Queue operations:
void enqueue(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

int dequeue() {
    if (front == NULL) {
        return -1;
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

// Stack operations:
void push(int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        return -1;
    }

    StackNode* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

// Reverse queue using stack:
void reverseQueue() {
    // Step 1: Queue -> Stack:
    while (front != NULL) {
        push(dequeue());
    }

    // Step 2: Stack -> Queue:
    while (top != NULL) {
        enqueue(pop());
    }
}

// Printing queue:
void printQueue() {
    Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    reverseQueue();

    printf("Reversed Queue:\n");
    printQueue();

    return 0;
}