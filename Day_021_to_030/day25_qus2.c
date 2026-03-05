/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// Create a new node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Append node at end
struct ListNode* appendNode(struct ListNode* head, int value) {
    struct ListNode* newNode = createNode(value);
    if (head == NULL)
        return newNode;

    struct ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Create cycle at given position (0-indexed). If pos = -1 → no cycle
void createCycle(struct ListNode* head, int pos) {
    if (pos == -1 || head == NULL)
        return;

    struct ListNode* tail = head;
    struct ListNode* cycleNode = NULL;
    int index = 0;

    while (tail->next != NULL) {
        if (index == pos)
            cycleNode = tail;
        tail = tail->next;
        index++;
    }

    if (index == pos)
        cycleNode = tail;

    if (cycleNode != NULL)
        tail->next = cycleNode;
}

// Detect cycle and return starting node
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL)
        return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Detecting cycle:
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Finding cycle start:
            struct ListNode *entry = head;
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry;
        }
    }

    return NULL;
}

// Print list safely (limit nodes to avoid infinite loop):
void printList(struct ListNode* head) {
    int count = 0;
    while (head != NULL && count < 20) {
        printf("%d -> ", head->val);
        head = head->next;
        count++;
    }
    if (head != NULL)
        printf("... (cycle detected while printing)");
    else
        printf("NULL");
    printf("\n");
}

// Free list (only works safely if no cycle):
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
    int n, value, pos;

    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = appendNode(head, value);
    }

    printf("\nEnter position to create cycle (-1 for no cycle): ");
    scanf("%d", &pos);

    createCycle(head, pos);

    printf("\nChecking for cycle...\n");

    struct ListNode* cycleStart = detectCycle(head);

    if (cycleStart == NULL)
        printf("No cycle detected.\n");
    else
        printf("Cycle starts at node with value: %d\n", cycleStart->val);

    // Only free if no cycle:
    if (cycleStart == NULL)
        freeList(head);

    return 0;
}