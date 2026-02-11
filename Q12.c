/*Problem: Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the first matrix
- Next m lines: n integers each representing the elements of the second matrix

Output:
- Print the resultant matrix after addition, with each row on a new line and elements separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9
9 8 7
6 5 4
3 2 1

Output:
10 10 10
10 10 10
10 10 10

Explanation:
Each element of the result matrix is the sum of the corresponding elements from the two input matrices.

Test Cases:

Test Case 1:
Input:
2 2
1 2
3 4
5 6
7 8
Output:
6 8
10 12

Test Case 2:
Input:
1 3
10 20 30
1 2 3
Output:
11 22 33

Test Case 3:
Input:
3 1
1
2
3
4
5
6
Output:
5
7
9*/
#include <stdio.h>
int main(){
int r1,c1;
int i,j,r2,c2;
printf("enter the number of rows and columns in m1");
scanf("%d %d",&r1,&c1);
int m1[r1][c1];
printf("enter the number of rows and columns in m2");
scanf("%d %d",&r2,&c2);
int m2[r2][c2];

printf("enter the rows and columns  of m1");
for(i=0;i<r1;i++){
    for(j=0;j<c1;j++){
        scanf("%d",&m1[i][j]);

    }
}
printf("enter the rows and columns  of m2");
for(i=0;i<r2;i++){
    for(j=0;j<c2;j++){
scanf("%d",&m2[i][j]);
    }
}
int m3[r1][c1];
if((r1==r2) && (c1==c2)){
for(i=0;i<r1;i++){
    for(j=0;j<c1;j++){
        m3[i][j]=m1[i][j]+m2[i][j];
    }
}

}
for(i=0;i<r1;i++){
    for(j=0;j<c1;j++){
        printf("%d ",m3[i][j]);
    }
    printf("\n");
}





















    return 0;
}