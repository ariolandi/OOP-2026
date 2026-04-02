#include <iostream>
#include "table.hpp"
#include <fstream>

int main() {
    // --- String - file read and write
    String a("test"), b;
    std::ofstream fout("test");
    a.serialize(fout);
    fout.close();

    std::ifstream fin("test");
    b.deserialize(fin);
    b.print(std::cout);
    std::cout << std::endl;
    fin.close();

    // --- Column - adding and removing rows
    Column c(String("name"));
    c.addValue("Gosho");
    c.addValue("Ani");
    c.getValue(0).print(std::cout);
    std::cout << std::endl;
    c.deleteValue(0);
    c.getValue(0).print(std::cout);
    std::cout << std::endl;

    // --- Table - adding and removing rows and columns
    Table t(
        String("Table1")
    );
    t.addColumn(String("Column1"));
    const Record row[2] = {Record(String("id"), String("rows1")), Record(String("Column1"), String("value1"))};
    t.addRow(2, row);

    t.print(std::cout);

    return 0;
}
