#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

int n;
char prod[MAX][MAX];
char nonTerminals[MAX];
char terminals[MAX];
int ntCount = 0;
int tCount = 0;

void findFirst(char, int, int);
void findFollow(char, char);

int main() {
    int i;
    char choice;
    char start;

    printf("Enter the number of productions: ");
    scanf("%d", &n);

    printf("Enter the productions:\n");
    for(i = 0; i < n; i++)
        scanf("%s", prod[i]);

    printf("Enter the start symbol: ");
    scanf(" %c", &start);

    // Finding Non-Terminals
    for(i = 0; i < n; i++) {
        nonTerminals[ntCount++] = prod[i][0];
    }

    // Finding Terminals
    for(i = 0; i < n; i++) {
        int j;
        for(j = 3; j < strlen(prod[i]); j++) {
            if(!isupper(prod[i][j]) && prod[i][j] != '|' && prod[i][j] != '#') {
                terminals[tCount++] = prod[i][j];
            }
        }
    }

    // Removing Duplicates from Terminals
    for(i = 0; i < tCount-1; i++) {
        int j;
        for(j = i+1; j < tCount; j++) {
            if(terminals[i] == terminals[j]) {
                int k;
                for(k = j; k < tCount - 1; k++)
                    terminals[k] = terminals[k+1];
                tCount--;
                j--;
            }
        }
    }

    // Calculating FIRST and FOLLOW sets
    printf("\nFIRST and FOLLOW sets:\n");
    printf("------------------------\n");
    printf("Non-terminals: ");
    for(i = 0; i < ntCount; i++)
        printf("%c ", nonTerminals[i]);
    printf("\n");

    printf("Terminals: ");
    for(i = 0; i < tCount; i++)
        printf("%c ", terminals[i]);
    printf("\n");

    for(i = 0; i < ntCount; i++)
        findFirst(nonTerminals[i], 0, 0);

    printf("\n");

    for(i = 0; i < ntCount; i++)
        findFollow(nonTerminals[i], start);

    return 0;
}

void findFirst(char c, int row, int col) {
    int i, j, k;

    if(!isupper(c)) {
        printf("FIRST(%c) = {%c}\n", c, c);
        return;
    }

    for(i = 0; i < n; i++) {
        if(prod[i][0] == c) {
            if(prod[i][3] == '#') {
                findFirst(c, i, 4);
            } else if(!isupper(prod[i][3])) {
                printf("FIRST(%c) = {%c}\n", c, prod[i][3]);
            } else {
                findFirst(prod[i][3], i, 3);
            }
        }
    }
}

void findFollow(char c, char start) {
    int i, j, k;

    if(c == start) {
        printf("FOLLOW(%c) = {$}\n", c);
    }

    for(i = 0; i < n; i++) {
        for(j = 3; j < strlen(prod[i]); j++) {
            if(prod[i][j] == c) {
                if(prod[i][j+1] != '\0') {
                    if(!isupper(prod[i][j+1])) {
                        printf("FOLLOW(%c) = {%c}\n", c, prod[i][j+1]);
                    } else {
                        findFirst(prod[i][j+1], i, j+1);
                    }
                } else {
                    if(prod[i][j] != prod[i][0]) {
                        findFollow(prod[i][0], start);
                    }
                }
            }
        }
    }
}
