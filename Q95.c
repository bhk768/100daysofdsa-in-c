/*Problem: Sort array of non-negative integers using counting sort.
Find max, build freq array, compute prefix sums, build output.*/
#include <stdio.h>

// Counting Sort function
void countingSort(int arr[], int n) {
    // Step 1: Find maximum element
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }

    // Step 2: Build frequency array
    int freq[max + 1];
    for (int i = 0; i <= max; i++) freq[i] = 0;
    for (int i = 0; i < n; i++) freq[arr[i]]++;

    // Step 3: Compute prefix sums
    for (int i = 1; i <= max; i++) {
        freq[i] += freq[i - 1];
    }

    // Step 4: Build output array (stable)
    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[freq[arr[i]] - 1] = arr[i];
        freq[arr[i]]--;
    }

    // Copy sorted output back to arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
