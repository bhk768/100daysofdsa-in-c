/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored*/
#include <stdio.h>
int main(){
int i,j;
char temp;
char s[100];
printf("enter the code");
scanf("%s",s);
int length=strlen(s);
j=length-1;
for(i=0;i<=j;i++){
    temp=s[i];
s[i]=s[j];
s[j]=temp;
j--;
}
printf("%s",s);












    return 0;
}