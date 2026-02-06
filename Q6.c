/*Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed*/
#include <stdio.h>
int main(){
int p,i,q,k,j;
printf("enter the number of entries in log1");
scanf("%d",&p);
int arr[p];
printf("enter the entries");
for(i=0;i<p;i++){
scanf("%d",&arr[i]);
}
printf("enter the number of entries in log2");
scanf("%d",&q);
int arr1[q];
printf("enter the entries");
for(i=0;i<q;i++){
scanf("%d",&arr1[i]);
}
int new[p+q];
i=0,j=0,k=0;
while(i<p && j<q){
if(arr[i]<=arr1[j]){
    new[k++]=arr[i++];
}
else{
    new[k++]=arr1[j++];
}
while(i<p){
    new[k++]=arr[i++];
}
while(j<q){
    new[k++]=arr1[j++];
}
for(i=0;i<p+q;i++){
printf("%d ",new[i]);
}
}

















return 0;
}