/*Problem: Count number of inversions using modified merge sort.
Inversion if i < j and a[i] > a[j].*/
#include <stdio.h>

// Merge two halves and count inversions
long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;     // left subarray index
    int j = mid + 1;  // right subarray index
    int k = left;     // temp array index
    long long invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1); // all remaining elements in left > arr[j]
        }
    }

    // Copy remaining elements
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    // Copy back to original array
    for (i = left; i <= right; i++) arr[i] = temp[i];

    return invCount;
}

// Recursive merge sort + inversion count
long long mergeSortAndCount(int arr[], int temp[], int left, int right) {
    long long invCount = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);

        invCount += mergeAndCount(arr, temp, left, mid, right);
    }
    return invCount;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n], temp[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long invCount = mergeSortAndCount(arr, temp, 0, n - 1);
    printf("%lld\n", invCount);

    return 0;
}
