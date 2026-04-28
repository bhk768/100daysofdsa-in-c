/*Problem: Implement Binary Search Iterative - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64*/
#include <stdio.h>

int binarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;  // Found at index mid
        else if (arr[mid] < x)
            low = mid + 1;  // Search right half
        else
            high = mid - 1; // Search left half
    }
    return -1; // Not found
}

int main() {
    int n, x;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &x); // Target element to search

    int result = binarySearch(arr, n, x);

    if (result != -1)
        printf("%d\n", result);  // Print index if found
    else
        printf("-1\n");          // Print -1 if not found

    return 0;
}
