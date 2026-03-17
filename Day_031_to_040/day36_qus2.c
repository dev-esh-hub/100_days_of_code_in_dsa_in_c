/*
Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
 

Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
 

Constraints:

1 <= k <= 1000
0 <= value <= 1000
At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));

    obj->capacity = k;
    obj->arr = (int*)malloc(sizeof(int) * k);
    obj->front = 0;
    obj->rear = -1;
    obj->size = 0;

    return obj;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if(obj->size == obj->capacity)
        return false;

    obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    obj->arr[obj->front] = value;
    obj->size++;

    if(obj->size == 1)
        obj->rear = obj->front;

    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if(obj->size == obj->capacity)
        return false;

    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->arr[obj->rear] = value;
    obj->size++;

    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if(obj->size == 0)
        return false;

    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if(obj->size == 0)
        return false;

    obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    obj->size--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if(obj->size == 0)
        return -1;

    return obj->arr[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if(obj->size == 0)
        return -1;

    return obj->arr[obj->rear];
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->capacity;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->arr);
    free(obj);
}

int main() {
    int k;
    printf("Enter size of deque: ");
    scanf("%d", &k);

    MyCircularDeque* dq = myCircularDequeCreate(k);

    int choice, value;

    while(1) {
        printf("\n1 Insert Front");
        printf("\n2 Insert Last");
        printf("\n3 Delete Front");
        printf("\n4 Delete Last");
        printf("\n5 Get Front");
        printf("\n6 Get Rear");
        printf("\n7 Check Empty");
        printf("\n8 Check Full");
        printf("\n9 Exit");
        printf("\nEnter choice: ");

        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                if(myCircularDequeInsertFront(dq, value))
                    printf("Inserted at front\n");
                else
                    printf("Deque is full\n");
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                if(myCircularDequeInsertLast(dq, value))
                    printf("Inserted at rear\n");
                else
                    printf("Deque is full\n");
                break;

            case 3:
                if(myCircularDequeDeleteFront(dq))
                    printf("Deleted from front\n");
                else
                    printf("Deque is empty\n");
                break;

            case 4:
                if(myCircularDequeDeleteLast(dq))
                    printf("Deleted from rear\n");
                else
                    printf("Deque is empty\n");
                break;

            case 5:
                printf("Front element: %d\n", myCircularDequeGetFront(dq));
                break;

            case 6:
                printf("Rear element: %d\n", myCircularDequeGetRear(dq));
                break;

            case 7:
                if(myCircularDequeIsEmpty(dq))
                    printf("Deque is empty\n");
                else
                    printf("Deque is not empty\n");
                break;

            case 8:
                if(myCircularDequeIsFull(dq))
                    printf("Deque is full\n");
                else
                    printf("Deque is not full\n");
                break;

            case 9:
                myCircularDequeFree(dq);
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}