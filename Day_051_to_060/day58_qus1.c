/*
Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.
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

// Search element in inorder
int search(int inorder[], int start, int end, int value){
    for(int i = start; i <= end; i++){
        if(inorder[i] == value){
            return i;
        }
    }
    return -1;
}

// Build Tree
struct node* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex){
    
    if(start > end){
        return NULL;
    }

    int current = preorder[*preIndex];
    *preIndex += 1;

    struct node* root = createNode(current);

    // If only one element
    if(start == end){
        return root;
    }

    int pos = search(inorder, start, end, current);

    // Build Left and Right
    root->left = buildTree(preorder, inorder, start, pos - 1, preIndex);
    root->right = buildTree(preorder, inorder, pos + 1, end, preIndex);

    return root;
}

// Postorder Traversal
void postorder(struct node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

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

    int preIndex = 0;

    struct node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    printf("Postorder traversal: ");
    postorder(root);

    return 0;
}