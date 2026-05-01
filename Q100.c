/*Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.*/
#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort (sort by position descending)
int cmp(const void *a, const void *b) {
    int *x = (int*)a;
    int *y = (int*)b;
    return y[0] - x[0]; // descending by position
}

// Function to compute number of car fleets
int carFleets(int target, int position[], int speed[], int n) {
    // Step 1: Pair position and speed
    int cars[n][2];
    for (int i = 0; i < n; i++) {
        cars[i][0] = position[i];
        cars[i][1] = speed[i];
    }

    // Step 2: Sort cars by position descending
    qsort(cars, n, sizeof(cars[0]), cmp);

    // Step 3: Traverse and compute fleets
    int fleets = 0;
    double prevTime = -1.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i][0]) / cars[i][1];
        if (time > prevTime) {
            fleets++;
            prevTime = time;
        }
        // If time <= prevTime, this car joins the fleet ahead
    }
    return fleets;
}

int main() {
    int target, n;
    scanf("%d %d", &target, &n);

    int position[n], speed[n];
    for (int i = 0; i < n; i++) scanf("%d", &position[i]);
    for (int i = 0; i < n; i++) scanf("%d", &speed[i]);

    printf("%d\n", carFleets(target, position, speed, n));
    return 0;
}
