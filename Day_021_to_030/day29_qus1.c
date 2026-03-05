/*
Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.
*/

#include<stdio.h>
#include<stdlib.h>

// Node structure
struct node{
    int data;
    struct node* next;
};

// Create new node
struct node* createNode(int data){

    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

// Insert at end
void insertAtEnd(struct node** head,int data){

    struct node* newnode = createNode(data);

    if(*head == NULL){
        *head = newnode;
        return;
    }

    struct node* temp = *head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newnode;
}

// Display list
void displayList(struct node* head){

    struct node* temp = head;

    printf("\nLinked List:\n");

    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Rotate list right by k
struct node* rotateRight(struct node* head,int k,int n){

    if(head == NULL || head->next == NULL || k == 0)
        return head;

    k = k % n;

    struct node* temp = head;

    // Move to last node
    while(temp->next != NULL){
        temp = temp->next;
    }

    // Make circular
    temp->next = head;

    int steps = n - k;

    struct node* newTail = head;

    for(int i=1;i<steps;i+=1){
        newTail = newTail->next;
    }

    struct node* newHead = newTail->next;

    newTail->next = NULL;

    return newHead;
}

int main(){

    struct node* head = NULL;

    int n,value,k;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    printf("Enter %d elements:\n",n);

    for(int i=0;i<n;i+=1){

        printf("Enter element %d: ",i+1);
        scanf("%d",&value);

        insertAtEnd(&head,value);
    }

    printf("Enter value of k: ");
    scanf("%d",&k);

    head = rotateRight(head,k,n);

    printf("\nLinked List after rotation:\n");

    displayList(head);

    return 0;
}