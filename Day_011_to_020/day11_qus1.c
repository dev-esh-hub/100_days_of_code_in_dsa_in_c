/*
Problem: Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the first matrix
- Next m lines: n integers each representing the elements of the second matrix

Output:
- Print the resultant matrix after addition, with each row on a new line and elements separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9
9 8 7
6 5 4
3 2 1

Output:
10 10 10
10 10 10
10 10 10

Explanation:
Each element of the result matrix is the sum of the corresponding elements from the two input matrices.

Test Cases:

Test Case 1:
Input:
2 2
1 2
3 4
5 6
7 8
Output:
6 8
10 12

Test Case 2:
Input:
1 3
10 20 30
1 2 3
Output:
11 22 33

Test Case 3:
Input:
3 1
1
2
3
4
5
6
Output:
5
7
9
*/

#include<stdio.h>

int main(){

    int n, m;
    printf("\nEnter the number of rows and columns for matrix number 1 and 2 both respectively: ");
    scanf("%d %d", &n, &m);

    int mat1[n][m], mat2[n][m];
    printf("\nEnter elements for matrix 1:\n");
    for(int i=0; i<n; i+=1){
        for(int j=0; j<m; j+=1){
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("\nEnter elements for matrix 2:\n");
    for(int i=0; i<n; i+=1){
        for(int j=0; j<m; j+=1){
            scanf("%d", &mat2[i][j]);
        }
    }

    // Addition of matrices:
    for(int i=0; i<n; i+=1){
        for(int j=0; j<m; j+=1){
            mat1[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    // Printing the sumation matrix:
    printf("\nThe Resultant matrix is:\n");
    for(int i=0; i<n; i+=1){
        for(int j=0; j<m; j+=1){
            printf("%d\t", mat1[i][j]);
        }
        printf("\n\v");
    }

    return 0;
}