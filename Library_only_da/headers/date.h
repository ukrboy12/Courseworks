#pragma once

struct Day{
    int day;
};

struct Month{
    int month;
};

struct Year{
    int year;
};

struct Date{
    int day;
    int month;
    int year;
};

int getDayIndex(int days, int month, int year);