/*
Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

Example 1:

Input:

Output:{1,4}
Explanation: Removing the vertex 1 will
discconect the graph as-

Removing the vertex 4 will disconnect the
graph as-

 

Your Task:
You don't need to read or print anything. Your task is to complete the function articulationPoints() which takes V and adj as input parameters and returns a list containing all the vertices removing which turn the graph into two or more disconnected components in sorted order. If there are no such vertices then returns a list containing -1.
 

Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)
 

Constraints:
1 ≤ V ≤ 105
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int **adj;
int *size;

int *disc, *low, *visited, *isAP;
int timer;

// DFS function
void dfs(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = timer++;

    int children = 0;

    for(int i = 0; i < size[u]; i++) {
        int v = adj[u][i];

        if(v == parent) continue;

        if(!visited[v]) {
            children++;
            dfs(v, u);

            // Update low value
            if(low[v] < low[u])
                low[u] = low[v];

            // Case 2: non-root
            if(parent != -1 && low[v] >= disc[u]) {
                isAP[u] = 1;
            }
        }
        else {
            if(disc[v] < low[u])
                low[u] = disc[v];
        }
    }

    // Case 1: root
    if(parent == -1 && children > 1) {
        isAP[u] = 1;
    }
}

int main() {

    int V, E;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    int edges[E][2];

    printf("Enter edges (u v):\n");
    for(int i = 0; i < E; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    // Step 1: count degrees
    size = (int*)calloc(V, sizeof(int));

    for(int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        size[u]++;
        size[v]++;
    }

    // Step 2: allocate adjacency list
    adj = (int**)malloc(V * sizeof(int*));

    for(int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(size[i] * sizeof(int));
        size[i] = 0; // reset
    }

    // Step 3: fill adjacency list
    for(int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    // Allocate arrays
    disc = (int*)malloc(V * sizeof(int));
    low = (int*)malloc(V * sizeof(int));
    visited = (int*)calloc(V, sizeof(int));
    isAP = (int*)calloc(V, sizeof(int));

    timer = 0;

    // Run DFS
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            dfs(i, -1);
        }
    }

    // Output articulation points
    int found = 0;

    printf("Articulation Points:\n");
    for(int i = 0; i < V; i++) {
        if(isAP[i]) {
            printf("%d ", i);
            found = 1;
        }
    }

    if(!found) {
        printf("-1");
    }

    printf("\n");

    return 0;
}