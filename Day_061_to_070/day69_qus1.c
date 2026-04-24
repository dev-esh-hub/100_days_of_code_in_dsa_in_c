// Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100005

// Adjacency list node
struct Node {
    int vertex, weight;
    struct Node* next;
};

struct Node* adj[MAX];

// Min Heap Node
struct HeapNode {
    int vertex, dist;
};

// Min Heap
struct MinHeap {
    int size;
    struct HeapNode heap[MAX];
};

// Create node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;

    // For undirected graph (optional)
    newNode = createNode(u, w);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Swap heap nodes
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(struct MinHeap* h, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if(right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if(smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapify(h, smallest);
    }
}

// Extract min
struct HeapNode extractMin(struct MinHeap* h) {
    struct HeapNode root = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapify(h, 0);
    return root;
}

// Insert into heap
void insert(struct MinHeap* h, int v, int dist) {
    int i = h->size++;
    h->heap[i].vertex = v;
    h->heap[i].dist = dist;

    while(i && h->heap[(i-1)/2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Dijkstra
void dijkstra(int V, int src) {

    int dist[MAX];
    for(int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }

    struct MinHeap heap;
    heap.size = 0;

    dist[src] = 0;
    insert(&heap, src, 0);

    while(heap.size > 0) {

        struct HeapNode minNode = extractMin(&heap);
        int u = minNode.vertex;

        struct Node* temp = adj[u];

        while(temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                insert(&heap, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    printf("Shortest distances from source %d:\n", src);
    for(int i = 0; i < V; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }
}

// Main
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

    printf("Enter edges (u v weight):\n");
    for(int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(V, src);

    return 0;
}