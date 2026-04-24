/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

 

Example 1:


Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
Example 2:


Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
Example 3:

Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
 

Constraints:

The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node.
*/

#include <stdio.h>
#include <stdlib.h>

// Definition of Node
struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

// Map to store cloned nodes (val → node)
struct Node* map[101];

// DFS function to clone graph
struct Node* dfs(struct Node* node) {
    if(node == NULL) return NULL;

    // If already cloned
    if(map[node->val] != NULL) {
        return map[node->val];
    }

    // Create new node
    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(node->numNeighbors * sizeof(struct Node*));

    // Save in map
    map[node->val] = clone;

    // Clone neighbors
    for(int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = dfs(node->neighbors[i]);
    }

    return clone;
}

// Function required by problem
struct Node *cloneGraph(struct Node *s) {
    if(s == NULL) return NULL;

    // Initialize map
    for(int i = 0; i <= 100; i++) {
        map[i] = NULL;
    }

    return dfs(s);
}

// Helper function to create node
struct Node* createNode(int val, int numNeighbors) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->numNeighbors = numNeighbors;
    node->neighbors = (struct Node**)malloc(numNeighbors * sizeof(struct Node*));
    return node;
}

// Helper function to print graph (DFS)
void printGraph(struct Node* node, int visited[]) {
    if(node == NULL || visited[node->val]) return;

    visited[node->val] = 1;

    printf("Node %d: ", node->val);
    for(int i = 0; i < node->numNeighbors; i++) {
        printf("%d ", node->neighbors[i]->val);
    }
    printf("\n");

    for(int i = 0; i < node->numNeighbors; i++) {
        printGraph(node->neighbors[i], visited);
    }
}

int main() {

    // Example graph:
    // 1 -- 2
    // |    |
    // 4 -- 3

    struct Node* node1 = createNode(1, 2);
    struct Node* node2 = createNode(2, 2);
    struct Node* node3 = createNode(3, 2);
    struct Node* node4 = createNode(4, 2);

    // Connecting nodes
    node1->neighbors[0] = node2;
    node1->neighbors[1] = node4;

    node2->neighbors[0] = node1;
    node2->neighbors[1] = node3;

    node3->neighbors[0] = node2;
    node3->neighbors[1] = node4;

    node4->neighbors[0] = node1;
    node4->neighbors[1] = node3;

    printf("Original Graph:\n");
    int visited1[101] = {0};
    printGraph(node1, visited1);

    // Clone graph
    struct Node* cloned = cloneGraph(node1);

    printf("\nCloned Graph:\n");
    int visited2[101] = {0};
    printGraph(cloned, visited2);

    return 0;
}