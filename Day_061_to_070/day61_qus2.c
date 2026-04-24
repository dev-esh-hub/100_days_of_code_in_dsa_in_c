/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
*/

#include <stdio.h>

// DFS function
void dfs(int** isConnected, int n, int visited[], int city) {
    visited[city] = 1;

    for(int j = 0; j < n; j += 1) {
        if(isConnected[city][j] == 1 && visited[j] == 0) {
            dfs(isConnected, n, visited, j);
        }
    }
}

// Main function required by problem
int findCircleNum(int** isConnected, int n, int* isConnectedColSize) {
    int visited[n];
    
    // Initialize visited array
    for(int i = 0; i < n; i += 1) {
        visited[i] = 0;
    }

    int provinces = 0;

    for(int i = 0; i < n; i += 1) {
        if(visited[i] == 0) {
            dfs(isConnected, n, visited, i);
            provinces += 1;
        }
    }

    return provinces;
}

int main() {
    int n;

    printf("Enter number of cities (n): ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i += 1) {
        for(int j = 0; j < n; j += 1) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Convert to pointer format (for function compatibility)
    int* ptr[n];
    for(int i = 0; i < n; i += 1) {
        ptr[i] = matrix[i];
    }

    int colSize = n;

    int result = findCircleNum(ptr, n, &colSize);

    printf("Number of provinces: %d\n", result);

    return 0;
}