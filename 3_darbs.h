#ifndef TELEFONS_H
#define TELEFONS_H

#include <string>

class Telefons {
private:
    std::string modelis;  // Telefona modelis
    int atminaGB;         // Telefona atmiņas apjoms GB
    float cena;           // Telefona cena EUR

    static int objektuSkaits;  // Statiskā mainīgā deklarācija objektu skaita uzskaitei

public:
    // Noklusējuma konstruktors
    Telefons();

    // Pārslogots konstruktors
    Telefons(std::string modelis, int atminaGB, float cena);

    // Destruktors
    ~Telefons();

    // Set un Get metodes katram atribūtam
    void setModelis(const std::string &modelis);
    std::string getModelis() const;

    void setAtminaGB(int atminaGB);
    int getAtminaGB() const;

    void setCena(float cena);
    float getCena() const;

    // Statiskā metode, lai atgrieztu objektu skaitu
    static int getObjektuSkaits();

    // Metode, kas veic aprēķinus
    float rekinsParAtminu(float vienibasCena) const;

    // Pārslogota metode, kas veic aprēķinus
    float rekinsParAtminu(float vienibasCena, float atlaide) const;
};

#endif // TELEFONS_H
