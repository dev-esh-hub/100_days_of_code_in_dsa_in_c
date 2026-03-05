/*
Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

// Create a new node:
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the end:
struct node* insertEnd(struct node* head, int value) {
    struct node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Print list in forward direction:
void printForward(struct node* head) {
    printf("\nForward traversal: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Free the list:
void freeList(struct node* head) {
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct node* head = NULL;
    int n, value;

    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printForward(head);

    freeList(head);
    return 0;
}