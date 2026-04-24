/*
Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)
*/

#include <stdio.h>
#include <limits.h>

#define MAX 100

int minKey(int key[], int visited[], int n) {
    int min = INT_MAX, minIndex = -1;

    for(int i = 1; i <= n; i++) {
        if(!visited[i] && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {

    int n, m;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    // Initialize graph
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v w):\n");

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int key[n+1];
    int visited[n+1];

    // Initialize
    for(int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0;  // Start from node 1

    int totalCost = 0;

    for(int count = 1; count <= n; count++) {

        int u = minKey(key, visited, n);
        visited[u] = 1;

        totalCost += key[u];

        // Update neighbors
        for(int v = 1; v <= n; v++) {
            if(graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("Total weight of MST: %d\n", totalCost);

    return 0;
}