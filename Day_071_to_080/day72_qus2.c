/*
Given a 2d matrix cost[][] of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once and then at the end come back to city 0 at minimum cost.

Examples:

Input: cost[][] = [[0, 111], 
                [112, 0]]
Output: 223
Explanation: We can visit 0->1->0 and cost = 111 + 112.
Input: cost[][] = [[0, 1000, 5000],
                [5000, 0, 1000],
                [1000, 5000, 0]]
Output: 3000
Explanation: We can visit 0->1->2->0 and cost = 1000 + 1000 + 1000 = 3000
Constraints:
1 ≤ cost.size() ≤ 15
0 ≤ cost[i][j] ≤ 104
*/

#include <stdio.h>
#include <limits.h>

#define MAXN 15
#define INF 1000000000

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int n, int cost[MAXN][MAXN]) {

    int N = 1 << n;

    static int dp[1 << MAXN][MAXN];

    // Initialize DP table
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
    }

    // Starting point
    dp[1][0] = 0;

    for(int mask = 1; mask < N; mask++) {

        for(int u = 0; u < n; u++) {

            if(!(mask & (1 << u))) continue;
            if(dp[mask][u] == INF) continue;

            for(int v = 0; v < n; v++) {

                if(mask & (1 << v)) continue;

                int newMask = mask | (1 << v);

                dp[newMask][v] = min(dp[newMask][v],
                                     dp[mask][u] + cost[u][v]);
            }
        }
    }

    int ans = INF;
    int fullMask = (1 << n) - 1;

    // Return to city 0
    for(int i = 0; i < n; i++) {
        if(dp[fullMask][i] != INF) {
            ans = min(ans, dp[fullMask][i] + cost[i][0]);
        }
    }

    return ans;
}

int main() {

    int n;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    int cost[MAXN][MAXN];

    printf("Enter cost matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    int result = tsp(n, cost);

    printf("Minimum travelling cost: %d\n", result);

    return 0;
}