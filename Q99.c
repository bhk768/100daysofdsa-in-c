/*Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.*/
#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort (sort by start time)
int cmp(const void *a, const void *b) {
    int *x = (int*)a;
    int *y = (int*)b;
    return x[0] - y[0];
}

// Function to merge intervals
int mergeIntervals(int intervals[][2], int n, int result[][2]) {
    // Step 1: Sort intervals by start time
    qsort(intervals, n, sizeof(intervals[0]), cmp);

    // Step 2: Traverse and merge
    int idx = 0; // index for result
    result[idx][0] = intervals[0][0];
    result[idx][1] = intervals[0][1];

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= result[idx][1]) {
            // Overlap → extend end time
            if (intervals[i][1] > result[idx][1]) {
                result[idx][1] = intervals[i][1];
            }
        } else {
            // No overlap → new interval
            idx++;
            result[idx][0] = intervals[i][0];
            result[idx][1] = intervals[i][1];
        }
    }
    return idx + 1; // number of merged intervals
}

int main() {
    int n;
    scanf("%d", &n);
    int intervals[n][2];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    int result[n][2];
    int mergedCount = mergeIntervals(intervals, n, result);

    for (int i = 0; i < mergedCount; i++) {
        printf("%d %d\n", result[i][0], result[i][1]);
    }

    return 0;
}
