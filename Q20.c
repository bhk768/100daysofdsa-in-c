/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/
#include <stdio.h>
#include <stdlib.h>
int main(){
int n,i,j,k;
printf("enter the number of elements");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elements of the array");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int min_sum=__INT_MAX__;
int right,left,temp,sum=0,ans1,ans2;
right=n-1;
left=0;
for(i=0;i<n;i++){
    for(j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
while(left<right){
sum=arr[left]+arr[right];
if(abs(sum)<abs(min_sum)){
    min_sum=sum;
ans1=arr[left];
ans2=arr[right];
}
if(sum<0){
    left++;
}
else{
    right--;
}
}
printf("%d %d",ans1,ans2);









    return 0;
}