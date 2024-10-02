// Author: Roberts Legzdiņš

#include <iostream>
#include <string>

using namespace std;

class Auto
{
private:
    float vidBenzinaPaterins; // Vidējais benzīna patēriņš litros uz 100 km
    int sedvietuSkaits;
    string marka;

    static int autoSkaits; // Statiskā mainīgā deklarācija

public:
    // Konstruktoru deklarācijas
    Auto();                                           // Noklusējuma konstruktors
    Auto(float paterins, int sedvietas, string mark); // Pārslogots konstruktors
    ~Auto();                                          // Destruktors

    // Metodes, kas neizmaina klases atribūtu vērtības
    void printAutoData() const;
    float getCelaBenzins(float km) const;

    float getCelaIzmaksa(float km) const;
    float getCelaIzmaksa(float km, float cenaPerL) const;

    static int getAutoSkaits(); // Statiskā metode, kas atgriež auto skaitu
};

int Auto::autoSkaits = 0;

// Noklusējuma konstruktors
Auto::Auto()
{
    vidBenzinaPaterins = 21.44;
    sedvietuSkaits = 5;
    marka = "BMW";
    autoSkaits++;
    cout << "Nopirkts jauns auto!" << endl;
    printAutoData();
    cout << "Pašreizējais auto skaits: " << autoSkaits << endl;
}

// Pārslogots konstruktors
Auto::Auto(float paterins, int sedvietas, string autoMarka)
{
    vidBenzinaPaterins = paterins;
    sedvietuSkaits = sedvietas;
    marka = autoMarka;
    autoSkaits++;
    cout << "Nopirkts jauns auto!" << endl;
    printAutoData();
    cout << "Pašreizējais auto skaits: " << autoSkaits << endl;
}

// Destruktors
Auto::~Auto()
{
    autoSkaits--;
    cout << "Auto tika norakstīts." << endl;
    printAutoData();
    cout << "Pašreizējais auto skaits: " << autoSkaits << endl;
}

void Auto::printAutoData() const
{
    cout << "Auto data:" << endl
         << "Marka: " << marka << endl
         << "Vidējais benzīna patēriņš: " << vidBenzinaPaterins << " L/100km" << endl
         << "Sēdvietu skaits: " << sedvietuSkaits << endl
         << endl;
}

float Auto::getCelaBenzins(float km) const
{
    return (vidBenzinaPaterins / 100) * km;
}

// getCelaIzmaksa ar noklusēto degvielas cenu
float Auto::getCelaIzmaksa(float km) const
{
    float noklusejamaCena = 1.50; // Degvielas cena 1.50 EUR par litru
    return getCelaBenzins(km) * noklusejamaCena;
}

// Pārslogota getCelaIzmaksa metode
float Auto::getCelaIzmaksa(float km, float cenaPerL) const
{
    return getCelaBenzins(km) * cenaPerL;
}

// Metodes getAutoSkaits deklarācija ārpus klases
int Auto::getAutoSkaits()
{
    return autoSkaits;
}

// Global objects
Auto mansAuto, *skolasAuto; // Pointer to skolasAuto

int main()
{
    skolasAuto = new Auto(25.62, 10, "Audi"); // Dynamic object allocation

    float km;
    do
    {
        cout << "Ievadi distanci km, kur gribat braukt: ";
        cin >> km;

        if (km <= 0)
        {
            cout << "Lūdzu, ievadiet pozitīvu vērtību." << endl;
        }
    } while (km <= 0);

    float benzinsMansAuto = mansAuto.getCelaBenzins(km);
    float benzinsSkolasAuto = skolasAuto->getCelaBenzins(km);

    cout << "Nepieciešamais benzīns manam auto: " << benzinsMansAuto << " L" << endl;
    cout << "Nepieciešamais benzīns skolas auto: " << benzinsSkolasAuto << " L" << endl
         << endl;

    cout << "Izmaksas manam auto ar noklusēto benzīna cenu: " << mansAuto.getCelaIzmaksa(km) << " EUR" << endl;
    cout << "Izmaksas skolas auto ar noklusēto benzīna cenu: " << skolasAuto->getCelaIzmaksa(km) << " EUR" << endl
         << endl;

    float degvielasCena;
    cout << "Ievadi degvielas litra cenu: ";
    cin >> degvielasCena;
    cout << "Izmaksas manam auto ar cenu " << degvielasCena << " EUR/l: " << mansAuto.getCelaIzmaksa(km, degvielasCena) << " EUR" << endl;
    cout << "Izmaksas skolas auto ar cenu " << degvielasCena << " EUR/l: " << skolasAuto->getCelaIzmaksa(km, degvielasCena) << " EUR" << endl
         << endl;

    Auto *draugaAuto = new Auto(24.5, 7, "Toyota");
    cout << "Drauga auto dati:" << endl;
    draugaAuto->printAutoData();

    cout << "Drauga auto izmaksas ar noklusēto cenu: " << draugaAuto->getCelaIzmaksa(km) << " EUR" << endl;
    cout << "Drauga auto izmaksas ar cenu " << degvielasCena << " EUR/l: " << draugaAuto->getCelaIzmaksa(km, degvielasCena) << " EUR" << endl
         << endl;

    cout << "Kopā automašīnas, kas tika iegādātas: " << Auto::getAutoSkaits() << endl;

    // Dinamisko objektu iznīcināšana
    delete skolasAuto;
    delete draugaAuto;

    cout << "Pašreizējais auto skaits pēc auto izdzēšanas: " << Auto::getAutoSkaits() << endl;

    return 0;
}
