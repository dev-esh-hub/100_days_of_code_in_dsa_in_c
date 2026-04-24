/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 2005

// Adjacency list node
struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];
int recStack[MAX];

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add directed edge u -> v
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS function to detect cycle
int dfs(int node) {

    visited[node] = 1;
    recStack[node] = 1;

    struct Node* temp = adj[node];

    while(temp != NULL) {
        int neighbor = temp->data;

        if(!visited[neighbor]) {
            if(dfs(neighbor)) {
                return 1;
            }
        }
        else if(recStack[neighbor]) {
            return 1; // cycle detected
        }

        temp = temp->next;
    }

    recStack[node] = 0; // backtrack
    return 0;
}

// Function to check if all courses can be finished
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize) {

    // Initialize
    for(int i = 0; i < numCourses; i++) {
        adj[i] = NULL;
        visited[i] = 0;
        recStack[i] = 0;
    }

    // Build graph (bi -> ai)
    for(int i = 0; i < prerequisitesSize; i++) {
        int ai = prerequisites[i][0];
        int bi = prerequisites[i][1];
        addEdge(bi, ai);
    }

    // Check cycle in all components
    for(int i = 0; i < numCourses; i++) {
        if(!visited[i]) {
            if(dfs(i)) {
                return false;
            }
        }
    }

    return true;
}

// Main function
int main() {

    int numCourses, E;

    printf("Enter number of courses: ");
    scanf("%d", &numCourses);

    printf("Enter number of prerequisites: ");
    scanf("%d", &E);

    // Allocate prerequisites array
    int** prerequisites = (int**)malloc(E * sizeof(int*));
    for(int i = 0; i < E; i++) {
        prerequisites[i] = (int*)malloc(2 * sizeof(int));
    }

    printf("Enter prerequisites (ai bi):\n");
    for(int i = 0; i < E; i++) {
        scanf("%d %d", &prerequisites[i][0], &prerequisites[i][1]);
    }

    if(canFinish(numCourses, prerequisites, E)) {
        printf("YES (All courses can be finished)\n");
    } else {
        printf("NO (Cycle detected, cannot finish)\n");
    }

    // Free memory
    for(int i = 0; i < E; i++) {
        free(prerequisites[i]);
    }
    free(prerequisites);

    return 0;
}