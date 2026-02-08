/*Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32*/
#include <stdio.h>


int power(int a, int n) {
    if (n == 0) {
        return 1;  
    } else {
        return a * power(a, n - 1);  
    }
}

int main() {
    int a, n;
    printf("Enter base and exponent (a b): ");
    scanf("%d %d", &a, &n);

    int ans = power(a, n);
    printf("%d^%d = %d\n", a, n, ans);

    return 0;
}