/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    
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

struct ListNode* createNode(int val){
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void printList(struct ListNode* head){
    while(head != NULL){
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main(){
    int n, x;
    scanf("%d", &n);

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    for(int i = 0; i < n; i += 1){
        scanf("%d", &x);
        struct ListNode* newNode = createNode(x);

        if(head == NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = reverseList(head);
    printList(head);

    return 0;
}