/*
Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for interval
struct Interval {
    int start;
    int end;
};

// Compare function for sorting by start time
int compare(const void* a, const void* b) {
    struct Interval* x = (struct Interval*)a;
    struct Interval* y = (struct Interval*)b;
    return x->start - y->start;
}

// Min Heap functions
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else break;
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else break;
    }
}

// Insert into heap
void push(int heap[], int* size, int value) {
    heap[*size] = value;
    *size += 1;
    heapifyUp(heap, *size - 1);
}

// Remove min (top)
int pop(int heap[], int* size) {
    int top = heap[0];
    heap[0] = heap[*size - 1];
    *size -= 1;
    heapifyDown(heap, *size, 0);
    return top;
}

// Get minimum element
int top(int heap[]) {
    return heap[0];
}

// Main function
int minMeetingRooms(struct Interval intervals[], int n) {
    if (n == 0) return 0;

    // Step 1: sort by start time
    qsort(intervals, n, sizeof(struct Interval), compare);

    int heap[n];
    int size = 0;

    // First meeting
    push(heap, &size, intervals[0].end);

    for (int i = 1; i < n; i += 1) {
        // If room is free
        if (intervals[i].start >= top(heap)) {
            pop(heap, &size);
        }

        // Allocate room (push end time)
        push(heap, &size, intervals[i].end);
    }

    return size;
}

int main() {
    int n;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    struct Interval intervals[n];

    printf("Enter start and end times:\n");
    for (int i = 0; i < n; i += 1) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    int result = minMeetingRooms(intervals, n);

    printf("Minimum number of rooms required: %d\n", result);

    return 0;
}