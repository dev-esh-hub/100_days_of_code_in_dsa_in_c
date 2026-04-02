/*
You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

 

Example 1:


Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
Example 2:


Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
Node.val == 0
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

// Queue for level order construction
struct Queue {
    struct TreeNode** arr;
    int front, rear, size;
};

struct Queue* createQueue(int n){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    q->front = 0;
    q->rear = 0;
    q->size = n;
    return q;
}

void enqueue(struct Queue* q, struct TreeNode* node){
    q->arr[q->rear++] = node;
}

struct TreeNode* dequeue(struct Queue* q){
    return q->arr[q->front++];
}

// Build tree from level order (-1 = NULL)
struct TreeNode* buildTree(int arr[], int n){
    
    if(n == 0 || arr[0] == -1){
        return NULL;
    }

    struct TreeNode* root = createNode(arr[0]);

    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int i = 1;

    while(i < n){
        struct TreeNode* curr = dequeue(q);

        // Left child
        if(i < n && arr[i] != -1){
            curr->left = createNode(arr[i]);
            enqueue(q, curr->left);
        }
        i += 1;

        // Right child
        if(i < n && arr[i] != -1){
            curr->right = createNode(arr[i]);
            enqueue(q, curr->right);
        }
        i += 1;
    }

    return root;
}

// Camera Logic
int cameras;

int dfs(struct TreeNode* root){
    
    if(root == NULL){
        return 2; // covered
    }

    int left = dfs(root->left);
    int right = dfs(root->right);

    if(left == 0 || right == 0){
        cameras += 1;
        return 1; // has camera
    }

    if(left == 1 || right == 1){
        return 2; // covered
    }

    return 0; // not covered
}

int minCameraCover(struct TreeNode* root){
    
    cameras = 0; // IMPORTANT FIX

    if(dfs(root) == 0){
        cameras += 1;
    }

    return cameras;
}

// Main
int main(){
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter level order traversal (-1 for NULL): ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    int result = minCameraCover(root);

    printf("Minimum cameras needed: %d", result);

    return 0;
}