/*
Problem: Count Nodes in Linked List

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

// Creating new node:
struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Counting nodes:
int countNodes(struct node* head){
    int count = 0;
    while(head != NULL){
        count += 1;
        head = head->next;
    }
    return count;
}

int main(){
    int n, x;
    scanf("%d", &n);

    struct node* head = NULL;
    struct node* tail = NULL;

    for(int i = 0; i < n; i += 1){
        scanf("%d", &x);
        struct node* newNode = createNode(x);

        if(head == NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Total nodes = %d", countNodes(head));

    return 0;
}