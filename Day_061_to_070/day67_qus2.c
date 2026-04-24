/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 2005

// Adjacency list node
struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge u -> v
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main() {

    int numCourses, E;

    printf("Enter number of courses: ");
    scanf("%d", &numCourses);

    printf("Enter number of prerequisites: ");
    scanf("%d", &E);

    // Initialize adjacency list
    for(int i = 0; i < numCourses; i++) {
        adj[i] = NULL;
    }

    int indegree[MAX] = {0};

    printf("Enter prerequisites (ai bi):\n");

    // Build graph
    for(int i = 0; i < E; i++) {
        int ai, bi;
        scanf("%d %d", &ai, &bi);

        addEdge(bi, ai);   // bi → ai
        indegree[ai] += 1;
    }

    // Queue
    int queue[MAX];
    int front = 0, rear = 0;

    // Push nodes with indegree 0
    for(int i = 0; i < numCourses; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int result[MAX];
    int index = 0;

    // BFS (Kahn's Algorithm)
    while(front < rear) {

        int node = queue[front++];
        result[index++] = node;

        struct Node* temp = adj[node];

        while(temp != NULL) {
            int neighbor = temp->data;

            indegree[neighbor] -= 1;

            if(indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }

            temp = temp->next;
        }
    }

    // Check for cycle
    if(index != numCourses) {
        printf("No valid order (Cycle detected)\n");
    } else {
        printf("Course Order: ");
        for(int i = 0; i < index; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }

    return 0;
}