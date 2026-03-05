/*
Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.
*/

#include<stdio.h>
#include<stdlib.h>

// Defining the node structure
struct node{
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int data){

    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

// Function to insert node at end
void insertAtEnd(struct node** head, int data){

    struct node* newnode = createNode(data);

    // If list is empty
    if(*head == NULL){

        *head = newnode;
        newnode->next = *head;
        return;
    }

    struct node* temp = *head;

    // Move to last node
    while(temp->next != *head){
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = *head;
}

// Function to display circular linked list
void displayList(struct node* head){

    if(head == NULL){
        printf("Linked List is empty.\n");
        return;
    }

    struct node* temp = head;

    printf("\nCircular Linked List Elements:\n");

    do{
        printf("%d ", temp->data);
        temp = temp->next;

    }while(temp != head);

    printf("\n");
}

int main(){

    struct node* head = NULL;

    int n;
    int value;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    printf("Enter %d elements:\n", n);

    for(int i=0;i<n;i+=1){

        printf("Enter element %d: ", i+1);
        scanf("%d",&value);

        insertAtEnd(&head,value);
    }

    displayList(head);

    return 0;
}