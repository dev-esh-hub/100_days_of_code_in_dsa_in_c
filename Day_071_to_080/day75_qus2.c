/*
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

 

Example 1:


Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
Example 2:


Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
 

Constraints:

graph.length == n
1 <= n <= 100
0 <= graph[u].length < n
0 <= graph[u][i] <= n - 1
graph[u] does not contain u.
All the values of graph[u] are unique.
If graph[u] contains v, then graph[v] contains u.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check bipartite using BFS
bool isBipartite(int** graph, int n, int* graphColSize) {

    int* color = (int*)malloc(n * sizeof(int));

    // Initialize all nodes as uncolored
    for(int i = 0; i < n; i++) {
        color[i] = -1;
    }

    // Check all components
    for(int i = 0; i < n; i++) {

        if(color[i] != -1) continue;

        // BFS queue
        int queue[1000];
        int front = 0, rear = 0;

        queue[rear++] = i;
        color[i] = 0;

        while(front < rear) {

            int u = queue[front++];

            for(int j = 0; j < graphColSize[u]; j++) {
                int v = graph[u][j];

                if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    queue[rear++] = v;
                }
                else if(color[v] == color[u]) {
                    free(color);
                    return false;
                }
            }
        }
    }

    free(color);
    return true;
}

int main() {

    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int** graph = (int**)malloc(n * sizeof(int*));
    int* graphColSize = (int*)malloc(n * sizeof(int));

    printf("Enter adjacency list:\n");

    for(int i = 0; i < n; i++) {
        printf("Enter number of neighbors of node %d: ", i);
        scanf("%d", &graphColSize[i]);

        graph[i] = (int*)malloc(graphColSize[i] * sizeof(int));

        printf("Enter neighbors:\n");
        for(int j = 0; j < graphColSize[i]; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if(isBipartite(graph, n, graphColSize)) {
        printf("Graph is Bipartite\n");
    } else {
        printf("Graph is NOT Bipartite\n");
    }

    // Free memory
    for(int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(graphColSize);

    return 0;
}