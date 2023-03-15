#include <iostream>
#include <string>
#include <vector>
#include "DIRECTORY.hpp"

int main() {
    Firms fe("Kamaz", "Kogogin", "8999 999 99 99", "cborochn", "mechanical engineering");
    Firms ve("Vaz", "Kogin", "8999 888 99 99", "Avtocborochn", "mechanical");
    Firms se("Shell", "Koin", "8999 777 99 99", "Avito", "engineering");
    Firms ka("Kama", "power", "8999 666 99 99", "Avto", "mechengineering");

    Directory dir;
    dir.add(fe);
    dir.add(ve);
    dir.add(se);
    dir.add(ka);
    auto f = dir.searchTitle("Kamaz");
    auto e = dir.searchOwner("Kogin");
    auto c = dir.searchPhone("8999 666 99 99");
    auto d = dir.searchAddress("Avito");
    auto z = dir.searchOccupation("engineering");
    z->print();
    dir.add(Firms("Kama", "power", "8999 666 99 99", "Avto", "mechengineering"));
    dir.Print();
    dir.Save();
}
