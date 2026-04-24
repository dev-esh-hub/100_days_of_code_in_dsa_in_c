// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

// Adjacency list node
struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];

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

    int indegree[MAX] = {0};

    printf("Enter directed edges (u v):\n");

    // Build graph
    for(int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(u, v);
        indegree[v] += 1;
    }

    // Queue
    int queue[MAX];
    int front = 0, rear = 0;

    // Push nodes with indegree 0
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int topo[MAX];
    int index = 0;

    // BFS (Kahn's Algorithm)
    while(front < rear) {

        int node = queue[front++];
        topo[index++] = node;

        struct Node* temp = adj[node];

        while(temp != NULL) {
            int neighbor = temp->data;

            indegree[neighbor] -= 1;

            if(indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }

            temp = temp->next;
        }
    }

    // Check for cycle
    if(index != V) {
        printf("Cycle detected! Topological sort not possible.\n");
    } else {
        printf("Topological Order: ");
        for(int i = 0; i < index; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }

    return 0;
}