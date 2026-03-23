/*
Problem Statement:
Construct a Binary Tree from the given level-order traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)

Output Format:
- Print inorder traversal of the constructed tree

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
4 2 5 1 3 6
*/

#include <stdio.h>
#include <stdlib.h>

// Tree Node:
struct node {
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node Node;

// Queue for level order construction:
struct queue {
    Node* arr[1000];
    int front, rear;
};

typedef struct queue Queue;

// Queue functions:
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, Node* node) {
    q->arr[q->rear] = node;
    q->rear += 1;
}

Node* dequeue(Queue* q) {
    return q->arr[q->front++];
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build tree from level order:
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    Queue q;
    initQueue(&q);

    Node* root = createNode(arr[0]);
    enqueue(&q, root);

    int i = 1;

    while (i < n && !isEmpty(&q)) {
        Node* current = dequeue(&q);

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(&q, current->left);
        }
        i += 1;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(&q, current->right);
        }
        i += 1;
    }

    return root;
}

// Inorder traversal:
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter level order traversal (-1 for NULL):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, n);

    printf("Inorder Traversal:\n");
    inorder(root);

    return 0;
}