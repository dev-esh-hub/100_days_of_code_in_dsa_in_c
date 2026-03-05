/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Function to append node at the end of the list
struct ListNode* appendNode(struct ListNode* head, int value) {
    struct ListNode* newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    struct ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

void printList(struct ListNode* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Function to remove all nodes with value = val
struct ListNode* removeElements(struct ListNode* head, int val) {
    // Dummy node to handle deletion at head:
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* current = &dummy;
    struct ListNode* temp;

    while (current->next != NULL) {
        if (current->next->val == val) {
            // Node to delete:
            temp = current->next;
            current->next = temp->next;
            free(temp);  // free memory
        } else {
            current = current->next;
        }
    }

    return dummy.next;
}

void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct ListNode* head = NULL;
    int n, value, valToRemove;

    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = appendNode(head, value);
    }

    printf("\nOriginal ");
    printList(head);

    printf("\nEnter value to remove: ");
    scanf("%d", &valToRemove);

    head = removeElements(head, valToRemove);

    printf("\nUpdated ");
    printList(head);

    // Free memory
    freeList(head);

    return 0;
}
