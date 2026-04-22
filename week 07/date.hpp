#ifndef __DATE_H__
#define __DATE_H__
#include <ctime>
#include <iostream>

class Date {
    unsigned year;
    unsigned month;
    unsigned day;

    public:
        Date();
};

Date::Date() {
    time_t now = time(nullptr); 
    tm *ltm = localtime(&now);

    year = ltm->tm_year + 1900;
    month = ltm->tm_mon + 1;
    day = ltm->tm_mday;
}

#endif // __DATE_H__