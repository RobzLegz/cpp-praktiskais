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
    float getVidBenzinaPaterins() const;
    int getSedvietuSkaits() const;
    string getMarka() const;

    void setVidBenzinaPaterins(float paterins);
    void setSedvietuSkaits(int sedvietuSkaits);
    void setMarka(string marka);

    void printAutoData() const;
    float getCelaBenzins(float km) const;
};

// Funkciju definīcijas ārpus klases

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
         << "Videjais benzina paterins: " << vidBenzinaPaterins << " L/100km" << endl
         << "Sedvietu skaits: " << sedvietuSkaits << endl;
}

float Auto::getCelaBenzins(float km) const
{
    return (vidBenzinaPaterins / 100) * km;
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
            cout << "Lūdzu, ievadiet pozitivu vertibu." << endl;
        }
    } while (km <= 0);

    float benzinsMansAuto = mansAuto.getCelaBenzins(km);
    float benzinsSkolasAuto = skolasAuto->getCelaBenzins(km);

    cout << "Nepieciesamais benzins manam auto: " << benzinsMansAuto << " L\n";
    cout << "Nepieciesamais benzins skolas auto: " << benzinsSkolasAuto << " L\n";

    delete skolasAuto;

    return 0;
}