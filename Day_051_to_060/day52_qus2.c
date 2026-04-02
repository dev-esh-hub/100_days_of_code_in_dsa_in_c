/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.
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

// Queue for level order
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
        struct TreeNode* curr = dequeue();

        // left child
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i += 1;

        // right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i += 1;
    }

    return root;
}

// Find node pointer by value
struct TreeNode* findNode(struct TreeNode* root, int val) {
    if (root == NULL) return NULL;

    if (root->val == val) return root;

    struct TreeNode* left = findNode(root->left, val);
    if (left != NULL) return left;

    return findNode(root->right, val);
}

// LCA function
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    
    if (root == NULL) return NULL;

    if (root == p || root == q) {
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

    int p_val, q_val;
    printf("Enter values of p and q: ");
    scanf("%d %d", &p_val, &q_val);

    // find node pointers
    struct TreeNode* p = findNode(root, p_val);
    struct TreeNode* q = findNode(root, q_val);

    if (p == NULL || q == NULL) {
        printf("One or both nodes not found\n");
        return 0;
    }

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL) {
        printf("LCA is: %d\n", lca->val);
    } else {
        printf("LCA not found\n");
    }

    return 0;
}