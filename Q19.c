/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3*/
#include <stdio.h>
int main(){
int n,i,j,k;
printf("enter the number of elements");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elements of the array");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("enter k");
    scanf("%d",&k);
    int first=0;
    int last=n-1,temp;
    while(first<=last){
        temp=arr[first];
        arr[first]=arr[last];
        arr[last]=temp;
        first++;
        last--;
    }
first=0;
last=k-1;
while(first<=last){
        temp=arr[first];
        arr[first]=arr[last];
        arr[last]=temp;
        first++;
        last--;
    }
first=k;
last=n-1;
while(first<=last){
        temp=arr[first];
        arr[first]=arr[last];
        arr[last]=temp;
        first++;
        last--;
    }
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }



















    return 0;
}