// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

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
int stack[MAX];
int top = -1;

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add directed edge u -> v
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Push to stack
void push(int v) {
    stack[top += 1] = v;
}

// DFS function
void dfs(int node) {

    visited[node] = 1;

    struct Node* temp = adj[node];

    while(temp != NULL) {
        int neighbor = temp->data;

        if(!visited[neighbor]) {
            dfs(neighbor);
        }

        temp = temp->next;
    }

    // Push after finishing
    push(node);
}

// Topological sort
void topoSort(int V) {

    for(int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    // Handle multiple components
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Order: ");

    // Print stack (reverse order)
    while(top != -1) {
        printf("%d ", stack[top]);
        top -= 1;
    }

    printf("\n");
}

// Main function
int main() {

    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Initialize adjacency list
    for(int i = 0; i < V; i++) {
        adj[i] = NULL;
    }

    printf("Enter directed edges (u v):\n");
    for(int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    topoSort(V);

    return 0;
}