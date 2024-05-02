#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_SYMBOLS 10
#define MAX_TERMINALS 10

char nonTerminals[MAX_SYMBOLS];
char terminals[MAX_TERMINALS];
char productionRules[MAX_RULES][MAX_SYMBOLS];

int numNonTerminals = 0;
int numTerminals = 0;
int numRules = 0;

void addToSet(char set[], char symbol) {
    int i;
    for (i = 0; set[i] != '\0'; i++) {
        if (set[i] == symbol) {
            return;
        }
    }
    set[i] = symbol;
    set[i + 1] = '\0';
}

void findFirst(char nonTerminal, char first[]) {
    int i, j;
    for (i = 0; i < numRules; i++) {
        if (productionRules[i][0] == nonTerminal) {
            if (productionRules[i][3] >= 'a' && productionRules[i][3] <= 'z') {
                addToSet(first, productionRules[i][3]);
            } else {
                findFirst(productionRules[i][3], first);
            }
        }
    }
}

int main() {
    int i;
    char first[MAX_TERMINALS] = "";

    printf("Enter the number of production rules: ");
    scanf("%d", &numRules);

    printf("Enter the grammar rules (in the form A -> alpha): \n");
    for (i = 0; i < numRules; i++) {
        scanf("%s", productionRules[i]);
    }

    for (i = 0; i < numRules; i++) {
        nonTerminals[i] = productionRules[i][0];
    }
    numNonTerminals = i;

    for (i = 0; i < numNonTerminals; i++) {
        printf("FIRST(%c) = { ", nonTerminals[i]);
        findFirst(nonTerminals[i], first);
        printf("%s }\n", first);
        memset(first, 0, sizeof(first));
    }

    return 0;
}
