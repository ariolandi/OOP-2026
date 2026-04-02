#ifndef __RECORD_H__
#define __RECORD_H__
#include "string.hpp"

struct Record {
    String key;
    String value;

    Record(const String& key, const String& value): key(key), value(value){}
};

#endif // __RECORD_H__