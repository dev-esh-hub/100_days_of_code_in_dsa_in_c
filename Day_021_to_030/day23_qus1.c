/*
Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

// Merging two sorted lists:
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node* mergedHead = NULL;
    struct Node* mergedTail = NULL;

    while (head1 != NULL && head2 != NULL) {
        struct Node* newNode;

        if (head1->data < head2->data) {
            newNode = createNode(head1->data);
            head1 = head1->next;
        } else {
            newNode = createNode(head2->data);
            head2 = head2->next;
        }

        if (mergedHead == NULL) {
            mergedHead = mergedTail = newNode;
        } else {
            mergedTail->next = newNode;
            mergedTail = newNode;
        }
    }

    // Remaining nodes:
    while (head1 != NULL) {
        mergedTail->next = createNode(head1->data);
        mergedTail = mergedTail->next;
        head1 = head1->next;
    }

    while (head2 != NULL) {
        mergedTail->next = createNode(head2->data);
        mergedTail = mergedTail->next;
        head2 = head2->next;
    }

    return mergedHead;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, m, value;
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    printf("\nEnter number of elements in first sorted list: ");
    scanf("%d", &n);

    printf("\nEnter %d elements (sorted): ", n);
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &value);
        list1 = insertAtEnd(list1, value);
    }

    printf("\nEnter number of elements in second sorted list: ");
    scanf("%d", &m);

    printf("\nEnter %d elements (sorted): ", m);
    for (int i = 0; i < m; i += 1) {
        scanf("%d", &value);
        list2 = insertAtEnd(list2, value);
    }

    // Merge lists:
    struct Node* mergedList = mergeLists(list1, list2);

    printf("\nMerged Sorted List: ");
    displayList(mergedList);

    return 0;
}