/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 

Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 105

// Adjacency list node
struct Node {
    int vertex, weight;
    struct Node* next;
};

struct Node* adj[MAX];

// Create node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add directed edge u -> v
void addEdge(int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Dijkstra function
int networkDelayTime(int n, int k) {

    int dist[MAX];
    int visited[MAX] = {0};

    // Initialize distances
    for(int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }

    dist[k] = 0;

    // Dijkstra
    for(int i = 1; i <= n; i++) {

        int u = -1;
        int minDist = INT_MAX;

        // Find minimum distance unvisited node
        for(int j = 1; j <= n; j++) {
            if(!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if(u == -1) break;

        visited[u] = 1;

        struct Node* temp = adj[u];

        while(temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if(!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }

            temp = temp->next;
        }
    }

    // Find maximum distance
    int maxTime = 0;

    for(int i = 1; i <= n; i++) {
        if(dist[i] == INT_MAX) {
            return -1;
        }
        if(dist[i] > maxTime) {
            maxTime = dist[i];
        }
    }

    return maxTime;
}

// Main function
int main() {

    int n, E;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Initialize graph
    for(int i = 1; i <= n; i++) {
        adj[i] = NULL;
    }

    printf("Enter edges (u v w):\n");
    for(int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int k;
    printf("Enter source node: ");
    scanf("%d", &k);

    int result = networkDelayTime(n, k);

    if(result == -1) {
        printf("Not all nodes are reachable\n");
    } else {
        printf("Minimum time for all nodes: %d\n", result);
    }

    return 0;
}