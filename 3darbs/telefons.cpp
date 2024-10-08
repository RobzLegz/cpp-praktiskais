#include "telefons.h"
#include <iostream>

// Inicializēt statisko mainīgo
int Telefons::objektuSkaits = 0;

// Noklusējuma konstruktors
Telefons::Telefons() : modelis("Nezināms"), svars(0), cena(0.0) {
    objektuSkaits++;
}

// Pārslogots konstruktors
Telefons::Telefons(std::string modelis, int svars, float cena) {
    this->modelis = modelis;    // Norāde uz klases atribūtiem
    this->svars = svars;
    this->cena = cena;
    objektuSkaits++;
}

// Destruktors
Telefons::~Telefons() {
    objektuSkaits--;
}

// Set metodes
void Telefons::setModelis(const std::string &modelis) {
    this->modelis = modelis;
}

void Telefons::setSvars(int svars) {
    this->svars = svars;
}

void Telefons::setCena(float cena) {
    this->cena = cena;
}

// Get metodes
std::string Telefons::getModelis() const {
    return this->modelis;
}

int Telefons::getSvars() const {
    return this->svars;
}

float Telefons::getCena() const {
    return this->cena;
}

// Statiskā metode, lai atgrieztu objektu skaitu
int Telefons::getObjektuSkaits() {
    return objektuSkaits;
}

// Aprēķinu metode: kopējās izmaksas par atmiņas apjomu
float Telefons::rekinsParAtminu(float vienibasCena) const {
    return this->svars * vienibasCena;
}

// Pārslogota aprēķinu metode: izmaksas ar atlaidi
float Telefons::rekinsParAtminu(float vienibasCena, float atlaide) const {
    float pilnaCena = this->svars * vienibasCena;
    return pilnaCena * (1.0 - atlaide / 100.0);
}
