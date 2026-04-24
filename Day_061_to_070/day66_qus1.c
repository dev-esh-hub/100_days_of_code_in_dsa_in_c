/*
Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

// Adjacency list node
struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];
int recStack[MAX];

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (directed)
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS function
int dfs(int node) {

    visited[node] = 1;
    recStack[node] = 1;

    struct Node* temp = adj[node];

    while(temp != NULL) {
        int neighbor = temp->data;

        // If not visited → DFS
        if(!visited[neighbor]) {
            if(dfs(neighbor)) {
                return 1;
            }
        }
        // If in recursion stack → cycle
        else if(recStack[neighbor]) {
            return 1;
        }

        temp = temp->next;
    }

    recStack[node] = 0; // backtrack
    return 0;
}

// Function to check cycle
int isCycle(int V) {

    for(int i = 0; i < V; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    // Handle multiple components
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            if(dfs(i)) {
                return 1;
            }
        }
    }

    return 0;
}

// Main function
int main() {

    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Initialize
    for(int i = 0; i < V; i++) {
        adj[i] = NULL;
    }

    printf("Enter directed edges (u v):\n");
    for(int i = 0; i < E; i++) {
        int u, v;
        scanf("%d", &u, &v);
        addEdge(u, v);
    }

    if(isCycle(V)) {
        printf("YES (Cycle exists)\n");
    } else {
        printf("NO (No cycle)\n");
    }

    return 0;
}