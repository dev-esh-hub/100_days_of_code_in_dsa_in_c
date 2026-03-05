/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head) {
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Creating new node:
struct ListNode* createNode(int val){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Printing list:
void printList(struct ListNode* head){
    while(head != NULL){
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main(){
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    printf("Enter values: ");
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

    struct ListNode* mid = middleNode(head);

    printf("Middle onwards: ");
    printList(mid);

    return 0;
}