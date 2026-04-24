/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/

#include <stdio.h>
#include <stdlib.h>

// Queue structure
typedef struct {
    int x, y;
} Node;

// Function to calculate minimum time
int orangesRotting(int** grid, int gridSize, int* gridColSize) {

    int rows = gridSize;
    int cols = gridColSize[0];

    Node queue[100];
    int front = 0, rear = 0;

    int fresh = 0;

    // Push all rotten oranges into queue + count fresh
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(grid[i][j] == 2){
                queue[rear].x = i;
                queue[rear].y = j;
                rear += 1;
            }
            else if(grid[i][j] == 1){
                fresh += 1;
            }
        }
    }

    // If no fresh oranges
    if(fresh == 0) return 0;

    int minutes = 0;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    // BFS
    while(front < rear){

        int size = rear - front;
        int rotted_this_round = 0;

        for(int i = 0; i < size; i++){
            Node curr = queue[front];
            front += 1;

            for(int d = 0; d < 4; d++){
                int nx = curr.x + dx[d];
                int ny = curr.y + dy[d];

                if(nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1){
                    grid[nx][ny] = 2;

                    queue[rear].x = nx;
                    queue[rear].y = ny;
                    rear += 1;

                    fresh -= 1;
                    rotted_this_round = 1;
                }
            }
        }

        if(rotted_this_round == 1){
            minutes += 1;
        }
    }

    if(fresh > 0) return -1;

    return minutes;
}

// Main function
int main() {

    int m, n;

    printf("Enter number of rows: ");
    scanf("%d", &m);

    printf("Enter number of columns: ");
    scanf("%d", &n);

    // Allocate memory for grid
    int** grid = (int**)malloc(m * sizeof(int*));
    for(int i = 0; i < m; i++){
        grid[i] = (int*)malloc(n * sizeof(int));
    }

    printf("Enter grid values (0, 1, 2):\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &grid[i][j]);
        }
    }

    int* gridColSize = (int*)malloc(sizeof(int));
    gridColSize[0] = n;

    int result = orangesRotting(grid, m, gridColSize);

    printf("Minimum minutes required: %d\n", result);

    // Free memory
    for(int i = 0; i < m; i++){
        free(grid[i]);
    }
    free(grid);
    free(gridColSize);

    return 0;
}