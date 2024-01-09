#include <iostream>
#include "car.h"

int main() {
    car c1;
    std::cout << "Objekt vytvoren konstruktorem bez parametru" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "SPZ                       " << c1.get_SPZ() << std::endl;
    std::cout << "Spotreba                  " << c1.get_spotrebaPaliva() << " litru na 100 km" << std::endl;
    std::cout << "Rok vyroby                " << c1.get_rokVyroby() << std::endl;
    std::cout << "Stari vozu v letech       " << c1.get_stariVozu() << std::endl;
    car c2("4T16404", 6.5, 2005);
    std::cout << "\nObjekt vytvoren konstruktorem s parametrem" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "SPZ                       " << c2.get_SPZ() << std::endl;
    std::cout << "Spotreba                  " << c2.get_spotrebaPaliva() << std::endl;
    std::cout << "Rok vyroby                " << c2.get_rokVyroby() << std::endl;
    std::cout << "Stari vozu v letech       " << c2.get_stariVozu() << std::endl;
    car c3;
    std::string spz;
    float spotreba;
    int rok;
    std::cout << "\nUzivatelske vstupy" << std::endl;
    std::cout << "------------------" << std::endl;
    std::cout << "Zadej SPZ auta:";
    std::cin >> spz;
    std::cout << "Zadej spotrebu:";
    std::cin >> spotreba;
    std::cout << "Zadej rok vyroby:";
    std::cin >> rok;
    c3.set_SPZ(spz);
    c3.set_spotrebaPaliva(spotreba);
    c3.set_rokVyroby(rok);
    std::cout << "SPZ                       " << c3.get_SPZ() << std::endl;
    std::cout << "Spotreba                  " << c3.get_spotrebaPaliva() << " litru na 100 km" << std::endl;
    std::cout << "Rok vyroby                " << c3.get_rokVyroby() << std::endl;
    std::cout << "Stari vozu v letech       " << c3.ziskejAktualniRocek() << std::endl;
    return 0;
}