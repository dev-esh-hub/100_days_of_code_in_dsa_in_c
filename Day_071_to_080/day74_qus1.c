/*
Problem Statement
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
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.
*/

#include <stdio.h>
#include <string.h>

#define MAX 1000
#define NAME_LEN 50

int main() {

    int n;
    printf("Enter number of votes: ");
    scanf("%d", &n);

    char names[MAX][NAME_LEN];

    printf("Enter candidate names:\n");
    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    char unique[MAX][NAME_LEN];
    int count[MAX] = {0};
    int uniqueCount = 0;

    // Count frequencies
    for(int i = 0; i < n; i++) {

        int found = 0;

        for(int j = 0; j < uniqueCount; j++) {
            if(strcmp(names[i], unique[j]) == 0) {
                count[j] += 1;
                found = 1;
                break;
            }
        }

        if(!found) {
            strcpy(unique[uniqueCount], names[i]);
            count[uniqueCount] = 1;
            uniqueCount += 1;
        }
    }

    // Find winner
    char winner[NAME_LEN];
    int maxVotes = -1;

    for(int i = 0; i < uniqueCount; i++) {

        if(count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        }
        else if(count[i] == maxVotes) {
            if(strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}