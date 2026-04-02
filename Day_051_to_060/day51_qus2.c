/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [2,1], p = 2, q = 1
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the BST.
*/

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Find node pointer by value
struct TreeNode* findNode(struct TreeNode* root, int val) {
    if (root == NULL) return NULL;

    if (root->val == val) return root;

    if (val < root->val) {
        return findNode(root->left, val);
    } else {
        return findNode(root->right, val);
    }
}

// LCA function (iterative)
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {

    while (root != NULL) {

        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        }
        else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        }
        else {
            return root;
        }
    }

    return NULL;
}

int main() {
    int n, i, val;
    struct TreeNode* root = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (i = 0; i < n; i += 1) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    int p_val, q_val;
    printf("Enter values of p and q: ");
    scanf("%d %d", &p_val, &q_val);

    // Find nodes
    struct TreeNode* p = findNode(root, p_val);
    struct TreeNode* q = findNode(root, q_val);

    if (p == NULL || q == NULL) {
        printf("One or both nodes not found in BST\n");
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