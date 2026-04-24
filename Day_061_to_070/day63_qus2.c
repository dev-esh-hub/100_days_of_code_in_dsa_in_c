/*
You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.

 

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation:



From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.

Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.

Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0

Output: [[0,0,0],[0,0,0]]

Explanation:

The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.

 

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n
*/

#include <stdio.h>
#include <stdlib.h>

// DFS function
void dfs(int** image, int m, int n, int r, int c, int original, int color) {
    
    // Boundary check
    if(r < 0 || c < 0 || r >= m || c >= n) {
        return;
    }

    // Stop if color doesn't match
    if(image[r][c] != original) {
        return;
    }

    // Fill new color
    image[r][c] = color;

    // 4 directions
    dfs(image, m, n, r + 1, c, original, color);
    dfs(image, m, n, r - 1, c, original, color);
    dfs(image, m, n, r, c + 1, original, color);
    dfs(image, m, n, r, c - 1, original, color);
}

int main() {
    int m, n;

    printf("Enter number of rows (m): ");
    scanf("%d", &m);

    printf("Enter number of columns (n): ");
    scanf("%d", &n);

    // Allocate 2D array
    int** image = (int**)malloc(m * sizeof(int*));
    for(int i = 0; i < m; i += 1) {
        image[i] = (int*)malloc(n * sizeof(int));
    }

    // Input matrix
    printf("Enter the image matrix:\n");
    for(int i = 0; i < m; i += 1) {
        for(int j = 0; j < n; j += 1) {
            scanf("%d", &image[i][j]);
        }
    }

    int sr, sc, color;

    printf("Enter starting row (sr): ");
    scanf("%d", &sr);

    printf("Enter starting column (sc): ");
    scanf("%d", &sc);

    printf("Enter new color: ");
    scanf("%d", &color);

    int original = image[sr][sc];

    // Important check
    if(original != color) {
        dfs(image, m, n, sr, sc, original, color);
    }

    // Output result
    printf("\nUpdated Image:\n");
    for(int i = 0; i < m; i += 1) {
        for(int j = 0; j < n; j += 1) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for(int i = 0; i < m; i += 1) {
        free(image[i]);
    }
    free(image);

    return 0;
}