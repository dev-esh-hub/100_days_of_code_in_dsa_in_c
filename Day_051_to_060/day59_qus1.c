/*
Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.
*/

#include<stdio.h>
#include<stdlib.h>

// Tree Node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create Node
struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build Tree (recursive)
struct node* build(int inorder[], int inorderMap[], int start, int end, int* postIndex, int postorder[]){
    
    if(start > end){
        return NULL;
    }

    int rootVal = postorder[*postIndex];
    *postIndex -= 1;

    struct node* root = createNode(rootVal);

    int pos = inorderMap[rootVal + 3000];

    // IMPORTANT: build right first
    root->right = build(inorder, inorderMap, pos + 1, end, postIndex, postorder);
    root->left = build(inorder, inorderMap, start, pos - 1, postIndex, postorder);

    return root;
}

// Main builder
struct node* buildTree(int inorder[], int postorder[], int n){
    
    int inorderMap[6001];

    for(int i = 0; i < n; i++){
        inorderMap[inorder[i] + 3000] = i;
    }

    int postIndex = n - 1;

    return build(inorder, inorderMap, 0, n - 1, &postIndex, postorder);
}

// Preorder traversal (output)
void preorder(struct node* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
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

    struct node* root = buildTree(inorder, postorder, n);

    printf("Preorder traversal: ");
    preorder(root);

    return 0;
}