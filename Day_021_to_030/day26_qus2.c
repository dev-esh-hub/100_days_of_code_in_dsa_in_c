/*
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
 

Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
 

Constraints:

0 <= index, val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

typedef struct {
    struct Node* head;
    int size;
} MyLinkedList;

// Create a new node:
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Initialize linked list:
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

// Get value at index:
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return -1;

    struct Node* temp = obj->head;
    for (int i = 0; i < index; i++)
        temp = temp->next;

    return temp->val;
}

// Add at head:
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct Node* newNode = createNode(val);
    newNode->next = obj->head;
    obj->head = newNode;
    obj->size += 1;
}

// Add at tail:
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct Node* newNode = createNode(val);

    if (obj->head == NULL) {
        obj->head = newNode;
    } else {
        struct Node* temp = obj->head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    obj->size += 1;
}

// Add at index:
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size)
        return;

    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    struct Node* newNode = createNode(val);
    struct Node* temp = obj->head;

    for (int i = 0; i < index - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
    obj->size += 1;
}

// Delete at index:
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return;

    struct Node* temp = obj->head;

    if (index == 0) {
        obj->head = temp->next;
        free(temp);
    } else {
        for (int i = 0; i < index - 1; i++)
            temp = temp->next;

        struct Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        free(nodeToDelete);
    }

    obj->size -= 1;
}

// Free entire list:
void myLinkedListFree(MyLinkedList* obj) {
    struct Node* temp = obj->head;
    while (temp != NULL) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(obj);
}

// Print list:
void printList(MyLinkedList* obj) {
    struct Node* temp = obj->head;
    printf("\nList: ");
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    MyLinkedList* list = myLinkedListCreate();

    myLinkedListAddAtHead(list, 1);
    myLinkedListAddAtTail(list, 3);
    myLinkedListAddAtIndex(list, 1, 2);

    printList(list);

    printf("\nValue at index 1: %d\n", myLinkedListGet(list, 1));

    myLinkedListDeleteAtIndex(list, 1);
    printList(list);

    printf("\nValue at index 1: %d\n", myLinkedListGet(list, 1));

    myLinkedListFree(list);
    return 0;
}