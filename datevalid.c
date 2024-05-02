#include <stdio.h>

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1; // Leap year
    else
        return 0; // Not a leap year
}

int isValidDate(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return 0; // Invalid date

    switch(month) {
        case 2:
            if (isLeapYear(year))
                return (day <= 29);
            else
                return (day <= 28);
        case 4: case 6: case 9: case 11:
            return (day <= 30);
        default:
            return (day <= 31);
    }
}

int main() {
    int day, month, year;

    printf("Enter date (DD MM YYYY): ");
    scanf("%d %d %d", &day, &month, &year);

    if (isValidDate(day, month, year))
        printf("Valid date\n");
    else
        printf("Invalid date\n");

    return 0;
}
