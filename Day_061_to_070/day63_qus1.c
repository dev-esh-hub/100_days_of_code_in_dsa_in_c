/*
Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int vertex;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// DFS function
void dfs(struct Node* adj[], int visited[], int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while(temp != NULL) {
        if(visited[temp->vertex] == 0) {
            dfs(adj, visited, temp->vertex);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Node* adj[n];

    // Initialize adjacency list
    for(int i = 0; i < n; i += 1) {
        adj[i] = NULL;
    }

    printf("Enter number of edges: ");
    scanf("%d", &m);

    int type;
    printf("Enter 1 for Directed Graph, 0 for Undirected Graph: ");
    scanf("%d", &type);

    int u, v;

    // Input edges
    for(int i = 0; i < m; i += 1) {
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);

        // Add edge u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // If undirected
        if(type == 0) {
            struct Node* newNode2 = createNode(u);
            newNode2->next = adj[v];
            adj[v] = newNode2;
        }
    }

    int start;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    int visited[n];

    // Initialize visited array
    for(int i = 0; i < n; i += 1) {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    dfs(adj, visited, start);

    printf("\n");

    return 0;
}