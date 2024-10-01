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

public:
    // Konstruktoru deklarācijas
    Auto(); // Noklusējuma konstruktors
    Auto(float paterins, int sedvietas, string mark); // Pārslogots konstruktors
    ~Auto(); // Destruktors

    // Getter un Setter metodes
    float getVidBenzinaPaterins() const;
    int getSedvietuSkaits() const;
    string getMarka() const;

    void setVidBenzinaPaterins(float paterins);
    void setSedvietuSkaits(int sedvietuSkaits);
    void setMarka(string marka);

    void printAutoData() const;
    float getCelaBenzins(float km) const;

    // Jaunas metodes
    float getCelaIzmaksa(float km) const; // Ar noklusēto degvielas cenu
    float getCelaIzmaksa(float km, float cenaPerL) const; // Pārslogota metode ar degvielas cenu
};

// Funkciju definīcijas ārpus klases

// 2.1.1. Noklusējuma konstruktors
Auto::Auto()
{
    vidBenzinaPaterins = 0;
    sedvietuSkaits = 0;
    marka = "Nezināma";
    cout << "Jauna automašīna ir nopirkta!" << endl;
}

// 2.1.3. Pārslogots konstruktors
Auto::Auto(float paterins, int sedvietas, string mark)
{
    vidBenzinaPaterins = paterins;
    sedvietuSkaits = sedvietas;
    marka = mark;
    cout << "Jauna automašīna ir nopirkta!" << endl;
    printAutoData(); // Izvadīt automašīnas datus
}

// 2.1.2. Destruktors
Auto::~Auto()
{
    cout << "Automašīna tika norakstīta. Dati: " << endl;
    printAutoData();
}

// Getter un Setter metodes
float Auto::getVidBenzinaPaterins() const
{
    return vidBenzinaPaterins;
}

int Auto::getSedvietuSkaits() const
{
    return sedvietuSkaits;
}

string Auto::getMarka() const
{
    return marka;
}

void Auto::setVidBenzinaPaterins(float paterins)
{
    this->vidBenzinaPaterins = paterins;
}

void Auto::setSedvietuSkaits(int sedvietuSkaits)
{
    this->sedvietuSkaits = sedvietuSkaits;
}

void Auto::setMarka(string marka)
{
    this->marka = marka; // this - norāde
}

void Auto::printAutoData() const
{
    cout << "Auto data:" << endl
         << "Marka: " << marka << endl
         << "Vidējais benzīna patēriņš: " << vidBenzinaPaterins << " L/100km" << endl
         << "Sēdvietu skaits: " << sedvietuSkaits << endl;
}

float Auto::getCelaBenzins(float km) const
{
    return (vidBenzinaPaterins / 100) * km;
}

// 2.1.4. getCelaIzmaksa ar noklusēto degvielas cenu
float Auto::getCelaIzmaksa(float km) const
{
    float noklusejamaCena = 1.50; // Degvielas cena 1.50 EUR par litru
    return getCelaBenzins(km) * noklusejamaCena;
}

// 2.1.5. Pārslogota getCelaIzmaksa metode
float Auto::getCelaIzmaksa(float km, float cenaPerL) const
{
    return getCelaBenzins(km) * cenaPerL;
}

// Global objects
Auto mansAuto, *skolasAuto; // Pointer to skolasAuto

int main()
{
    skolasAuto = new Auto(); // Dynamic object allocation

    float vidBenzinaPaterins;
    int sedvietuSkaits;
    string marka;

    cout << "Ievadi videjo benzina paterinu uz 100km: ";
    cin >> vidBenzinaPaterins;
    mansAuto.setVidBenzinaPaterins(vidBenzinaPaterins);

    cout << "Ievadi sedvietu skaitu auto: ";
    cin >> sedvietuSkaits;
    mansAuto.setSedvietuSkaits(sedvietuSkaits);

    cout << "Ievadi auto marku: ";
    cin >> marka;
    mansAuto.setMarka(marka);

    mansAuto.printAutoData();

    cout << "Ievadi videjo benzina paterinu uz 100km skolas auto: ";
    cin >> vidBenzinaPaterins;
    skolasAuto->setVidBenzinaPaterins(vidBenzinaPaterins);

    cout << "Ievadi sedvietu skaitu skolas auto: ";
    cin >> sedvietuSkaits;
    skolasAuto->setSedvietuSkaits(sedvietuSkaits);

    cout << "Ievadi skolas auto marku: ";
    cin >> marka;
    skolasAuto->setMarka(marka);

    skolasAuto->printAutoData();

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

    cout << "Nepieciešamais benzīns manam auto: " << benzinsMansAuto << " L\n";
    cout << "Nepieciešamais benzīns skolas auto: " << benzinsSkolasAuto << " L\n";

    // Izmaksas ar noklusēto cenu
    cout << "Izmaksas manam auto ar noklusēto cenu: " << mansAuto.getCelaIzmaksa(km) << " EUR\n";
    cout << "Izmaksas skolas auto ar noklusēto cenu: " << skolasAuto->getCelaIzmaksa(km) << " EUR\n";

    // Izmaksas ar pielāgotu cenu
    float degvielasCena;
    cout << "Ievadi degvielas litra cenu: ";
    cin >> degvielasCena;
    cout << "Izmaksas manam auto ar cenu " << degvielasCena << " EUR/l: " << mansAuto.getCelaIzmaksa(km, degvielasCena) << " EUR\n";
    cout << "Izmaksas skolas auto ar cenu " << degvielasCena << " EUR/l: " << skolasAuto->getCelaIzmaksa(km, degvielasCena) << " EUR\n";

    delete skolasAuto;

    return 0;
}
