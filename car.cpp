#include "car.h"
#include <iostream>
#include <ctime>

car::car() {
    // Defaultní inicializace hodnot
    SPZ = "NO_SPZ";
    spotrebaPaliva = 0.1;
    rokVyroby = 1900;
    stariVozu = ziskejAktualniRok(rokVyroby); // Získání věku vozu
}

// Metoda pro získání věku vozu na základě roku výroby
int car::ziskejAktualniRok(int rokVyroby) {
    std::time_t systemTime = std::time(nullptr);
    std::tm* currentTime = std::localtime(&systemTime);
    int currentYear = currentTime->tm_year + 1900;
    return currentYear - rokVyroby;
}

car::~car() {
    // Prázdný destruktor
}

// Metody pro získání hodnot soukromých členů
std::string car::get_SPZ() const {
    return this->SPZ;
}

float car::get_spotrebaPaliva() const {
    return this->spotrebaPaliva;
}

int car::get_rokVyroby() const {
    return this->rokVyroby;
}

int car::get_stariVozu() const {
    return this->stariVozu;
}

// Metody pro nastavení hodnot soukromých členů s kontrolou platnosti
void car::set_SPZ(std::string spz) {
    if (jePlatnaSPZ(spz)) {
        SPZ = spz;
    } else {
        std::cout << "Neplatna SPZ" << std::endl;
    }
}

void car::set_spotrebaPaliva(float spotreba) {
    if (jeKladnaSpotreba(spotreba)) {
        spotrebaPaliva = spotreba;
    } else {
        std::cout << "Spotreba paliva musi byt kladne cislo" << std::endl;
    }
}

void car::set_rokVyroby(int rok) {
    if (jePlatnyRokVyroby(rok)) {
        rokVyroby = rok;
    } else {
        std::cout << "Neplatny rok vyroby" << std::endl;
    }
}

// Konstruktor s explicitními hodnotami
car::car(std::string spzetka, float spotrebicka, int rocekVyroby) {
    SPZ = spzetka;
    spotrebaPaliva = spotrebicka;
    rokVyroby = rocekVyroby;
    stariVozu = ziskejAktualniRok(rokVyroby); // Získání věku vozu
}

// Metoda pro získání aktuálního roku
int car::ziskejAktualniRocek() {
    std::time_t systemTime = std::time(nullptr);
    std::tm* currentTime = std::localtime(&systemTime);
    int currentYear = currentTime->tm_year + 1900;
    stariVozu = currentYear - rokVyroby; // Aktualizace věku vozu
    return currentYear - rokVyroby;
}

// Metoda pro kontrolu platnosti roku výroby
bool car::jePlatnyRokVyroby(int rok = 2024) {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    int aktualniRok = localTime->tm_year + 1900;
    return rok >= 1900 && rok <= aktualniRok;
}

// Metoda pro kontrolu platnosti registrační značky
bool car::jePlatnaSPZ(std::string SPZ) {
    std::regex pattern("^[A-FH-NPR-TV-Y0-9]{7}$");
    return std::regex_match(SPZ, pattern);
}

// Metoda pro kontrolu kladné spotřeby paliva
bool car::jeKladnaSpotreba(float spotrebaPaliva) {
    return spotrebaPaliva > 0;
}

// Přetížení operátoru << pro výpis informací o voze
std::ostream &operator<<(std::ostream &ok, const car &car) {
    ok << "-------------------------------------------" << std::endl;
    ok << "SPZ                       " << car.get_SPZ() << std::endl;
    ok << "Spotreba                  " << car.get_spotrebaPaliva() << std::endl;
    ok << "Rok vyroby                " << car.get_rokVyroby() << std::endl;
    ok << "Stari vozu v letech       " << car.get_stariVozu() << std::endl;
    return ok;
}
