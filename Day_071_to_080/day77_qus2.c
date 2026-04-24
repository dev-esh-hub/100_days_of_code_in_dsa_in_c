/*
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]
 

Constraints:

2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.
*/

#include <stdio.h>
#include <stdlib.h>

int *disc, *low, *visited;
int timeCounter;

int **adj;
int *size;

int **result;
int resultSize = 0;

// DFS (Tarjan)
void dfs(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = timeCounter++;

    for(int i = 0; i < size[u]; i++) {
        int v = adj[u][i];

        if(v == parent) continue;

        if(!visited[v]) {
            dfs(v, u);

            if(low[v] < low[u])
                low[u] = low[v];

            if(low[v] > disc[u]) {
                result[resultSize] = (int*)malloc(2 * sizeof(int));
                result[resultSize][0] = u;
                result[resultSize][1] = v;
                resultSize++;
            }
        }
        else {
            if(disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int main() {

    int n, m;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of connections: ");
    scanf("%d", &m);

    int connections[m][2];

    printf("Enter connections (u v):\n");
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &connections[i][0], &connections[i][1]);
    }

    // Step 1: count degrees
    size = (int*)calloc(n, sizeof(int));

    for(int i = 0; i < m; i++) {
        int u = connections[i][0];
        int v = connections[i][1];
        size[u]++;
        size[v]++;
    }

    // Step 2: allocate adjacency list
    adj = (int**)malloc(n * sizeof(int*));

    for(int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(size[i] * sizeof(int));
        size[i] = 0; // reset
    }

    // Step 3: fill adjacency list
    for(int i = 0; i < m; i++) {
        int u = connections[i][0];
        int v = connections[i][1];

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    // Allocate arrays
    disc = (int*)malloc(n * sizeof(int));
    low = (int*)malloc(n * sizeof(int));
    visited = (int*)calloc(n, sizeof(int));

    result = (int**)malloc(m * sizeof(int*));
    resultSize = 0;
    timeCounter = 0;

    // Run DFS
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, -1);
        }
    }

    // Output
    printf("Critical Connections:\n");

    for(int i = 0; i < resultSize; i++) {
        printf("[%d, %d]\n", result[i][0], result[i][1]);
    }

    if(resultSize == 0) {
        printf("No critical connections\n");
    }

    return 0;
}