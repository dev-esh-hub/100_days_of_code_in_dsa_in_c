/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    
    if(matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];
    int total = rows * cols;

    int* result = (int*)malloc(total * sizeof(int));
    *returnSize = total;

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    int k = 0;

    while(top <= bottom && left <= right) {

        // Left to Right:
        for(int i = left; i <= right; i += 1) {
            result[k] = matrix[top][i];
            k += 1;
        }
        top += 1;

        // Top to Bottom:
        for(int i = top; i <= bottom; i += 1) {
            result[k] = matrix[i][right];
            k += 1;
        }
        right -= 1;

        // Right to Left:
        if(top <= bottom) {
            for(int i = right; i >= left; i -= 1) {
                result[k] = matrix[bottom][i];
                k += 1;
            }
            bottom -= 1;
        }

        // Bottom to Top:
        if(left <= right) {
            for(int i = bottom; i >= top; i -= 1) {
                result[k] = matrix[i][left];
                k += 1;
            }
            left += 1;
        }
    }

    return result;
}

int main() {
    int m, n;

    printf("\nEnter rows and columns: ");
    scanf("%d %d", &m, &n);

    // Allocate input matrix:
    int** matrix = (int**)malloc(m * sizeof(int*));
    for(int i = 0; i < m; i += 1) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    printf("\nEnter matrix elements:\n");
    for(int i = 0; i < m; i += 1) {
        for(int j = 0; j < n; j += 1) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int returnSize;
    int* matrixColSize = (int*)malloc(sizeof(int));
    matrixColSize[0] = n;

    int* result = spiralOrder(matrix, m, matrixColSize, &returnSize);

    printf("\nSpiral Order traversal: ");
    for(int i = 0; i < returnSize; i += 1) {
        printf("%d ", result[i]);
    }

    // Free memory:
    free(result);
    free(matrixColSize);
    for(int i = 0; i < m; i += 1) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
