/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
*/

#include<stdio.h>
#include<stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create Node
struct TreeNode* createNode(int val){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Recursive build function
struct TreeNode* build(int* preorder, int* inorderMap, int start, int end, int* preIndex){
    
    if(start > end){
        return NULL;
    }

    int rootVal = preorder[*preIndex];
    *preIndex += 1;

    struct TreeNode* root = createNode(rootVal);

    int pos = inorderMap[rootVal + 3000];

    root->left = build(preorder, inorderMap, start, pos - 1, preIndex);
    root->right = build(preorder, inorderMap, pos + 1, end, preIndex);

    return root;
}

// Main buildTree function
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    
    int inorderMap[6001]; // values range: -3000 to 3000

    // Fill map
    for(int i = 0; i < inorderSize; i++){
        inorderMap[inorder[i] + 3000] = i;
    }

    int preIndex = 0;

    return build(preorder, inorderMap, 0, inorderSize - 1, &preIndex);
}

// Postorder Traversal (for output)
void postorder(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

// Main function
int main(){
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int preorder[n], inorder[n];

    printf("Enter preorder traversal: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &preorder[i]);
    }

    printf("Enter inorder traversal: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &inorder[i]);
    }

    struct TreeNode* root = buildTree(preorder, n, inorder, n);

    printf("Postorder traversal: ");
    postorder(root);

    return 0;
}