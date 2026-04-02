/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
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

// Recursive Build Function
struct TreeNode* build(int* postorder, int* inorderMap, int start, int end, int* postIndex){
    
    if(start > end){
        return NULL;
    }

    int rootVal = postorder[*postIndex];
    *postIndex -= 1;

    struct TreeNode* root = createNode(rootVal);

    int pos = inorderMap[rootVal + 3000];

    // IMPORTANT: build right first
    root->right = build(postorder, inorderMap, pos + 1, end, postIndex);
    root->left = build(postorder, inorderMap, start, pos - 1, postIndex);

    return root;
}

// Main buildTree function
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    
    int inorderMap[6001]; // range -3000 to 3000

    // Fill map
    for(int i = 0; i < inorderSize; i++){
        inorderMap[inorder[i] + 3000] = i;
    }

    int postIndex = inorderSize - 1;

    return build(postorder, inorderMap, 0, inorderSize - 1, &postIndex);
}

// Preorder traversal (for output)
void preorder(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

// Main function
int main(){
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int inorder[n], postorder[n];

    printf("Enter inorder traversal: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &inorder[i]);
    }

    printf("Enter postorder traversal: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &postorder[i]);
    }

    struct TreeNode* root = buildTree(inorder, n, postorder, n);

    printf("Preorder traversal: ");
    preorder(root);

    return 0;
}