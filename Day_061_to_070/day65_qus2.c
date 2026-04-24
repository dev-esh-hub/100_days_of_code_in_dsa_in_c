#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

// Adjacency list node
struct Node {
    int data;
    struct Node* next;
};

// Graph
struct Node* adj[MAX];
int visited[MAX];

// Function to create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS function
int dfs(int node, int parent) {

    visited[node] = 1;

    struct Node* temp = adj[node];

    while(temp != NULL) {
        int neighbor = temp->data;

        // If not visited → DFS
        if(!visited[neighbor]) {
            if(dfs(neighbor, node)) {
                return 1;
            }
        }
        // If visited and not parent → cycle
        else if(neighbor != parent) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

// Function to check cycle
int isCycle(int V) {

    for(int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    // Handle multiple components
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            if(dfs(i, -1)) {
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

    // Initialize adjacency list
    for(int i = 0; i < V; i++) {
        adj[i] = NULL;
    }

    printf("Enter edges (u v):\n");
    for(int i = 0; i < E; i++) {
        int u, v;
        scanf("%d", &u, &v);
        addEdge(u, v);
    }

    if(isCycle(V)) {
        printf("YES (Cycle present)\n");
    } else {
        printf("NO (No cycle)\n");
    }

    return 0;
}