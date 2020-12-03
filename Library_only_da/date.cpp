#include "headers/date.h"

int getDayIndex(int days, int month, int year){
    int daysOfTheMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    for (int i = 0; i < month - 1; i++)
    {
        days += daysOfTheMonth[i];
    }
    if ( year%4==0 and year%100==0 and year%400==0){
        days += 1;
    }
    return days;
}
