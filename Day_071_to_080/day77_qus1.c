/*
Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED
*/

#include <stdio.h>

#define MAX 1000

int adj[MAX][MAX];
int size[MAX];
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

    // Start DFS from node 1
    dfs(1);

    // Check if all nodes visited
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");

    return 0;
}