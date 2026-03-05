/*
Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.
*/


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Create new node:
struct node* createNode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Get length of linked list:
int getLength(struct node* head) {
    int length = 0;
    while (head != NULL) {
        length += 1;
        head = head->next;
    }
    return length;
}

// Find intersection node:
struct node* findIntersection(struct node* head1, struct node* head2) {

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff;
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;

    if (len1 > len2) {
        diff = len1 - len2;
        while (diff > 0) {
            ptr1 = ptr1->next;
            diff -= 1;
        }
    } else {
        diff = len2 - len1;
        while (diff > 0) {
            ptr2 = ptr2->next;
            diff -= 1;
        }
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) {
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {

    int n, m, i, value;

    struct node *head1 = NULL, *head2 = NULL;
    struct node *temp = NULL, *last = NULL;

    printf("\nEnter number of nodes in first linked list: ");
    scanf("%d", &n);

    printf("\nEnter elements of first linked list:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        temp = createNode(value);

        if (head1 == NULL) {
            head1 = temp;
        } else {
            last->next = temp;
        }
        last = temp;
    }

    // Store nodes of first list:
    struct node* nodes[1000];
    temp = head1;
    i = 0;
    while (temp != NULL) {
        nodes[i] = temp;
        temp = temp->next;
        i += 1;
    }

    printf("\nEnter number of nodes in second linked list: ");
    scanf("%d", &m);

    printf("\nEnter elements of second linked list:\n");

    last = NULL;

    for (i = 0; i < m; i++) {

        scanf("%d", &value);

        int j;
        int found = 0;

        for (j = 0; j < n; j++) {
            if (nodes[j]->data == value) {

                if (head2 == NULL) {
                    head2 = nodes[j];
                } else {
                    last->next = nodes[j];
                }

                found = 1;
                break;
            }
        }

        if (found == 1) {
            break;
        }

        temp = createNode(value);

        if (head2 == NULL) {
            head2 = temp;
        } else {
            last->next = temp;
        }

        last = temp;
    }

    struct node* intersection = findIntersection(head1, head2);

    printf("\nResult:\n");

    if (intersection != NULL) {
        printf("\nIntersection point is: %d\n", intersection->data);
    } else {
        printf("\nNo Intersection\n");
    }

    return 0;
}