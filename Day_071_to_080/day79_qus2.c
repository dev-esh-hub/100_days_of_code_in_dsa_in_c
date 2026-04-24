/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. Find the number of strongly connected components in the graph.

Examples:

Input: V = 5, E = 5, edges[][] = [[0, 2], [0, 3], [1, 0], [2, 1], [3, 4]]


Output: 3
Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph.
 
Input: V = 3, E = 3, edges[][] = [[0, 1], [1, 2], [2, 0]]

Output: 1
Explanation: All of the nodes are connected to each other. So, there's only one SCC.
Input: V = 2, E = 1, edges[][] = [[0, 1]]
Output: 2
Constraints:
1 ≤ V ≤ 106
0 ≤ E ≤ 106
0 ≤ edges[i][0], edges[i][1] < V
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

// Adjacency lists
int **adj, **rev;
int *size1, *size2;

// Stack
int stack[MAX];
int top = -1;

// Visited array
int *visited;

// Push to stack
void push(int x) {
    stack[++top] = x;
}

// Pop from stack
int pop() {
    return stack[top--];
}

// DFS 1 (fill stack)
void dfs1(int u) {
    visited[u] = 1;

    for(int i = 0; i < size1[u]; i++) {
        int v = adj[u][i];
        if(!visited[v]) {
            dfs1(v);
        }
    }

    push(u);
}

// DFS 2 (on reversed graph)
void dfs2(int u) {
    visited[u] = 1;

    for(int i = 0; i < size2[u]; i++) {
        int v = rev[u][i];
        if(!visited[v]) {
            dfs2(v);
        }
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
    size1 = (int*)calloc(V, sizeof(int));
    size2 = (int*)calloc(V, sizeof(int));

    for(int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        size1[u]++;
        size2[v]++;
    }

    // Step 2: allocate adjacency lists
    adj = (int**)malloc(V * sizeof(int*));
    rev = (int**)malloc(V * sizeof(int*));

    for(int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(size1[i] * sizeof(int));
        rev[i] = (int*)malloc(size2[i] * sizeof(int));
        size1[i] = 0;
        size2[i] = 0;
    }

    // Step 3: fill adjacency lists
    for(int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][size1[u]++] = v;
        rev[v][size2[v]++] = u;
    }

    // Initialize visited
    visited = (int*)calloc(V, sizeof(int));

    // Step 4: DFS to fill stack
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            dfs1(i);
        }
    }

    // Reset visited
    for(int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    // Step 5: DFS on reversed graph
    int scc = 0;

    while(top != -1) {
        int node = pop();

        if(!visited[node]) {
            dfs2(node);
            scc++;
        }
    }

    printf("Number of Strongly Connected Components: %d\n", scc);

    return 0;
}