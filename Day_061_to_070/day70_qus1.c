/*
Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE
*/


#include <stdio.h>

#define INF 1000000000

int main() {
    int n, m, i, j;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter number of edges: ");
    scanf("%d", &m);

    int u[m], v[m], w[m];

    printf("Enter edges (u v w):\n");
    for(i = 0; i < m; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    int dist[n];

    // Initialize distances
    for(i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;

    // Relax edges n-1 times
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < m; j++) {
            if(dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]]) {
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }

    // Check negative cycle
    for(j = 0; j < m; j++) {
        if(dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]]) {
            printf("NEGATIVE CYCLE detected\n");
            return 0;
        }
    }

    // Print distances
    printf("Shortest distances from source:\n");
    for(i = 0; i < n; i++) {
        printf("Vertex %d -> %d\n", i, dist[i]);
    }

    return 0;
}