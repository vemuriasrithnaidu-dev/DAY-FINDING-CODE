/*
--------------------------------------------------------------------
                       DAY FINDER PROGRAM IN C
--------------------------------------------------------------------

Authors     : <ASRITH>
Language    : C
Project     : Date – Day Calculator
Description :
    This program determines the day of the week for any given date.
    It validates:
        - Correct number of days in each month
        - Leap year February rules (28/29 days)
    It allows re-entry if wrong input is given.
*/

#include <stdio.h>
int isLeap(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
int monthcode(int month) {
    switch(month)
    {
        case 1:  return 0;
        case 2:  return 3;
        case 3:  return 3;
        case 4:  return 6;
        case 5:  return 1;
        case 6:  return 4;
        case 7:  return 6;
        case 8:  return 2;
        case 9:  return 5;
        case 10: return 0;
        case 11: return 3;
        case 12: return 5;
        default: return -1;
    }
}

int yearcode(int year) { return year % 100; }
int leapcode(int year) { return (year % 100) / 4; }
int centurycode(int year) {
    int c = (year / 100 + 1) % 4;
    switch(c)
    {
        case 1: return 6;
        case 2: return 4;
        case 3: return 2;
        case 0: return 0;
    }
    return 0;
}
int inputNumber( char as[]) {
    int num;
    while (1) {
        printf("%s", as);
        if (scanf("%d", &num) != 1) {
            printf("INVALID INPUT! ENTER NUMBERS ONLY.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');
        return num;
    }
}

int main() {
    int date, month, year, maxdays, sum;
    while (1) {
        month = inputNumber("ENTER THE MONTH (1-12): ");
        if (month >= 1 && month <= 12) break;
        printf("INVALID MONTH! PLEASE ENTER 1 TO 12 ONLY.\n");
    }
    while (1) {
        year = inputNumber("ENTER THE YEAR: ");
        if (year >= 1&&year <=3000) break;
        printf("INVALID YEAR! ENTER A POSITIVE NUMBER.\n");
    }
    if (month == 2) {
        maxdays = isLeap(year) ? 29 : 28;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 ||
             month == 8 || month == 10 || month == 12) {
        maxdays = 31;
    }
    else {
        maxdays = 30;
    }
    while (1) {
        printf("ENTER THE DATE (1-%d): ", maxdays);
        if (scanf("%d", &date) != 1) {
            printf("INVALID INPUT! ENTER NUMBERS ONLY.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        if (date >= 1 && date <= maxdays) break;

        printf("INVALID DATE! THIS MONTH HAS ONLY %d DAYS.\n", maxdays);
    }
    sum = date + monthcode(month) + yearcode(year) + leapcode(year) + centurycode(year);
    if (isLeap(year) && (month == 1 || month == 2)) sum--;

    sum %= 7;

    printf("\nTHE DAY ON %02d-%02d-%d IS : ", date, month, year);

    switch(sum) {
        case 0: printf("SUNDAY\n"); break;
        case 1: printf("MONDAY\n"); break;
        case 2: printf("TUESDAY\n"); break;
        case 3: printf("WEDNESDAY\n"); break;
        case 4: printf("THURSDAY\n"); break;
        case 5: printf("FRIDAY\n"); break;
        case 6: printf("SATURDAY\n"); break;
    }

    return 0;
}
