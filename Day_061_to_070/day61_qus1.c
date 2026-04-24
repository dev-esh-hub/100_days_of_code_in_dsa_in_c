/*
Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix
*/

#include <stdio.h>

int main() {
    int n, m, i, j;
    
    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    int adj[n][n];

    // Initialize matrix with 0
    for(i = 0; i < n; i += 1) {
        for(j = 0; j < n; j += 1) {
            adj[i][j] = 0;
        }
    }

    // Input number of edges
    printf("Enter number of edges: ");
    scanf("%d", &m);

    int u, v;

    // Ask graph type
    int type;
    printf("Enter 1 for Directed Graph, 0 for Undirected Graph: ");
    scanf("%d", &type);

    // Input edges
    for(i = 0; i < m; i += 1) {
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        // If undirected, mark both sides
        if(type == 0) {
            adj[v][u] = 1;
        }
    }

    // Print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i += 1) {
        for(j = 0; j < n; j += 1) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}