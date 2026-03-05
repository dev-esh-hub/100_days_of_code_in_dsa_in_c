/*
Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* CreateNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void displayList(struct node* head) {
    struct node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, data;

    printf("Enter value of n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("List is empty\n");
        return 0;
    }

    struct node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i += 1) {
        scanf("%d", &data);

        newNode = CreateNode(data);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Linked List: ");
    displayList(head);

    return 0;
}