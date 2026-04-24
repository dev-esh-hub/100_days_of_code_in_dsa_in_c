/*
Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

// Adjacency list
typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

Node* adj[MAX];

// Create new node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v, int w) {
    Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Min Heap
typedef struct {
    int node, dist;
} HeapNode;

HeapNode heap[MAX];
int heapSize = 0;

// Swap
void swap(int i, int j) {
    HeapNode temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

// Heapify up
void heapifyUp(int i) {
    while(i > 0 && heap[(i-1)/2].dist > heap[i].dist) {
        swap(i, (i-1)/2);
        i = (i-1)/2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < heapSize && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if(right < heapSize && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if(smallest != i) {
        swap(i, smallest);
        heapifyDown(smallest);
    }
}

// Push into heap
void push(int node, int dist) {
    heap[heapSize].node = node;
    heap[heapSize].dist = dist;
    heapifyUp(heapSize);
    heapSize++;
}

// Pop from heap
HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return root;
}

int main() {

    int n, m;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize adjacency list
    for(int i = 1; i <= n; i++) {
        adj[i] = NULL;
    }

    printf("Enter edges (u v w):\n");

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        addEdge(u, v, w);
        addEdge(v, u, w); // undirected
    }

    int source;
    printf("Enter source node: ");
    scanf("%d", &source);

    int dist[n+1];

    // Initialize distances
    for(int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }

    dist[source] = 0;
    push(source, 0);

    while(heapSize > 0) {

        HeapNode curr = pop();
        int u = curr.node;

        for(Node* temp = adj[u]; temp != NULL; temp = temp->next) {
            int v = temp->v;
            int w = temp->w;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
        }
    }

    // Output
    printf("Shortest distances:\n");
    for(int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    printf("\n");

    return 0;
}