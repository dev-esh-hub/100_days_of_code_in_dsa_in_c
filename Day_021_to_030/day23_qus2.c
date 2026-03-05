/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next; 
        fast = fast->next->next; 

        if(slow == fast){
            return true;
        }
    }

    return false;
}

struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, pos;

    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    if(n <= 0){
        printf("\nEmpty list\n");
        return 0;
    }

    struct ListNode *head = NULL, *temp = NULL, *cycleNode = NULL;

    printf("\nEnter %d values:\n", n);
    for(int i = 0; i < n; i += 1) {
        int value;
        scanf("%d", &value);

        struct ListNode* newNode = createNode(value);

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }

        if(i == 0) cycleNode = head;
    }

    printf("\nEnter position to create cycle (-1 for no cycle): ");
    scanf("%d", &pos);

    // Creating cycle if pos is valid:
    if(pos >= 0 && pos < n) {
        struct ListNode* target = head;
        for(int i = 0; i < pos; i += 1) {
            target = target->next;
        }
        temp->next = target;
    }

    // Checking cycle:
    if(hasCycle(head)) {
        printf("\nCycle detected\n");
    } else {
        printf("\nNo cycle\n");
    }

    return 0;
}