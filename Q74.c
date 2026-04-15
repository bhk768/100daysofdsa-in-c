/*Problem Statement
Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

Input Format
A single string s.

Output Format
Print the first non-repeating character or '$' if none exists.

Sample Input
geeksforgeeks

Sample Output
f

Explanation
The character 'f' occurs only once in the string and appears before any other non-repeating character.*/
#include <stdio.h>
#include <string.h>

char firstNonRepeating(char *s) {
    int freq[26] = {0};   // frequency array for lowercase letters
    int len = strlen(s);

    // Count frequency of each character
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }

    // Find the first character with frequency = 1
    for (int i = 0; i < len; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$';  // if all characters repeat
}

int main() {
    char s[100];
    scanf("%s", s);

    char result = firstNonRepeating(s);
    printf("%c\n", result);

    return 0;
}
