/*
Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

Input:
- First line: two integers m and n
- Next m lines: n integers each

Output:
- Print the sum of the primary diagonal elements

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
15

Explanation:
1 + 5 + 9 = 15
*/

#include<stdio.h>
#include<stdlib.h>

int diagonal_sum(int ** matrix, int rows, int cols){

    int sum = 0;

    for(int i=0; i<rows; i+=1){
        for(int j=0; j<cols; j+=1){
            if(i == j){
                sum += matrix[i][j];
            }
        }
    }

    return sum;
}

int main(){

    int rows, cols;
    printf("\nEnter the numebr of rows and column: ");
    scanf("%d %d", &rows, &cols);

    if(rows != cols){
        printf("\nOnly Sqare matrix allowed!\n");
        return 0;
    }

    // Allocating input matrix dinamically:
    int **matrix = (int**)malloc(rows * sizeof(int));
    for(int i=0; i<rows; i+=1){
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    printf("\nEnter matrix elements: \n");
    for(int i=0; i<rows; i+=1){
        for(int j=0; j<cols; j+=1){
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nThe sum of diagonals is: %d", diagonal_sum(matrix, rows, cols));

    return 0;
}