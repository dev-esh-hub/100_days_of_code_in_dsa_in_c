/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
*/

#include <stdio.h>
#include <stdlib.h>

// 🔹 Your function (unchanged)
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {

    int m = matrixSize;
    int n = matrixColSize[0];
    int first_row_zero = 0, first_col_zero = 0;

    // Checking first row:
    for(int i=0; i<n; i+=1){
        if(matrix[0][i] == 0){
            first_row_zero = 1;
            break;
        }
    }

    // Checking first column:
    for(int i=0; i<m; i+=1){
        if(matrix[i][0] == 0){
            first_col_zero = 1;
            break;
        }
    }

    // Marking rows and columns:
    for(int i=1; i<m; i+=1){
        for(int j=1; j<n; j+=1){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Setting zeroes using markers:
    for(int i=1; i<m; i+=1){
        for(int j=1; j<n; j+=1){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }

    // First row:
    if(first_row_zero){
        for(int i=0; i<n; i+=1){
            matrix[0][i] = 0;
        }
    }

    // First Column:
    if(first_col_zero){
        for(int i=0; i<m; i+=1){
            matrix[i][0] = 0;
        }
    }
}

int main() {
    int m, n;

    printf("\nEnter rows and columns: ");
    scanf("%d %d", &m, &n);

    // Allocate matrix dynamically
    int** matrix = (int**)malloc(m * sizeof(int*));
    for(int i = 0; i < m; i += 1){
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    // matrixColSize array (as required)
    int* matrixColSize = (int*)malloc(sizeof(int));
    matrixColSize[0] = n;

    // Input matrix
    printf("\nEnter matrix elements:\n");
    for(int i = 0; i < m; i += 1){
        for(int j = 0; j < n; j += 1){
            scanf("%d", &matrix[i][j]);
        }
    }

    // Call function
    setZeroes(matrix, m, matrixColSize);

    // Print result
    printf("\nOutput matrix:\n");
    for(int i = 0; i < m; i += 1){
        for(int j = 0; j < n; j += 1){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for(int i = 0; i < m; i += 1){
        free(matrix[i]);
    }
    free(matrix);
    free(matrixColSize);

    return 0;
}
