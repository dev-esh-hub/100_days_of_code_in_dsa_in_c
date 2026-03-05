/*
Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* insertEnd(struct node* head, int data) {
    struct node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

// Deleting first occurrence of key:
struct node* deleteKey(struct node* head, int key) {
    struct node* temp = head;
    struct node* prev = NULL;

    // Case 1: Key is in head node so:
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Case 2: Traversing list to find key:
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Case 3: Key not found so:
    if (temp == NULL) {
        return head;
    }

    // Removing node:
    prev->next = temp->next;
    free(temp);

    return head;
}

// Printing list:
void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, value, key;
    struct node* head = NULL;

    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("\nEnter the key to delete: ");
    scanf("%d", &key);

    head = deleteKey(head, key);

    display(head);

    return 0;
}