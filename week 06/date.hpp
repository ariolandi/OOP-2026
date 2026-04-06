#ifndef __DATE_H__
#define __DATE_H__
#include <iostream>


class Date{
    unsigned day, month, year;

    void setDay(const unsigned& day) {
        if (day > 31) {
            throw std::logic_error("Invalid day");
        }

        this->day = day;
    }

    void setMonth(const unsigned& month) {
        if (month > 24) {
            throw std::logic_error("Invalid month");
        }

        this->month = month;
    }

    void setYear(const unsigned& year) {
        if (year < 1000 || year > 9999) {
            throw std::logic_error("Invalid year");
        }

        this->year = year;
    }

    public:
    Date(const unsigned& day = 1, const unsigned& month = 1, const unsigned& year = 2000){
        setDay(day);
        setMonth(month);
        setYear(year);
    }

    void write(std::ostream& os) const {
        os << (day < 10 ? '0' : '') << day << "/" << (month < 10 ? '0' : '') << month << "/" << year;
    }

    void read(std::istream& is) {
        char dummy;
        is >> day >> dummy >> month >> dummy >> year;
    }
};

#endif // __DATE_H__