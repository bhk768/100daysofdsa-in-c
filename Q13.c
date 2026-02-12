/*Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the matrix

Output:
- Print "Symmetric Matrix" if the given matrix is symmetric
- Otherwise, print "Not a Symmetric Matrix"

Example:
Input:
3 3
1 2 3
2 4 5
3 5 6

Output:
Symmetric Matrix

Explanation:
The matrix is square (3 × 3) and for every i and j, element[i][j] = element[j][i].

Test Cases:

Test Case 1:
Input:
2 2
1 2
2 1
Output:
Symmetric Matrix

Test Case 2:
Input:
3 3
1 0 1
2 3 4
1 4 5
Output:
Not a Symmetric Matrix

Test Case 3:
Input:
2 3
1 2 3
4 5 6
Output:
Not a Symmetric Matrix*/
#include <stdio.h>
#include <stdlib.h>
int main(){
int r1,c1,r2,c2,i,j,flag=-1;
printf("enter the number of rows and columns in m1");
scanf("%d %d",&r1,&c1);
int m1[r1][c1];
printf("enter the elements of m1");
for(i=0;i<r1;i++){
   for(j=0;j<c1;j++){
scanf("%d",&m1[i][j]);
   }
   
   }
   int **result=(int**)malloc(c1*sizeof(int*));
for(i=0;i<c1;i++){
    result[i]=(int*) malloc(r1*sizeof(int));
}
for(i=0;i<r1;i++){
    for(j=0;j<c1;j++){
        result[j][i]=m1[i][j];
    }
}
for(i=0;i<r1;i++){
    for(j=0;j<c1;j++){
       if(result[i][j]==m1[i][j]){
        
       }
       else{
        flag=0;
       }
    }
}
if(flag==-1)
printf("matrix is symmnetric");
else
printf("matrix is not symmetric");

   return 0;
}













  