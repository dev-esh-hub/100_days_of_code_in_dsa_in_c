/*
Problem: Count Leaf Nodes

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
*/

#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Tree is empty.\n");
        return 0;
    }

    struct Node* nodes[n];

    // Create nodes
    for (int i = 0; i < n; i += 1) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &val);
        nodes[i] = createNode(val);
    }

    // Link nodes
    for (int i = 0; i < n; i += 1) {
        int leftIndex, rightIndex;

        printf("Enter left child index of node %d (-1 for NULL): ", i);
        scanf("%d", &leftIndex);

        printf("Enter right child index of node %d (-1 for NULL): ", i);
        scanf("%d", &rightIndex);

        if (leftIndex != -1)
            nodes[i]->left = nodes[leftIndex];

        if (rightIndex != -1)
            nodes[i]->right = nodes[rightIndex];
    }

    struct Node* root = nodes[0];

    int leafCount = countLeafNodes(root);

    printf("Total Leaf Nodes = %d\n", leafCount);

    return 0;
}