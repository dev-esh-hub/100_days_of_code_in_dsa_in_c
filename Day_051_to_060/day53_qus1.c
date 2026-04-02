/*
Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Queue for tree construction
struct TreeNode* queue[MAX];
int front = 0, rear = 0;

void enqueue(struct TreeNode* node) {
    queue[rear++] = node;
}

struct TreeNode* dequeue() {
    return queue[front++];
}

// Build tree
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        struct TreeNode* curr = dequeue();

        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i += 1;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i += 1;
    }

    return root;
}

// Structure for BFS with HD
struct Pair {
    struct TreeNode* node;
    int hd;
};

// Queue for vertical traversal
struct Pair q[MAX];
int f = 0, r = 0;

void push(struct TreeNode* node, int hd) {
    q[r].node = node;
    q[r].hd = hd;
    r += 1;
}

struct Pair pop() {
    return q[f++];
}

// Vertical Order Traversal
void verticalOrder(struct TreeNode* root) {
    if (root == NULL) return;

    // HD range assumption (-500 to +500)
    int offset = 500;
    int map[1000][1000];  // store values
    int count[1000] = {0};

    push(root, 0);

    int minHD = 0, maxHD = 0;

    while (f < r) {
        struct Pair temp = pop();
        struct TreeNode* node = temp.node;
        int hd = temp.hd;

        int index = hd + offset;

        map[index][count[index]++] = node->val;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left != NULL) {
            push(node->left, hd - 1);
        }
        if (node->right != NULL) {
            push(node->right, hd + 1);
        }
    }

    // Print result
    for (int i = minHD; i <= maxHD; i += 1) {
        int index = i + offset;
        for (int j = 0; j < count[index]; j += 1) {
            printf("%d ", map[index][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level order values (-1 for NULL):\n");
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    printf("Vertical Order Traversal:\n");
    verticalOrder(root);

    return 0;
}