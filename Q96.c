/*Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.*/
#include <stdio.h>
#include <stdlib.h>

// Insertion sort for individual buckets
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bucket Sort function
void bucketSort(float arr[], int n) {
    // Step 1: Create n empty buckets
    float *buckets[n];
    int bucketSizes[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = (float *)malloc(n * sizeof(float));
        bucketSizes[i] = 0;
    }

    // Step 2: Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bi = (int)(n * arr[i]); // bucket index
        buckets[bi][bucketSizes[bi]++] = arr[i];
    }

    // Step 3: Sort each bucket
    for (int i = 0; i < n; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
        }
    }

    // Step 4: Concatenate all buckets
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[idx++] = buckets[i][j];
        }
        free(buckets[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    float arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }

    return 0;
}
