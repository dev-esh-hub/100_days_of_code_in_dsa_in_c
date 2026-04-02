/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/

#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build tree using level order input
struct TreeNode* buildTree() {
    int val;
    printf("Enter root value (-1 for NULL): ");
    scanf("%d", &val);

    if (val == -1) return NULL;

    struct TreeNode* root = createNode(val);

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* current = queue[front++];

        int leftVal, rightVal;

        printf("Enter left child of %d (-1 for NULL): ", current->val);
        scanf("%d", &leftVal);

        if (leftVal != -1) {
            current->left = createNode(leftVal);
            queue[rear++] = current->left;
        }

        printf("Enter right child of %d (-1 for NULL): ", current->val);
        scanf("%d", &rightVal);

        if (rightVal != -1) {
            current->right = createNode(rightVal);
            queue[rear++] = current->right;
        }
    }

    return root;
}

/**
 * Level Order Traversal Function
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int levelIndex = 0;

    while (front < rear) {
        int levelSize = rear - front;

        result[levelIndex] = (int*)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[levelIndex] = levelSize;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* current = queue[front++];

            result[levelIndex][i] = current->val;

            if (current->left != NULL)
                queue[rear++] = current->left;

            if (current->right != NULL)
                queue[rear++] = current->right;
        }

        levelIndex += 1;
    }

    *returnSize = levelIndex;
    return result;
}

// Function to print result
void printLevelOrder(int** result, int returnSize, int* returnColumnSizes) {
    printf("\nLevel Order Traversal:\n");

    for (int i = 0; i < returnSize; i++) {
        printf("[ ");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("]\n");
    }
}

// Main function
int main() {
    int returnSize;
    int* returnColumnSizes;

    printf("=== Build Binary Tree ===\n");
    struct TreeNode* root = buildTree();

    int** result = levelOrder(root, &returnSize, &returnColumnSizes);

    printLevelOrder(result, returnSize, returnColumnSizes);

    return 0;
}