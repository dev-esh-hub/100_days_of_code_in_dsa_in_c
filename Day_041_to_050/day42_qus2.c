/*
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.
*/

#include <stdio.h>
#include <stdlib.h>

// ---------- Heap Structures ----------

typedef struct {
    int* arr;
    int size;
} MaxHeap;

typedef struct {
    int* arr;
    int size;
} MinHeap;

typedef struct {
    MaxHeap* left;   // max heap
    MinHeap* right;  // min heap
} MedianFinder;

// ---------- Utility ----------
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ---------- Max Heap ----------
void maxHeapifyUp(MaxHeap* h, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->arr[parent] >= h->arr[i]) break;
        swap(&h->arr[parent], &h->arr[i]);
        i = parent;
    }
}

void maxHeapifyDown(MaxHeap* h, int i) {
    while (1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;

        if (left < h->size && h->arr[left] > h->arr[largest])
            largest = left;
        if (right < h->size && h->arr[right] > h->arr[largest])
            largest = right;

        if (largest == i) break;

        swap(&h->arr[i], &h->arr[largest]);
        i = largest;
    }
}

void maxHeapPush(MaxHeap* h, int val) {
    h->arr[h->size] = val;
    h->size += 1;
    maxHeapifyUp(h, h->size - 1);
}

int maxHeapPop(MaxHeap* h) {
    int val = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size -= 1;
    maxHeapifyDown(h, 0);
    return val;
}

int maxHeapTop(MaxHeap* h) {
    return h->arr[0];
}

// ---------- Min Heap ----------
void minHeapifyUp(MinHeap* h, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->arr[parent] <= h->arr[i]) break;
        swap(&h->arr[parent], &h->arr[i]);
        i = parent;
    }
}

void minHeapifyDown(MinHeap* h, int i) {
    while (1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if (left < h->size && h->arr[left] < h->arr[smallest])
            smallest = left;
        if (right < h->size && h->arr[right] < h->arr[smallest])
            smallest = right;

        if (smallest == i) break;

        swap(&h->arr[i], &h->arr[smallest]);
        i = smallest;
    }
}

void minHeapPush(MinHeap* h, int val) {
    h->arr[h->size] = val;
    h->size += 1;
    minHeapifyUp(h, h->size - 1);
}

int minHeapPop(MinHeap* h) {
    int val = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size -= 1;
    minHeapifyDown(h, 0);
    return val;
}

int minHeapTop(MinHeap* h) {
    return h->arr[0];
}

// ---------- MedianFinder ----------

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));

    obj->left = (MaxHeap*)malloc(sizeof(MaxHeap));
    obj->right = (MinHeap*)malloc(sizeof(MinHeap));

    obj->left->arr = (int*)malloc(50000 * sizeof(int));
    obj->right->arr = (int*)malloc(50000 * sizeof(int));

    obj->left->size = 0;
    obj->right->size = 0;

    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    maxHeapPush(obj->left, num);
    minHeapPush(obj->right, maxHeapPop(obj->left));

    if (obj->right->size > obj->left->size) {
        maxHeapPush(obj->left, minHeapPop(obj->right));
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->left->size > obj->right->size) {
        return (double)maxHeapTop(obj->left);
    } else {
        return (maxHeapTop(obj->left) + minHeapTop(obj->right)) / 2.0;
    }
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->left->arr);
    free(obj->right->arr);
    free(obj->left);
    free(obj->right);
    free(obj);
}

// ---------- Main Function ----------

int main() {
    MedianFinder* obj = medianFinderCreate();

    int q;
    printf("Enter number of operations: ");
    scanf("%d", &q);

    printf("Operations:\n1 x -> add number\n2 -> find median\n");

    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int num;
            scanf("%d", &num);
            medianFinderAddNum(obj, num);
        } 
        else if (type == 2) {
            double median = medianFinderFindMedian(obj);
            printf("Median: %.5lf\n", median);
        }
    }

    medianFinderFree(obj);
    return 0;
}