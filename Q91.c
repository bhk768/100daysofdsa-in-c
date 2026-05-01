/*Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.*/
#include <stdio.h>

// Function to check if boards can be painted within given maxTime
int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime) return 0; // single board exceeds limit

        if (currentSum + boards[i] > maxTime) {
            painters++;
            currentSum = boards[i];
            if (painters > k) return 0;
        } else {
            currentSum += boards[i];
        }
    }
    return 1;
}

// Function to find minimum time
int minTime(int boards[], int n, int k) {
    int low = 0, high = 0, result = -1;

    for (int i = 0; i < n; i++) {
        high += boards[i]; // sum of all boards
        if (boards[i] > low) low = boards[i]; // largest board
    }

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(boards, n, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%d\n", minTime(boards, n, k));
    return 0;
}
