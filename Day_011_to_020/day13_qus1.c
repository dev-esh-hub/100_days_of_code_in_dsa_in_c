/*
Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

Input:
- First line: two integers r and c representing the number of rows and columns
- Next r lines: c integers each representing the matrix elements

Output:
- Print all visited elements in the order of traversal, separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
1 2 3 6 9 8 7 4 5

Explanation:
The traversal begins along the top row, proceeds down the rightmost column, then moves across the bottom row in reverse, and finally goes up the leftmost column. The same pattern repeats for the inner submatrix.

Test Cases:

Test Case 1:
Input:
2 3
1 2 3
4 5 6
Output:
1 2 3 6 5 4

Test Case 2:
Input:
3 1
7
8
9
Output:
7 8 9
*/

#include <stdio.h>

#define MAX 100

void Traversal(int matrix[MAX][MAX], int rows, int cols){
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while(top <= bottom && left <= right){

        // Left to right:
        for(int i = left; i <= right; i += 1){
            printf("%d ", matrix[top][i]);
        }
        top += 1;

        // Top to Bottom:
        for(int i = top; i <= bottom; i += 1){
            printf("%d ", matrix[i][right]);
        }
        right -= 1;

        // Right to Left:
        if(top <= bottom){
            for(int i = right; i >= left; i -= 1){
                printf("%d ", matrix[bottom][i]);
            }
            bottom -= 1;
        }

        // Bottom to Top:
        if(left <= right){
            for(int i = bottom; i >= top; i -= 1){
                printf("%d ", matrix[i][left]);
            }
            left += 1;
        }
    }
}

int main(){
    int rows, cols;
    int matrix[MAX][MAX];

    printf("\nEnter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("\nEnter matrix elements:\n");
    for(int i = 0; i < rows; i += 1){
        for(int j = 0; j < cols; j += 1){
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nTraversal: \n");
    Traversal(matrix, rows, cols);

    return 0;
}
