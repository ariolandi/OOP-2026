#ifndef __MY_STRING__
#define __MY_STRING__
#include <cstring>
#include <iostream>

class String {
    char* str;

    void set(const char* str);

    public:
    String();
    String(const char* str);
    String(const String& other);
    String(String&& other);
    String& operator=(const String& other);
    String& operator=(const char* other);
    String& operator=(String&& other);

    ~String();

    bool operator==(const String& other) const;
    bool operator!=(const String& other) const;

    void operator+=(const char* str);

    size_t length() const;
    bool isEmpty() const;
    void print(std::ostream& os) const;

    void serialize(std::ostream& os) const;
    void deserialize(std::istream& is);
};


String::String() {
    str = new char[1];
    str[0] = '\0';
}

String::String(const char* str) {
    set(str);
}

String::String(const String& other) {
    set(other.str);
}

String::String(String&& other) {
    this->str = other.str;
    other.str = 0;
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] this->str;
        set(other.str);
    }
    return *this;
}

String& String::operator=(const char* other) {
    delete[] this->str;
    set(other);
    
    return *this;
}

String& String::operator=(String&& other) {
    if (this != &other) {
        delete[] this->str;
        this->str = other.str;
        other.str = nullptr;
    }
    return *this;
}

String::~String() {
    delete[] str;
}


bool String::operator==(const String& other) const {
    return !strcmp(str, other.str);
}

bool String::operator!=(const String& other) const {
    return !operator==(other);
}

void String::operator+=(const char* str) {
    char* tmp = new char[strlen(this->str) + strlen(str) + 1];
    strcpy(tmp, this->str);
    strcat(tmp, str);

    delete[] this->str;
    set(tmp);
}

void String::set(const char* str) {
    this->str = new char[strlen(str) + 1];
    strcpy(this->str, str);
}

size_t String::length() const {
    return strlen(str);
}

bool String::isEmpty() const {
    return str == nullptr || length() == 0;
}

void String::print(std::ostream& os) const {
    os << str;
}

void String::serialize(std::ostream& os) const {
    os << length() << std::endl;
    os << str << std::endl;
}

void String::deserialize(std::istream& is) {
    size_t size;
    is >> size;
    is.ignore();
    char str[size + 1];
    is.getline(str, size + 1);
    operator=(str);
}

#endif