/*
The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.



 

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:

Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
-109 <= matrix[i][j] <= 109
*/

#include <stdio.h>
#include <stdlib.h>

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int rows = matrixSize;
    int cols = matrixColSize[0];

    *returnSize = cols;

    *returnColumnSizes = (int*)malloc(cols * sizeof(int));
    for(int i = 0; i < cols; i += 1){
        (*returnColumnSizes)[i] = rows;
    }

    int** result = (int**)malloc(cols * sizeof(int*));
    for(int i = 0; i < cols; i += 1){
        result[i] = (int*)malloc(rows * sizeof(int));
    }

    for(int i = 0; i < rows; i += 1){
        for(int j = 0; j < cols; j += 1){
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

int main() {

    int m, n;
    printf("\nEnter rows and columns: ");
    scanf("%d %d", &m, &n);

    // Allocating input matrix:
    int** matrix = (int**)malloc(m * sizeof(int*));
    for(int i = 0; i < m; i += 1){
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    printf("\nEnter matrix elements:\n");
    for(int i = 0; i < m; i += 1){
        for(int j = 0; j < n; j += 1){
            scanf("%d", &matrix[i][j]);
        }
    }

    // matrixColSize array (It tells how many columns in each row):
    int* matrixColSize = (int*)malloc(m * sizeof(int));
    for(int i = 0; i < m; i += 1){
        matrixColSize[i] = n;
    }

    int returnSize;
    int* returnColumnSizes;

    int** ans = transpose(matrix, m, matrixColSize, &returnSize, &returnColumnSizes);

    printf("\nTranspose matrix:\n");
    for(int i = 0; i < returnSize; i += 1){
        for(int j = 0; j < returnColumnSizes[i]; j += 1){
            printf("%d\t", ans[i][j]);
        }
        printf("\n\v");
    }

    // Free memory
    for(int i = 0; i < m; i += 1){
        free(matrix[i]);
    }
    free(matrix);
    free(matrixColSize);

    for(int i = 0; i < returnSize; i += 1){
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);

    return 0;
}
