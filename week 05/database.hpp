#ifndef __DATABASE_H__
#define __DATABASE_H__
#include <iostream>
#include "table.hpp"

class Database {
    String filename;
    Table** tables;
    size_t tablesCount;
    std::fstream fio;

    void copy(const Database& other);
    void move(Database&& other);
    void clear();

    size_t findTable(const String& title) const;
    void serialize() const;
    void deserialize();
 public:
	Database(const String& name);
    Database(const Database& other);
    Database& operator=(const Database& other);
    Database(Database&& other);
    Database& operator=(Database&& other);
    ~Database();

    void addTable(const Table& table);
    void view(const String& title, std::ostream& os) const;

    void deleteTable(const String& title);

    void print(std::ostream& os) const;
};

void Database::copy(const Database& other) {
    filename = other.filename;
    tablesCount = other.tablesCount;

    tables = new Table*[tablesCount];

    for (size_t i = 0; i < tablesCount; ++i) {
        tables[i] = new Column(*(other.tables[i]));
    }

    fio.open(filename);
}

void Database::move(Database&& other) {
    filename = other.filename;
    tablesCount = other.tablesCount;

    tables = other.tables;
    other.tables = nullptr;

    fio.open(filename);
}

void Database::clear() {                                                                           
    serialize();
    fio.close();

    for(size_ i = 0; i < tablesCount; ++i) {
        delete tables[i];
    }

    delete[] tables;
}

size_t Database::findTable(const String& title) const {
    for (size_t i = 0; i < tablesCount; ++i) {
        if (tables[i]->hasTitle(title)) {
            return i;
        }
    } 

    return tablesCount;
}

void Database::serialize() const {
    fio << tablesCount << std::endl;
    for (size_t i = 0; i < tablesCount; ++i) {
        table[i]->serialize(fio);
    }
}

void Database::deserialize() {
    clear();
    
    fio >> tablesCount;
    fio.ignore();

    tables = new Table*[tablesCount]
    for (size_t i = 0; i < tablesCount; ++i) {
        Table* newTable = new Table('');
        newTable->deserialize(fio);
        tables[i] = newTable;
    }
}

Database::Database(const String& name) {
    this->filename = name;
    fio.open(name);
    tablesCount = 0;
    tables = nullptr;

    deserialize();
}

Database::Database(const Database& other) {
    copy(other);
}

Database& Database::operator=(const Database& other){
    if (this != &other) {
        clear();
        copy(other);
    }

    return *this;
}

Database::Database(Database&& other) {
    move(std::move(other));
}

Database& Database::operator=(Database&& other){
    if (this != &other) {
        clear();
        move(std::move);
    }

    return *this;
}

Database::~Database() {
    clear();
}

void Database::addTable(const Table& table) {
    
}

void Database::view(const String& title, std::ostream& os) const {

}

void Database::deleteTable(const String& title);

void Database::print(std::ostream& os) const;


#endif // __DATABASE_H__