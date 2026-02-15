/*
Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements

Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"

Example:
Input:
3
1 0 0
0 1 0
0 0 1

Output:
Identity Matrix
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isIdentity(int ** matrix, int rows, int columns){
    for(int i = 0; i < rows; i += 1){
        for(int j = 0; j < columns; j += 1){
            
            // All Diagonal Elements should be 1:
            if(i == j && matrix[i][j] != 1){
                return false;
            }
            
            // All non-diagonal elements should be 0:
            if(i != j && matrix[i][j] != 0){
                return false;
            }
        }
    }
    
    return true;
}

int main(){

    int rows, cols;
    printf("\nEnter number of rows and columns respectively: ");
    scanf("%d %d", &rows, &cols);

    // If not a square matrix so not Symmetric:
    if(rows != cols){
        printf("\nIdentity Matrix must be square!\n");
        return 0;
    }

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

    // Checking symmetric of matrix:
    if(isIdentity(matrix, rows, cols)){
        printf("\nIdentity Matrix\n");
    } else {
        printf("\nNot an Identity Matrix\n");
    }

    return 0;
}