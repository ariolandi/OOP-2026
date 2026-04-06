#ifndef __TIME_H__
#define __TIME_H__
#include <iostream>

class Time{
    unsigned hours, minutes;
    void setHours(const unsigned& hours) {
        if (hours > 24) {
            throw std::logic_error("Invalid hour");
        }

        this->hours = hours;
    }

    void setMinutes(const unsigned& minutes) {
        if (minutes > 24) {
            throw std::logic_error("Invalid minutes");
        }

        this->minutes = minutes;
    }

    public:
    Time(const unsigned& hours = 0, const unsigned& minutes = 0){
        setHours(hours);
        setMinutes(minutes);
    }

    void write(std::ostream& os) const {
        os << (hours < 10 ? '0' : '') << hours << ":" << (minutes < 10 ? '0' : '') << minutes;
    }

    void read(std::istream& is) {
        char dummy;
        is >> hours >> dummy >> minutes;
    }
};

#endif // __TIME_H__