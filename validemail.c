#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValidEmail(char *email) {
    int atCount = 0;
    int dotCount = 0;
    int len = strlen(email);

    // Check for empty string
    if (len == 0)
        return false;

    // Check for @ and .
    for (int i = 0; i < len; i++) {
        if (email[i] == '@') {
            atCount++;
        } else if (email[i] == '.') {
            dotCount++;
        }
    }

    if (atCount != 1 || dotCount < 1) {
        return false;
    }

    // Check local part (part before @)
    char *localPart = strtok(email, "@");
    if (localPart == NULL || strlen(localPart) == 0) {
        return false;
    }

    // Check domain part (part after @)
    char *domainPart = strtok(NULL, "@");
    if (domainPart == NULL || strlen(domainPart) == 0) {
        return false;
    }

    // Check for consecutive dots
    for (int i = 0; i < len - 1; i++) {
        if (email[i] == '.' && email[i+1] == '.') {
            return false;
        }
    }

    // Check for invalid characters in local part and domain part
    char *invalidChars = "!#$%^&*()+=[]{}|;:,<>?";
    for (int i = 0; i < strlen(invalidChars); i++) {
        if (strchr(localPart, invalidChars[i]) != NULL || strchr(domainPart, invalidChars[i]) != NULL) {
            return false;
        }
    }

    return true;
}

int main() {
    char email[100];
    printf("Enter an email address: ");
    scanf("%s", email);

    if (isValidEmail(email)) {
        printf("Valid email address\n");
    } else {
        printf("Invalid email address\n");
    }

    return 0;
}
