#ifndef __EVENT_H__
#define __EVENT_H__
#include <iostream>
#include <cstring>
#include "time.hpp"
#include "date.hpp"

class Event {
    char description[101];    
    Date date;
    Time time;

    void copy(const Event& other) {
        this->date = other.date;
        this->time = other.time;
        strcpy(this->description, other.description);
    }

    public:
    Event(){}
    Event(const char description[], const Date& date, const Time& time) {
        this->date = date;
        this->time = time;
        strcpy(this->description, description);
    }

    Event(const Event& other) {
        copy(other);
    }

    Event& operator=(const Event& other) {
        if (this != &other) {
            copy(other);
        }

        return *this;
    }

    void write(std::ostream& os) const {
        os << description << std::endl;
        date.write(os);
        os << " ";
        time.write(os);
        os << std::endl;
    }

    void read(std::istream& is) {
        is.getline(description, 101);
        date.read(is);
        time.read(is);
    }
};


#endif // __EVENT_H__