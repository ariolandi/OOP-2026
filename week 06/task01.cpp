#include <iostream>
#include <fstream>
#include "event.hpp"

int main() {
    Event e("some testing event", Date(1, 4, 2026), Time(12));
    std::ofstream fout("testing_file.txt");
    e.write(fout);
    fout.close();

    Event e1;
    std::ifstream fin("testing_file.txt");
    e1.read(fin);
    fin.close();
    e1.write(std::cout);


    return 0;
}
