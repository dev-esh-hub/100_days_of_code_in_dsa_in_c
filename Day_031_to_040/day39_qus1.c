/*
Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30
*/

#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

// Swaping:
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up:
void heapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent] > heap[i]) {
            swap(&heap[parent], &heap[i]);
            i = parent;
        } else {
            break;
        }
    }
}

// Heapify Down:
void heapifyDown(int i) {
    while (1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}

// Inserting:
void insert(int x) {
    if (size == MAX) {
        printf("Heap Overflow\n");
        return;
    }

    heap[size] = x;
    heapifyUp(size);
    size += 1;
}

// Peek:
int peek() {
    if (size == 0) return -1;
    return heap[0];
}

// Extract Minimum:
int extractMin() {
    if (size == 0) return -1;

    int min = heap[0];
    heap[0] = heap[size - 1];
    size -= 1;

    heapifyDown(0);

    return min;
}

int main() {
    int n;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        char op[20];

        printf("Enter operation (insert x / peek / extractMin): ");
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(op, "peek") == 0) {
            int res = peek();
            if (res == -1)
                printf("Heap is empty\n");
            else
                printf("Minimum element: %d\n", res);
        }
        else if (strcmp(op, "extractMin") == 0) {
            int res = extractMin();
            if (res == -1)
                printf("Heap is empty\n");
            else
                printf("Extracted Min: %d\n", res);
        }
        else {
            printf("Invalid operation\n");
        }
    }

    return 0;
}