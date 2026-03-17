/*
Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations
*/

#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

// Check empty:
int empty() {
    return (front == -1);
}

// Check Size:
int size() {
    if(front == -1)
        return 0;
    return rear - front + 1;
}

// Push front:
void push_front(int value) {
    if(front == 0) {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1) {
        front = rear = 0;
    }
    else {
        front--;
    }

    deque[front] = value;
    printf("Inserted %d at front\n", value);
}

// Push Back:
void push_back(int value) {
    if(rear == MAX-1) {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1) {
        front = rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = value;
    printf("Inserted %d at rear\n", value);
}

// Pop front:
void pop_front() {
    if(empty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Removed element: %d\n", deque[front]);

    if(front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }
}

// Pop Rear:
void pop_back() {
    if(empty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Removed element: %d\n", deque[rear]);

    if(front == rear) {
        front = rear = -1;
    }
    else {
        rear--;
    }
}

// Front element:
void get_front() {
    if(empty())
        printf("Deque is empty\n");
    else
        printf("Front element: %d\n", deque[front]);
}

// Rear element:
void get_back() {
    if(empty())
        printf("Deque is empty\n");
    else
        printf("Rear element: %d\n", deque[rear]);
}

// Clear Dequeue:
void clear() {
    front = rear = -1;
    printf("Deque cleared\n");
}

// Display:
void display() {
    if(empty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");

    for(int i = front; i <= rear; i++)
        printf("%d ", deque[i]);

    printf("\n");
}

// Reverse:
void reverse() {
    if(empty()) return;

    int i = front, j = rear;

    while(i < j) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }

    printf("Deque reversed\n");
}

// Sort:
void sort() {
    if(empty()) return;

    for(int i = front; i <= rear; i++) {
        for(int j = i+1; j <= rear; j++) {
            if(deque[i] > deque[j]) {
                int temp = deque[i];
                deque[i] = deque[j];
                deque[j] = temp;
            }
        }
    }

    printf("Deque sorted in ascending order\n");
}

int main() {

    int choice, value;

    while(1) {

        printf("\n------ Deque Menu ------\n");
        printf("1 Push Front\n");
        printf("2 Push Back\n");
        printf("3 Pop Front\n");
        printf("4 Pop Back\n");
        printf("5 Front\n");
        printf("6 Back\n");
        printf("7 Size\n");
        printf("8 Empty\n");
        printf("9 Clear\n");
        printf("10 Reverse\n");
        printf("11 Sort\n");
        printf("12 Display\n");
        printf("13 Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push_front(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                push_back(value);
                break;

            case 3:
                pop_front();
                break;

            case 4:
                pop_back();
                break;

            case 5:
                get_front();
                break;

            case 6:
                get_back();
                break;

            case 7:
                printf("Size of deque: %d\n", size());
                break;

            case 8:
                if(empty())
                    printf("Deque is empty\n");
                else
                    printf("Deque is not empty\n");
                break;

            case 9:
                clear();
                break;

            case 10:
                reverse();
                break;

            case 11:
                sort();
                break;

            case 12:
                display();
                break;

            case 13:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}