/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
*/

#include <stdio.h>
#include <stdlib.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;

    // Transposing the matrix:
    for(int i = 0; i < n; i += 1) {
        for(int j = i + 1; j < n; j += 1) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Reversing each row in matrix:
    for(int i = 0; i < n; i += 1) {
        int left = 0, right = n - 1;
        while(left < right) {
            int temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;
            left += 1;
            right -= 1;
        }
    }
}

int main() {
    int n, m;

    printf("\nEnter number of rows and columns: ");
    scanf("%d %d", &n, &m);

    // Allocate input matrix dynamically:
    int** matrix = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i += 1) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    printf("\nEnter matrix elements:\n");
    for(int i = 0; i < n; i += 1) {
        for(int j = 0; j < n; j += 1) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int* matrixColSize = (int*)malloc(sizeof(int));
    matrixColSize[0] = n;

    rotate(matrix, n, matrixColSize);

    printf("\nRotated Matrix (90° Clockwise):\n");
    for(int i = 0; i < n; i += 1) {
        for(int j = 0; j < n; j += 1) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n\v");
    }

    // Free memory:
    for(int i = 0; i < n; i += 1) {
        free(matrix[i]);
    }
    free(matrix);
    free(matrixColSize);

    return 0;
}
