#ifndef AUTO_CAR_H
#define AUTO_CAR_H

#include <regex>
#include <string>
#include <iostream> // Přidáno pro std::ostream

class car {
private:
    std::string SPZ;
    float spotrebaPaliva;
    int rokVyroby;
    int stariVozu;

    // Privátní metody pro ověření platnosti
    bool jePlatnaSPZ(std::string);
    bool jeKladnaSpotreba(float);
    bool jePlatnyRokVyroby(int);
    int ziskejAktualniRok(int);

public:
    // Konstruktory a destruktor
    car();
    car(std::string, float, int);
    virtual ~car();

    // Přetížení operátoru << pro výpis na std::ostream
    friend std::ostream &operator<<(std::ostream &, const car &);

    // Veřejné metody pro získání hodnot soukromých členů
    std::string get_SPZ() const;
    float get_spotrebaPaliva() const;
    int get_rokVyroby() const;
    int get_stariVozu() const;

    // Veřejné metody pro nastavení hodnot soukromých členů
    void set_SPZ(std::string);
    void set_spotrebaPaliva(float);
    void set_rokVyroby(int);

    // Veřejná metoda pro získání aktuálního roku
    int ziskejAktualniRocek();
};
#endif
