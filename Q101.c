/*Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).*/
#include <stdio.h>
#include <stdlib.h>

// Structure to store value and original index
typedef struct {
    int val;
    int idx;
} Pair;

// Merge function that counts smaller elements
void merge(Pair arr[], int left, int mid, int right, int count[]) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Pair L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    int rightCount = 0; // number of elements taken from right side

    while (i < n1 && j < n2) {
        if (L[i].val <= R[j].val) {
            count[L[i].idx] += rightCount;
            arr[k++] = L[i++];
        } else {
            rightCount++;
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        count[L[i].idx] += rightCount;
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Recursive merge sort
void mergeSort(Pair arr[], int left, int right, int count[]) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);
        merge(arr, left, mid, right, count);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

    Pair arr[n];
    for (int i = 0; i < n; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    int count[n];
    for (int i = 0; i < n; i++) count[i] = 0;

    mergeSort(arr, 0, n - 1, count);

    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }
    return 0;
}
