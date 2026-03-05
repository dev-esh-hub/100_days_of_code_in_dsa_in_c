/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

#include<stdio.h>
#include<stdlib.h>

// Node structure
struct ListNode{
    int val;
    struct ListNode* next;
};

// Create new node
struct ListNode* createNode(int data){

    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));

    newnode->val = data;
    newnode->next = NULL;

    return newnode;
}

// Insert at end
void insertAtEnd(struct ListNode** head,int data){

    struct ListNode* newnode = createNode(data);

    if(*head == NULL){
        *head = newnode;
        return;
    }

    struct ListNode* temp = *head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newnode;
}

// Display linked list
void displayList(struct ListNode* head){

    struct ListNode* temp = head;

    while(temp != NULL){
        printf("%d ",temp->val);
        temp = temp->next;
    }

    printf("\n");
}

// Add two numbers using stack method
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    int stack1[200], stack2[200];
    int top1 = -1, top2 = -1;

    while(l1 != NULL){
        stack1[++top1] = l1->val;
        l1 = l1->next;
    }

    while(l2 != NULL){
        stack2[++top2] = l2->val;
        l2 = l2->next;
    }

    int carry = 0;
    struct ListNode* head = NULL;

    while(top1 >= 0 || top2 >= 0 || carry){

        int sum = carry;

        if(top1 >= 0){
            sum += stack1[top1--];
        }

        if(top2 >= 0){
            sum += stack2[top2--];
        }

        struct ListNode* newnode = createNode(sum % 10);

        newnode->next = head;
        head = newnode;

        carry = sum / 10;
    }

    return head;
}

int main(){

    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;
    struct ListNode* result = NULL;

    int n1,n2,value;

    printf("Enter number of nodes in first linked list: ");
    scanf("%d",&n1);

    printf("Enter %d digits for first number:\n",n1);

    for(int i=0;i<n1;i+=1){

        printf("Enter digit %d: ",i+1);
        scanf("%d",&value);

        insertAtEnd(&l1,value);
    }

    printf("\nEnter number of nodes in second linked list: ");
    scanf("%d",&n2);

    printf("Enter %d digits for second number:\n",n2);

    for(int i=0;i<n2;i+=1){

        printf("Enter digit %d: ",i+1);
        scanf("%d",&value);

        insertAtEnd(&l2,value);
    }

    printf("\nFirst Linked List: ");
    displayList(l1);

    printf("Second Linked List: ");
    displayList(l2);

    result = addTwoNumbers(l1,l2);

    printf("\nSum as Linked List: ");
    displayList(result);

    return 0;
}