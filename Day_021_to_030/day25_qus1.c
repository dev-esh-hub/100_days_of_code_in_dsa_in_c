/*
Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to create a new node:
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to append node at the end:
struct node* appendNode(struct node* head, int value) {
    struct node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Function to display linked list:
void printList(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to count occurrences of key:
int countOccurrences(struct node* head, int key) {
    int count = 0;

    while (head != NULL) {
        if (head->data == key)
            count += 1;
        head = head->next;
    }
    return count;
}

// Function to free the linked list:
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
    int n, value, key;

    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = appendNode(head, value);
    }

    printf("\nLinked list: ");
    printList(head);

    printf("\nEnter key: ");
    scanf("%d", &key);

    int result = countOccurrences(head, key);
    printf("\nOccurrences of %d = %d\n", key, result);

    freeList(head);
    return 0;
}