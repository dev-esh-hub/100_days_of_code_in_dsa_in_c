/*
Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.
*/

#include <stdio.h>
#include <stdlib.h>

// Node for linked list (bucket)
struct Node {
    float val;
    struct Node* next;
};

// Insert node in sorted order (for each bucket)
struct Node* sortedInsert(struct Node* head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->next = NULL;

    // insert at beginning or empty list
    if (head == NULL || value < head->val) {
        newNode->next = head;
        return newNode;
    }

    struct Node* curr = head;
    while (curr->next != NULL && curr->next->val <= value) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

// Bucket Sort function
void bucketSort(float arr[], int n) {

    // Create n buckets (array of linked lists)
    struct Node* buckets[n];

    // Initialize buckets
    for (int i = 0; i < n; i += 1) {
        buckets[i] = NULL;
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i += 1) {
        int index = (int)(arr[i] * n);  // bucket index
        buckets[index] = sortedInsert(buckets[index], arr[i]);
    }

    // Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i += 1) {
        struct Node* curr = buckets[i];

        while (curr != NULL) {
            arr[k++] = curr->val;
            curr = curr->next;
        }
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];

    printf("Enter elements (in range [0,1)):\n");
    for (int i = 0; i < n; i += 1) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i += 1) {
        printf("%.3f ", arr[i]);
    }

    return 0;
}