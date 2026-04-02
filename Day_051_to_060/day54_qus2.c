/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
*/

#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create new node
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

// Zigzag Level Order Traversal (LeetCode style)
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    
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
    int leftToRight = 1;

    while (front < rear) {
        int levelSize = rear - front;

        result[levelIndex] = (int*)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[levelIndex] = levelSize;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* current = queue[front++];

            int index;
            if (leftToRight == 1)
                index = i;
            else
                index = levelSize - 1 - i;

            result[levelIndex][index] = current->val;

            if (current->left != NULL)
                queue[rear++] = current->left;

            if (current->right != NULL)
                queue[rear++] = current->right;
        }

        leftToRight = !leftToRight;
        levelIndex += 1;
    }

    *returnSize = levelIndex;
    return result;
}

// Print result
void printResult(int** result, int returnSize, int* returnColumnSizes) {
    printf("\nZigzag Level Order Traversal:\n");

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
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter level order traversal (-1 for NULL):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    int returnSize;
    int* returnColumnSizes;

    int** result = zigzagLevelOrder(root, &returnSize, &returnColumnSizes);

    printResult(result, returnSize, returnColumnSizes);

    return 0;
}