#include <stdio.h>

int countOccurrences(char[], char[]);

int main() {
    char text[1000], word[1000];

    printf("Enter the string: ");
    gets(text);
    printf("Enter the word to be searched: ");
    gets(word);

    int occurrences = countOccurrences(text, word);
    printf("The word '%s' occurs %d times in the string.", word, occurrences);

    return 0;
}

int countOccurrences(char s[], char w[]) {
    int count = 0, i = 0, t = 0, j = 0;

    while (s[i]) {
        if (s[i] == ' ' || s[i] == 'n' || s[i] == 't') {
            count++;
        }
        i++;
    }

    return count;
}
