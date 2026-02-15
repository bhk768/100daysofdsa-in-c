/*Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

Input:
- First line: two integers m and n
- Next m lines: n integers each

Output:
- Print the sum of the primary diagonal elements

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
15

Explanation:
1 + 5 + 9 = 15*/
#include <stdio.h>
int main(){
int r1,c1,r2,c2,i,j,sum=0;
printf("enter the number of rows and columns in m1");
scanf("%d %d",&r1,&c1);
int m1[r1][c1];
printf("enter the elements of m1");
for(i=0;i<r1;i++){
   for(j=0;j<c1;j++){
scanf("%d",&m1[i][j]);
   }
   
   }

for(i=0;i<r1;i++){
   for(j=0;j<c1;j++){
if(i==j){
sum+=m1[i][j];
}
   }
   
   }

printf("%d",sum);














    return 0;
}