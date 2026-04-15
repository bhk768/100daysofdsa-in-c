/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store candidate name and vote count
typedef struct {
    char name[100];
    int votes;
} Candidate;

int main() {
    int n;
    scanf("%d", &n);

    Candidate candidates[1000]; // assuming max 1000 unique candidates
    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        char temp[100];
        scanf("%s", temp);

        // Check if candidate already exists
        int found = -1;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(candidates[j].name, temp) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            candidates[found].votes++;
        } else {
            strcpy(candidates[uniqueCount].name, temp);
            candidates[uniqueCount].votes = 1;
            uniqueCount++;
        }
    }

    // Find candidate with maximum votes
    char winner[100];
    int maxVotes = -1;
    for (int i = 0; i < uniqueCount; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            strcpy(winner, candidates[i].name);
        } else if (candidates[i].votes == maxVotes) {
            // Tie → choose lexicographically smaller
            if (strcmp(candidates[i].name, winner) < 0) {
                strcpy(winner, candidates[i].name);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}
