/*
Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.

 

Example 1:


Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: true
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
Example 2:


Input: matrix = [[1,2],[2,2]]
Output: false
Explanation:
The diagonal "[1, 2]" has different elements.
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 20
0 <= matrix[i][j] <= 99
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    
    for(int i = 1; i < rows; i += 1){
        for(int j = 1; j < cols; j += 1){
            if(matrix[i][j] != matrix[i-1][j-1]){
                return false;
            }
        }
    }
    return true;
}

int main() {

    int rows, cols;
    printf("\nEnter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Allocate input matrix dynamically:
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i += 1){
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    printf("\nEnter matrix elements:\n");
    for(int i = 0; i < rows; i += 1){
        for(int j = 0; j < cols; j += 1){
            scanf("%d", &matrix[i][j]);
        }
    }

    // Create matrixColSize array:
    int* matrixColSize = (int*)malloc(rows * sizeof(int));
    for(int i = 0; i < rows; i += 1){
        matrixColSize[i] = cols;
    }

    if(isToeplitzMatrix(matrix, rows, matrixColSize)){
        printf("Toeplitz Matrix\n");
    } else {
        printf("Not a Toeplitz Matrix\n");
    }

    for(int i = 0; i < rows; i += 1){
        free(matrix[i]);
    }
    free(matrix);
    free(matrixColSize);

    return 0;
}
