/*Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements

Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"

Example:
Input:
3
1 0 0
0 1 0
0 0 1

Output:
Identity Matrix*/
#include <stdio.h>
int main() {

int r1,c1,r2,c2,i,j,identity=1;
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
if(m1[i][j]!=1){
    identity=-1;
}
}
else if(m1[i][j]!=0){
    identity=-1;
  
   
}
   }
   if(identity==-1){
    break;
   }
   }
if(identity==0){
    printf("its a identity matrix");
}
if(identity==-1){
    printf("not a identity matrix");
}













    return 0;
}