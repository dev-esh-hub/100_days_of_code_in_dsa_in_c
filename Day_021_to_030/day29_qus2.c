/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

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

// Add two numbers
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    struct ListNode* result = NULL;
    struct ListNode* tail = NULL;

    int carry = 0;

    while(l1 != NULL || l2 != NULL || carry != 0){

        int sum = carry;

        if(l1 != NULL){
            sum += l1->val;
            l1 = l1->next;
        }

        if(l2 != NULL){
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        struct ListNode* newnode = createNode(sum % 10);

        if(result == NULL){
            result = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }

    return result;
}

int main(){

    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;
    struct ListNode* result = NULL;

    int n1,n2,value;

    printf("Enter number of nodes in first linked list: ");
    scanf("%d",&n1);

    printf("Enter %d digits for first number (reverse order):\n",n1);

    for(int i=0;i<n1;i+=1){

        printf("Enter digit %d: ",i+1);
        scanf("%d",&value);

        insertAtEnd(&l1,value);
    }

    printf("\nEnter number of nodes in second linked list: ");
    scanf("%d",&n2);

    printf("Enter %d digits for second number (reverse order):\n",n2);

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