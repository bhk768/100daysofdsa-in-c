#include <stdio.h>
/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3*/
#include <stdio.h>

int main() {
    int n,i,j,seen=0;
printf("enter the number of elements");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elements of the array");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
for(i=0;i<n;i++){
seen=0;
for(j=0;j<i;j++){
    if(arr[i]==arr[j]){
        seen=1;
    }
}
if(seen!=1){
    printf("%d",arr[i]);
}
}
    
    return 0;
}