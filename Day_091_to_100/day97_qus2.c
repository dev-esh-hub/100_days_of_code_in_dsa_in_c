/*
Given two arrays start[] and end[] such that start[i] is the starting time of ith meeting and end[i] is the ending time of ith meeting. Return the minimum number of rooms required to attend all meetings.

Note: A person can also attend a meeting if it's starting time is same as the previous meeting's ending time.

Examples:

Input: start[] = [1, 10, 7], end[] = [4, 15, 10]
Output: 1
Explanation: Since all the meetings are held at different times, it is possible to attend all the meetings in a single room.
Input: start[] = [2, 9, 6], end[] = [4, 12, 10]
Output: 2
Explanation: 1st and 2nd meetings at one room but for 3rd meeting one another room required.
Constraints:
1 ≤ start.size() = end.size() ≤ 105
0 ≤ start[i] < end[i] ≤ 106
*/

#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Function to find minimum rooms
int minMeetingRooms(int start[], int end[], int n) {

    // Sort both arrays
    qsort(start, n, sizeof(int), compare);
    qsort(end, n, sizeof(int), compare);

    int i = 0, j = 0;
    int rooms = 0, maxRooms = 0;

    while (i < n) {

        // New meeting starts before previous ends
        if (start[i] < end[j]) {
            rooms += 1;
            i += 1;
        } else {
            // Room becomes free
            rooms -= 1;
            j += 1;
        }

        if (rooms > maxRooms) {
            maxRooms = rooms;
        }
    }

    return maxRooms;
}

int main() {
    int n;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    int start[n], end[n];

    printf("Enter start times:\n");
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &start[i]);
    }

    printf("Enter end times:\n");
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &end[i]);
    }

    int result = minMeetingRooms(start, end, n);

    printf("Minimum number of rooms required: %d\n", result);

    return 0;
}