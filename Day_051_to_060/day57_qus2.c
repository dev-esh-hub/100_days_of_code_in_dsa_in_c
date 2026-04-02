/*
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

Example 1:


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
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

// Build Tree from level order
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

/**
 * Flatten Function (In-place)
 */
void flatten(struct TreeNode* root) {
    
    struct TreeNode* current = root;

    while (current != NULL) {

        if (current->left != NULL) {

            // Find rightmost of left subtree
            struct TreeNode* temp = current->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }

            // Attach original right subtree
            temp->right = current->right;

            // Move left subtree to right
            current->right = current->left;
            current->left = NULL;
        }

        current = current->right;
    }
}

// Print flattened list (right pointers)
void printFlattened(struct TreeNode* root) {
    printf("\nFlattened Tree (Linked List):\n");

    struct TreeNode* current = root;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->right;
    }
    printf("\n");
}

// Main
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

    // Flatten tree
    flatten(root);

    // Print result
    printFlattened(root);

    return 0;
}