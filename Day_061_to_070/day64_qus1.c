/*
Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
int queue[MAX];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    rear += 1;
    queue[rear] = value;
}

// Dequeue operation
int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    int value = queue[front];
    front += 1;
    return value;
}

// BFS function
void bfs(int n, int adj[MAX][MAX], int source) {
    int visited[MAX] = {0};

    printf("\nBFS Traversal: ");

    enqueue(source);
    visited[source] = 1;

    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

// Main function
int main() {
    int n, source;
    int adj[MAX][MAX];

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Input source
    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Call BFS
    bfs(n, adj, source);

    return 0;
}