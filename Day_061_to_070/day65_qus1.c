/*
Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

// DFS function
int dfs(int node, int parent, int V) {
    visited[node] = 1;

    for(int i = 0; i < V; i++){
        if(adj[node][i] == 1){

            // If not visited → DFS
            if(visited[i] == 0){
                if(dfs(i, node, V)){
                    return 1;
                }
            }
            // If visited and not parent → cycle
            else if(i != parent){
                return 1;
            }
        }
    }
    return 0;
}

int hasCycle(int V) {

    for(int i = 0; i < V; i++){
        visited[i] = 0;
    }

    // Handle disconnected graph
    for(int i = 0; i < V; i++){
        if(visited[i] == 0){
            if(dfs(i, -1, V)){
                return 1;
            }
        }
    }

    return 0;
}

int main() {

    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Initialize adjacency matrix
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for(int i = 0; i < E; i++){
        int u, v;
        scanf("%d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1;  // Undirected graph
    }

    if(hasCycle(V)){
        printf("YES (Cycle detected)\n");
    } else {
        printf("NO (No cycle)\n");
    }

    return 0;
}