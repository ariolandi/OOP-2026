#ifndef TABLE_HPP
#define TABLE_HPP
#include "string.hpp"
#include "column.hpp"
#include "record.hpp"
#include <iostream>

class Table {
    String title;
    Column** columns;
    size_t columnsCount;

    void copy(const Table& other);
    void move(Table&& other);
    void clear();

    size_t findColumn(const String& header) const;
 public:
	Table(const String& title);
    Table(const Table& other);
    Table& operator=(const Table& other);
    Table(Table&& other);
    Table& operator=(Table&& other);
    ~Table();

    void addColumn(const String& header);
    void addRow(const size_t& recordsCount, const Record records[]);
    void find(const String& id, std::ostream& os) const;
    bool hadTitle(const String& title) const;

    void deleteColumn(const String& header);
    void deleteRow(const String& id);

    void print(std::ostream& os) const;
    void serialize(std::ostream& os) const;
    void deserialize(std::istream& is);
};

void Table::copy(const Table& other) {
    title = other.title;
    columnsCount = other.columnsCount;

    columns = new Column*[columnsCount];

    for (size_t i = 0; i < columnsCount; ++i) {
        columns[i] = new Column(*(other.columns[i]));
    }
}

void Table::move(Table&& other) {
    title = other.title;
    columnsCount = other.columnsCount;

    columns = other.columns;
    other.columns = nullptr;
}

void Table::clear() {
    for (size_t i = 0; i < columnscount; ++i) {
        delete columns[i];
    }
    
    delete[] columns;
}

size_t Table::findColumn(const String& header) const {
    for (size_t i = 0; i < columnsCount; ++i) {
        if (columns[i]->getHeader() == header) {
            return i;
        }
    }

    return columnsCount;
}

Table::Table(const String& title){
    this->title = title;
    columnsCount = 1;
    columns = new Column*[1];
    columns[0] = new Column("id");
}

Table::Table(const Table& other){
    copy(other);
}
Table& Table::operator=(const Table& other){
    if (this != &other) {
        clear();
        copy(other);
    }

    return *this;
}

Table::Table(Table&& other){
    move(std::move(other));
}

Table& Table::operator=(Table&& other){
    if (this != &other) {
        clear();
        move(std::move(other));
    }

    return *this;
}

Table::~Table(){
    clear();
}

void Table::addColumn(const String& header) {
    if (findColumn(header) != columnsCount) {
        throw std::logic_error("Already exists");
    }
    
    Column** tmp = new Column*[columnsCount + 1];

    for (size_t i = 0; i < columnsCount; ++i) {
        tmp[i] = columns[i];
    }

    delete[] columns;
    tmp[columnsCount] = new Column(header, columns[0]->getRowsCount());
    columns = tmp;
    columnsCount ++;
}

void Table::addRow(const size_t& recordsCount, const Record records[]) {
    for (size_t i = 0; i < columnsCount; ++i) {
        bool hasValue = false;
        
        for (size_t j = 0; j < recordsCount && !hasValue; ++j) { 
            if (records[j].key == columns[i]->getHeader()) {
                columns[i]->addValue(records[j].value);
                hasValue = true;
            }
        }

        if (!hasValue) {
            columns[i]->addValue(String());
        }
    }
}

void Table::find(const String& id, std::ostream& os) const {
    size_t idColumn = findColumn(String("id"));

    if (idColumn == columnsCount) {
        throw std::logic_error("Id column does not exist");
    }

    size_t index = columns[idColumn]->getRowIndex(id);
    if (index == columns[idColumn]->getRowsCount()) {
        throw std::out_of_range("No such id");
    } 
    for (size_t j = 0; j < columnsCount; ++j) {
        columns[j]->getHeader().print(os);
        os <<": ";
        columns[j]->getValue(index).print(os);
        os << std::endl;
    }
}

bool Table::hadTitle(const String& title) const {
    return this->title == title;
}


void Table::deleteColumn(const String& header) {
    size_t columnIndex = findColumn(header);

    if (columnIndex == columnsCount) {
        throw std::logic_error("Column does not exist");
    }

    Column** tmp = new Column*[columnsCount - 1];

    size_t j = 0;
    for (size_t i = 0; i < columnsCount; ++i) {
        if (i != columnIndex) {
            tmp[j] = columns[i];
            ++j;

        }
    }

    delete columns[columnIndex];

    columnsCount --;

    delete[] columns;
    columns = tmp;
}

void Table::deleteRow(const String& id) {
        size_t idColumn = findColumn(String("id"));

    if (idColumn == columnsCount) {
        throw std::logic_error("Id column does not exist");
    }

    size_t index = columns[idColumn]->getRowIndex(id);
    if (index == columns[idColumn]->getRowsCount()) {
        throw std::out_of_range("No such id");
    } 
    for (size_t j = 0; j < columnsCount; ++j) {
        columns[j]->deleteValue(index);
    }
}

void Table::print(std::ostream& os) const {
    title.print(os);
    os << std::endl;

    if (columnsCount > 0) {
        size_t rowsCount = columns[0]->getRowsCount();

        for (size_t i = 0; i < rowsCount; ++i) {
            os << "[" << std::endl;
            for (size_t j = 0; j < columnsCount; ++j) {
                os << "    ";
                columns[j]->getHeader().print(os);
                os <<": ";
                columns[j]->getValue(i).print(os);
                os << std::endl;
            }
            os << "]" << std::endl;
        }
    }
}


void Table::serialize(std::ostream& os) const {
    title.serialize(os);

    os << columnsCount << std::endl;
    for (size_t i = 0; i < columnsCount; ++i) {
        columns[i]->serialize(os);
    } 
}

void Table::deserialize(std::istream& is) {
    clear();

    title.deserialize(is);

    is >> columnsCount;
    is.ignore();

    columns = new Column*[columnsCount];
    for (size_t i = 0; i < columnsCount; ++i) {
        Column* newColumn = new Column('');
        newColumn->deserialize(is);
        columns[i] = newColumn;
    }
}

#endif  // TABLE_HPP
