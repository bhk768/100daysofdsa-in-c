/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/
#include <stdio.h>
#include <string.h>
int main(){
int length,i;
char s[100];
printf("enter a string");
scanf("%s",s);
length=strlen(s);
int flag=-1;
char *first=&s[0];
char *last=&s[length-1];
while(first<=last){
   if(*first!=*last){
    flag=0;
   }
    first++;
    last--;
}
if(flag==-1){
    printf("its palindrome");
}
else{
    printf("its not ");
}









    return 0;
}