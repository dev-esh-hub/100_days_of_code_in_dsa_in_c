/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 

Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109
*/

#include <stdio.h>

// Function to find minimum eating speed
int minEatingSpeed(int* piles, int pilesSize, int h) {
    
    int max = piles[0];
    
    // Find maximum pile
    for (int i = 1; i < pilesSize; i++) {
        if (piles[i] > max) {
            max = piles[i];
        }
    }

    int low = 1, high = max;
    int ans = max;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        long long totalHours = 0;

        // Calculate total hours needed
        for (int i = 0; i < pilesSize; i++) {
            totalHours += (piles[i] + mid - 1) / mid;  // ceil division
        }

        if (totalHours <= h) {
            ans = mid;        // possible answer
            high = mid - 1;   // try smaller speed
        } else {
            low = mid + 1;    // increase speed
        }
    }

    return ans;
}

int main() {
    int n, h;

    printf("Enter number of piles: ");
    scanf("%d", &n);

    int piles[n];

    printf("Enter %d pile values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &piles[i]);
    }

    printf("Enter total hours (h): ");
    scanf("%d", &h);

    int result = minEatingSpeed(piles, n, h);

    printf("Minimum eating speed (k) is: %d\n", result);

    return 0;
}