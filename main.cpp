#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "DIRECTORY.hpp"
#include "My_ptr.hpp"

int main() {
    //Задание 1.
//    Firms fe("Kamaz", "Kogogin", "8999 999 99 99", "cborochn", "mechanical engineering");
//    Firms ve("Vaz", "Kogin", "8999 888 99 99", "Avtocborochn", "mechanical");
//    Firms se("Shell", "Koin", "8999 777 99 99", "Avito", "engineering");
//    Firms ka("Kama", "power", "8999 666 99 99", "Avto", "mechengineering");
//
//    Directory dir;
//    dir.add(fe);
//    dir.add(ve);
//    dir.add(se);
//    dir.add(ka);
//    auto f = dir.searchTitle("Kamaz");
//    auto e = dir.searchOwner("Kogin");
//    auto c = dir.searchPhone("8999 666 99 99");
//    auto d = dir.searchAddress("Avito");
//    auto z = dir.searchOccupation("engineering");
//    z->print();
//    dir.add(Firms("Kama", "power", "8999 666 99 99", "Avto", "mechengineering"));
//    dir.Print();
//    dir.Save();

//Задание 2.

    std::shared_ptr<int> s(new int(85));
    std::shared_ptr<int> s2;
    std::cout << s.use_count() << std::endl;
    s2 = s;
    std::cout << s.use_count() << std::endl;

    std::cout << "__________________________________________\n";

    My_shared<int> s1(new int(85));
    My_shared<int> s21;
    My_shared<int> s22;
    std::cout << s1.use_count() << std::endl;
    s21 = s1;
    s22 = s1;
    std::cout << s1.use_count() << std::endl;


}
