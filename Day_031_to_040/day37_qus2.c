/*
You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
 

Example 1:

Input:
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

Output: [null, 4, 5, 5, 8, 8]

Explanation:

KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3); // return 4
kthLargest.add(5); // return 5
kthLargest.add(10); // return 5
kthLargest.add(9); // return 8
kthLargest.add(4); // return 8

Example 2:

Input:
["KthLargest", "add", "add", "add", "add"]
[[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]

Output: [null, 7, 7, 7, 8]

Explanation:

KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);
kthLargest.add(2); // return 7
kthLargest.add(10); // return 7
kthLargest.add(9); // return 7
kthLargest.add(9); // return 8
 

Constraints:

0 <= nums.length <= 104
1 <= k <= nums.length + 1
-104 <= nums[i] <= 104
-104 <= val <= 104
At most 104 calls will be made to add.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *heap;
    int size;
    int capacity;
    int k;
} KthLargest;

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(KthLargest* obj, int i){
    while(i > 0){
        int parent = (i - 1) / 2;
        if(obj->heap[parent] <= obj->heap[i])
            break;

        swap(&obj->heap[parent], &obj->heap[i]);
        i = parent;
    }
}

void heapifyDown(KthLargest* obj, int i){
    while(1){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < obj->size && obj->heap[left] < obj->heap[smallest])
            smallest = left;

        if(right < obj->size && obj->heap[right] < obj->heap[smallest])
            smallest = right;

        if(smallest == i)
            break;

        swap(&obj->heap[i], &obj->heap[smallest]);
        i = smallest;
    }
}

void push(KthLargest* obj, int val){
    obj->heap[obj->size] = val;
    heapifyUp(obj, obj->size);
    obj->size++;
}

void pop(KthLargest* obj){
    obj->heap[0] = obj->heap[obj->size - 1];
    obj->size--;
    heapifyDown(obj, 0);
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize){

    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));

    obj->heap = (int*)malloc(sizeof(int) * 10000);
    obj->size = 0;
    obj->capacity = 10000;
    obj->k = k;

    for(int i = 0; i < numsSize; i++){
        push(obj, nums[i]);
        if(obj->size > k)
            pop(obj);
    }

    return obj;
}

int kthLargestAdd(KthLargest* obj, int val){

    push(obj, val);

    if(obj->size > obj->k)
        pop(obj);

    return obj->heap[0];
}

void kthLargestFree(KthLargest* obj){
    free(obj->heap);
    free(obj);
}

int main(){

    int k, n;

    printf("Enter value of k: ");
    scanf("%d", &k);

    printf("Enter number of initial scores: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter the initial scores:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }

    KthLargest* obj = kthLargestCreate(k, nums, n);

    int q;
    printf("Enter number of new scores to add: ");
    scanf("%d", &q);

    for(int i = 0; i < q; i++){

        int val;
        printf("Enter new score: ");
        scanf("%d", &val);

        int ans = kthLargestAdd(obj, val);

        printf("Current %d-th largest score: %d\n", k, ans);
    }

    kthLargestFree(obj);

    return 0;
}