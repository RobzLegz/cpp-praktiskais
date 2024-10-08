#ifndef TELEFONS_H
#define TELEFONS_H

#include <string>

class Telefons
{
private:
    std::string modelis;
    int svars;
    float cena;

    static int objektuSkaits; // Statiskā mainīgā deklarācija objektu skaita uzskaitei

public:
    // Noklusējuma konstruktors
    Telefons();

    // Pārslogots konstruktors
    Telefons(std::string modelis, int svars, float cena);

    // Destruktors
    ~Telefons();

    // Set un get metodes katram atribūtam
    void setModelis(const std::string &modelis);
    std::string getModelis() const;

    void setSvars(int svars);
    int getSvars() const;

    void setCena(float cena);
    float getCena() const;

    // Statiskā metode, lai atgrieztu objektu skaitu
    static int getObjektuSkaits();

    // Metode, kas veic aprēķinus
    float rekinsParAtminu(float vienibasCena) const;

    // Pārslogota metode, kas veic aprēķinus
    float rekinsParAtminu(float vienibasCena, float atlaide) const;
};

#endif
