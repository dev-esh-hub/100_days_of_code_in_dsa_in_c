/*
Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous node, forming a loop. Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed otherwise, it will print false.

Examples:

Input: head = 1 -> 3 -> 4, pos = 2
Output: true
Explanation: The linked list looks like

A loop is present in the list, and it is removed.
Input: head = 1 -> 8 -> 3 -> 4, pos = 0
Output: true
Explanation: 

The Linked list does not contains any loop. 
Input: head = 1 -> 2 -> 3 -> 4, pos = 1
Output: true
Explanation: The linked list looks like 

A loop is present in the list, and it is removed.
Constraints:
1 ≤ size of linked list ≤ 105
*/

#include<stdio.h>
#include<stdlib.h>

// Node structure
struct Node{
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data){

    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));

    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

// Insert at end
void insertAtEnd(struct Node** head, int data){

    struct Node* newnode = createNode(data);

    if(*head == NULL){
        *head = newnode;
        return;
    }

    struct Node* temp = *head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newnode;
}

// Display linked list
void displayList(struct Node* head){

    struct Node* temp = head;

    printf("\nLinked List:\n");

    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Detect loop
int detectLoop(struct Node* head){

    struct Node* slow = head;
    struct Node* fast = head;

    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return 1;
        }
    }

    return 0;
}

// Remove loop
void removeLoop(struct Node* head){

    struct Node* slow = head;
    struct Node* fast = head;

    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            break;
        }
    }

    if(fast == NULL || fast->next == NULL){
        return;
    }

    slow = head;

    if(slow == fast){

        while(fast->next != slow){
            fast = fast->next;
        }
    }
    else{

        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
    }

    fast->next = NULL;
}

// Create loop manually
void createLoop(struct Node* head, int pos){

    if(pos < 0){
        return;
    }

    struct Node* temp = head;
    struct Node* loopNode = NULL;

    int index = 0;

    while(temp->next != NULL){

        if(index == pos){
            loopNode = temp;
        }

        temp = temp->next;
        index += 1;
    }

    temp->next = loopNode;
}

int main(){

    struct Node* head = NULL;

    int n;
    int value;
    int pos;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i+=1){

        printf("Enter value: ");
        scanf("%d",&value);

        insertAtEnd(&head,value);
    }

    displayList(head);

    printf("\nEnter position to create loop (-1 for no loop): ");
    scanf("%d",&pos);

    if(pos != -1){
        createLoop(head,pos);
    }

    if(detectLoop(head)){

        printf("\nLoop detected in the linked list.\n");

        removeLoop(head);

        printf("Loop removed successfully.\n");
    }
    else{
        printf("\nNo loop present in the linked list.\n");
    }

    displayList(head);

    return 0;
}