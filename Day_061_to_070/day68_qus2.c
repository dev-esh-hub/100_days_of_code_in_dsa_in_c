/*
A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

Examples:

Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
Output: true
Explanation: A possible correct order of letters in the alien dictionary is "bdac".
The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
So, 'b' → 'd' → 'a' → 'c' is a valid ordering.
Input: words[] = ["caa", "aaa", "aab"]
Output: true
Explanation: A possible correct order of letters in the alien dictionary is "cab".
The pair "caa" and "aaa" suggests 'c' appears before 'a'.
The pair "aaa" and "aab" suggests 'a' appear before 'b' in the alien dictionary. 
So, 'c' → 'a' → 'b' is a valid ordering.
Input: words[] = ["ab", "cd", "ef", "ad"]
Output: ""
Explanation: No valid ordering of letters is possible.
The pair "ab" and "ef" suggests "a" appears before "e".
The pair "ef" and "ad" suggests "e" appears before "a", which contradicts the ordering rules.
Constraints:
1 ≤ words.length ≤ 500
1 ≤ words[i].length ≤ 100
words[i] consists only of lowercase English letters.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26   // only lowercase letters

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

    int n;
    printf("Enter number of words: ");
    scanf("%d", &n);

    char words[n][101];

    printf("Enter words:\n");
    for(int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    // Initialize
    for(int i = 0; i < MAX; i++) {
        adj[i] = NULL;
    }

    int indegree[MAX] = {0};
    int present[MAX] = {0}; // track which chars exist

    // Mark present characters
    for(int i = 0; i < n; i++) {
        for(int j = 0; words[i][j] != '\0'; j++) {
            present[words[i][j] - 'a'] = 1;
        }
    }

    // Build graph
    for(int i = 0; i < n - 1; i++) {
        char* w1 = words[i];
        char* w2 = words[i + 1];

        int len = strlen(w1) < strlen(w2) ? strlen(w1) : strlen(w2);
        int found = 0;

        for(int j = 0; j < len; j++) {
            if(w1[j] != w2[j]) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';

                addEdge(u, v);
                indegree[v]++;

                found = 1;
                break;
            }
        }

        // Prefix invalid case
        if(!found && strlen(w1) > strlen(w2)) {
            printf("Invalid order\n");
            return 0;
        }
    }

    // Queue
    int queue[MAX];
    int front = 0, rear = 0;

    // Push nodes with indegree 0
    for(int i = 0; i < MAX; i++) {
        if(present[i] && indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    char result[MAX];
    int index = 0;

    // Kahn's Algorithm
    while(front < rear) {

        int node = queue[front++];
        result[index++] = (char)(node + 'a');

        struct Node* temp = adj[node];

        while(temp != NULL) {
            int neighbor = temp->data;

            indegree[neighbor]--;

            if(indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }

            temp = temp->next;
        }
    }

    // Count total unique characters
    int total = 0;
    for(int i = 0; i < MAX; i++) {
        if(present[i]) total++;
    }

    // Check cycle
    if(index != total) {
        printf("Invalid order (Cycle detected)\n");
    } else {
        printf("Alien Dictionary Order: ");
        for(int i = 0; i < index; i++) {
            printf("%c ", result[i]);
        }
        printf("\n");
    }

    return 0;
}