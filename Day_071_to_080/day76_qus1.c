/*
Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Adjacency list
int adj[MAX][MAX];
int size[MAX];   // number of neighbors
int visited[MAX];

// DFS function
void dfs(int node) {
    visited[node] = 1;

    for(int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];

        if(!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {

    int n, m;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize
    for(int i = 1; i <= n; i++) {
        size[i] = 0;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Undirected graph
        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    int components = 0;

    // Count components
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i);
            components += 1;
        }
    }

    printf("Number of connected components: %d\n", components);

    return 0;
}