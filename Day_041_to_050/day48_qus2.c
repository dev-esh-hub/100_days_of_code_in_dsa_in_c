/*
Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
Example 2:

Input: root = [1]
Output: 0
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000
*/

#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate sum of left leaves
int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int sum = 0;

    // Check left child
    if (root->left != NULL) {
        // If left child is a leaf
        if (root->left->left == NULL && root->left->right == NULL) {
            sum += root->left->val;
        } else {
            sum += sumOfLeftLeaves(root->left);
        }
    }

    // Check right subtree
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main() {
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Tree is empty.\n");
        return 0;
    }

    struct TreeNode* nodes[n];

    // Create nodes
    for (int i = 0; i < n; i += 1) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);
        nodes[i] = createNode(value);
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

    struct TreeNode* root = nodes[0];

    int result = sumOfLeftLeaves(root);

    printf("Sum of Left Leaves = %d\n", result);

    return 0;
}