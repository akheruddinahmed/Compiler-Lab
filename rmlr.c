#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int noOfprod = 2;
char G[2][10] = {"A->Ab", "A->c"};
int newchar = 90;

char getNewChar() {
    return newchar--;
}

char *substr(int i, int j) {
    int k = 0;
    char *arr = (char *)malloc(10 * sizeof(char));
    while (G[i][j] != '\0') {
        arr[k] = G[i][j];
        j++, k++;
    }
    arr[k] = '\0';
    return arr;
}

void removeLR(int i, int j) {
    char *alpha = substr(i, 4);
    char *beta = substr(j, 3);
    char z[2] = {getNewChar(), '\0'};
    char p1[10] = {G[i][0], '_', '>', '\0'};
    char p2[10] = {z[0], '_', '>', '\0'};
    strcat(p1, beta);
    strcat(p2, alpha);
    printf("After left recursion removed\n");
    printf("%s\n", p1);
    printf("%s\n", p2);
}

int main() {
    int i, j;
    for (i = 0; i < noOfprod; i++) {
        if (G[i][0] == G[i][3]) {
            for (j = 0; j < noOfprod; j++) {
                if (i != j && G[i][0] == G[j][0] && G[j][3] != G[j][0]) {
                    removeLR(i, j);
                }
            }
        }
    }
    return 0;
}
