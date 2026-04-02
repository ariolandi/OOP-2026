#ifndef __COLUMN__
#define __COLUMN__
#include "string.hpp"

class Column {
    String header;
    String* rows;
    size_t rowsCount;

    void copy(const Column& other);
    void move(Column&& other);
    void clear();

    public:
    Column(const String& header, const size_t& rowsCount = 0);
    Column(const Column& other);
    Column& operator=(const Column& other);
    Column(Column&& other);
    Column& operator=(Column&& other);
    ~Column();

    String getValue(const size_t& index) const;
    String getHeader() const;
    size_t getRowsCount() const;

    void addValue(const String& value);
    void deleteValue(const size_t& index);
    size_t getRowIndex(const String& value) const;

    void serialize(std::ostream& os) const;
    void deserialize(std::istream& is);
};

void Column::copy(const Column& other) {
    header = other.header;
    rowsCount = other.rowsCount;

    rows = new String[rowsCount];

    for (size_t i = 0; i < rowsCount; ++i) {
        rows[i] = other.rows[i];
    }
}

void Column::move(Column&& other) {
    header = std::move(other.header);
    rowsCount = other.rowsCount;

    rows = other.rows;
    other.rows = nullptr;
    other.rowsCount = 0;
}

void Column::clear() {
    delete[] rows;
}

Column::Column(const String& header, const size_t& rowsCount): header(header) {
    this->rowsCount = rowsCount;
    this->rows = new String[rowsCount];
}

Column::Column(const Column& other) {
    copy(other);
}

Column& Column::operator=(const Column& other) {
    if (this != &other) {
        clear();
        copy(other);
    }

    return *this;
}

Column::Column(Column&& other) {
    move(std::move(other));
}

Column& Column::operator=(Column&& other) {
    if (this != &other) {
        clear();
        move(std::move(other));
    }

    return *this;
}

Column::~Column() {
    clear();
}

String Column::getHeader() const {
    return header;
}

String Column::getValue(const size_t& index) const {
    if (index > rowsCount) {
        throw std::out_of_range("Index out of range");
    }

    return rows[index];
}

size_t Column::getRowsCount() const {
    return rowsCount;
}

void Column::addValue(const String& value) {
    String* tmp = new String[rowsCount + 1];

    for (size_t i = 0; i < rowsCount; ++i) {
        tmp[i] = std::move(rows[i]);
    }

    tmp[rowsCount] = value;
    rowsCount ++;

    delete[] rows;
    rows = tmp;
}

void Column::deleteValue(const size_t& index) {
    if (index > rowsCount) {
        throw std::out_of_range("Index out of range");
    }
    
    String* tmp = new String[rowsCount - 1];

    size_t j = 0;
    for (size_t i = 0; i < rowsCount; ++i) {
        if (i != index) {
            tmp[j] = std::move(rows[i]);
            ++j;

        }
    }

    rowsCount --;

    delete[] rows;
    rows = tmp;
}

size_t Column::getRowIndex(const String& value) const {
    for (size_t i = 0; i < rowsCount; ++i) {
        if(rows[i] == value) return i;
    } 

    return rowsCount;
}


void Column::serialize(std::ostream& os) const {
    header.serialize(os);

    os << rowsCount << std::endl;
    for (size_t i = 0; i < rowsCount; ++i) {
        rows[i].serialize(os);
    } 
}

void Column::deserialize(std::istream& is) {
    clear();

    header.deserialize(is);

    is >> rowsCount;
    is.ignore();

    rows = new String[rowsCount];
    for (size_t i = 0; i < rowsCount; ++i) {
        rows[i].deserialize(is);
    }
}

#endif