/*
Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2
*/

#include <stdio.h>
#include <stdlib.h>

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

// Queue for level order construction
struct TreeNode* queue[1000];
int front = 0, rear = 0;

void enqueue(struct TreeNode* node) {
    queue[rear++] = node;
}

struct TreeNode* dequeue() {
    return queue[front++];
}

// Build tree from level order
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        struct TreeNode* current = dequeue();

        // left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(current->left);
        }
        i += 1;

        // right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(current->right);
        }
        i += 1;
    }

    return root;
}

// Find LCA in Binary Tree
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, int p, int q) {
    if (root == NULL) return NULL;

    if (root->val == p || root->val == q) {
        return root;
    }

    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left != NULL && right != NULL) {
        return root;
    }

    if (left != NULL) return left;
    else return right;
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

    int p, q;
    printf("Enter two node values: ");
    scanf("%d %d", &p, &q);

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL) {
        printf("LCA is: %d\n", lca->val);
    } else {
        printf("LCA not found\n");
    }

    return 0;
}