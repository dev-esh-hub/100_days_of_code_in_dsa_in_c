/*
Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.
*/

#include<stdio.h>
#include<stdlib.h>

// Node structure for polynomial term
struct node{
    int coeff;
    int exp;
    struct node* next;
};

// Function to create new node
struct node* createNode(int coeff, int exp){

    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->next = NULL;

    return newnode;
}

// Function to insert term at end
void insertTerm(struct node** head,int coeff,int exp){

    struct node* newnode = createNode(coeff,exp);

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

// Function to display polynomial
void displayPolynomial(struct node* head){

    struct node* temp = head;

    printf("\nPolynomial:\n");

    while(temp != NULL){

        if(temp->exp == 0){
            printf("%d",temp->coeff);
        }
        else if(temp->exp == 1){
            printf("%dx",temp->coeff);
        }
        else{
            printf("%dx^%d",temp->coeff,temp->exp);
        }

        if(temp->next != NULL){
            printf(" + ");
        }

        temp = temp->next;
    }

    printf("\n");
}

int main(){

    struct node* head = NULL;

    int n,coeff,exp;

    printf("Enter number of terms in polynomial: ");
    scanf("%d",&n);

    printf("Enter coefficient and exponent for each term:\n");

    for(int i=0;i<n;i+=1){

        printf("Enter coefficient for term %d: ",i+1);
        scanf("%d",&coeff);

        printf("Enter exponent for term %d: ",i+1);
        scanf("%d",&exp);

        insertTerm(&head,coeff,exp);
    }

    displayPolynomial(head);

    return 0;
}