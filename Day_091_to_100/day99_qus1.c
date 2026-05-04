/*
Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for car
struct Car {
    int position;
    double time;
};

// Comparator for sorting by position (descending)
int compare(const void* a, const void* b) {
    struct Car* x = (struct Car*)a;
    struct Car* y = (struct Car*)b;
    return y->position - x->position;
}

// Function to count car fleets
int carFleet(int target, int position[], int speed[], int n) {

    struct Car cars[n];

    // Step 1: store position and time
    for (int i = 0; i < n; i += 1) {
        cars[i].position = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // Step 2: sort by position descending
    qsort(cars, n, sizeof(struct Car), compare);

    int fleets = 0;
    double maxTime = 0;

    // Step 3: traverse
    for (int i = 0; i < n; i += 1) {

        // New fleet
        if (cars[i].time > maxTime) {
            fleets += 1;
            maxTime = cars[i].time;
        }
    }

    return fleets;
}

int main() {
    int n, target;

    printf("Enter number of cars: ");
    scanf("%d", &n);

    int position[n], speed[n];

    printf("Enter positions:\n");
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &position[i]);
    }

    printf("Enter speeds:\n");
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &speed[i]);
    }

    printf("Enter target distance: ");
    scanf("%d", &target);

    int result = carFleet(target, position, speed, n);

    printf("Number of car fleets: %d\n", result);

    return 0;
}