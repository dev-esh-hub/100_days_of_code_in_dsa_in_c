/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

// Insert node at end
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

    printf("\nLinked List:\n");

    while(temp != NULL){
        printf("%d -> ",temp->val);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Reverse linked list
struct ListNode* reverse(struct ListNode* head){

    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while(curr != NULL){

        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// Check palindrome
bool isPalindrome(struct ListNode* head){

    if(head == NULL || head->next == NULL)
        return true;

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    // Find middle
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct ListNode* second = reverse(slow->next);

    struct ListNode* first = head;

    // Compare halves
    while(second != NULL){

        if(first->val != second->val)
            return false;

        first = first->next;
        second = second->next;
    }

    return true;
}

int main(){

    struct ListNode* head = NULL;

    int n,value;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    printf("Enter %d elements:\n",n);

    for(int i=0;i<n;i+=1){

        printf("Enter element %d: ",i+1);
        scanf("%d",&value);

        insertAtEnd(&head,value);
    }

    displayList(head);

    if(isPalindrome(head)){
        printf("\nThe linked list is a Palindrome.\n");
    }
    else{
        printf("\nThe linked list is NOT a Palindrome.\n");
    }

    return 0;
}
