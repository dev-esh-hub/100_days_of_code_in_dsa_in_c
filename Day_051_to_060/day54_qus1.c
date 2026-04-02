/*
Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.
*/

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create Node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build tree from level order array
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = createNode(arr[0]);

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n && front < rear) {
        struct TreeNode* current = queue[front++];

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i += 1;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i += 1;
    }

    return root;
}

// Zigzag Traversal
void zigzagTraversal(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int leftToRight = 1;  // direction flag

    while (front < rear) {
        int levelSize = rear - front;

        int temp[levelSize];

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* current = queue[front++];

            int index;
            if (leftToRight == 1) {
                index = i;
            } else {
                index = levelSize - 1 - i;
            }

            temp[index] = current->val;

            if (current->left != NULL)
                queue[rear++] = current->left;

            if (current->right != NULL)
                queue[rear++] = current->right;
        }

        // Print current level
        for (int i = 0; i < levelSize; i++) {
            printf("%d ", temp[i]);
        }

        // Toggle direction
        leftToRight = !leftToRight;
    }
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter level order traversal (-1 for NULL):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    printf("\nZigzag Traversal:\n");
    zigzagTraversal(root);

    return 0;
}