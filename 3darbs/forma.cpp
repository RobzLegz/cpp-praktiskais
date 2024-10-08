#include <vcl.h>
#pragma hdrstop

#include "forma.h"
#include "Telefons.h"
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

// Formas konstruktors
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    objektiCount = 0;  // Sākumā objektu skaits ir 0
    StringGrid1->Cells[0][0] = "Modelis";
    StringGrid1->Cells[1][0] = "Atmiņa (GB)";
    StringGrid1->Cells[2][0] = "Cena (EUR)";
    ComboBoxMetode->Items->Add("Rēķināt pēc vienības cenas");
    ComboBoxMetode->Items->Add("Rēķināt pēc vienības cenas ar atlaidi");
}

// Pievienot jaunu objektu masīvam un atjaunot StringGrid
void __fastcall TForm1::ButtonPievienotClick(TObject *Sender)
{
    PievienotJaunuObjektu();
    AtjaunotStringGrid();
}

// Metode jauna objekta pievienošanai masīvā
void TForm1::PievienotJaunuObjektu()
{
    if (objektiCount < 10)  // Pārbauda, vai masīvā ir vieta
    {
        // Iegūst atribūtu vērtības no lietotāja ievades laukiem
        String modelis = EditModelis->Text;
        int atmina = StrToInt(EditAtmina->Text);
        float cena = StrToFloat(EditCena->Text);

        // Izveido jaunu telefona objektu un piešķir to masīvā
        telefoni[objektiCount] = new Telefons(modelis.c_str(), atmina, cena);
        objektiCount++;
    }
    else
    {
        ShowMessage("Nav vietas vairāk objektiem!");
    }
}

// Metode, lai atjaunotu StringGrid ar masīva datiem
void TForm1::AtjaunotStringGrid()
{
    for (int i = 0; i < objektiCount; i++)
    {
        StringGrid1->Cells[0][i+1] = telefoni[i]->getModelis().c_str();
        StringGrid1->Cells[1][i+1] = telefoni[i]->getAtminaGB();
        StringGrid1->Cells[2][i+1] = telefoni[i]->getCena();
    }
}

// Izsaukt izvēlēto metodi un parādīt rezultātu
void __fastcall TForm1::ButtonRekinsClick(TObject *Sender)
{
    int rowIndex = StringGrid1->Row - 1; // Izvēlētā rinda StringGridā
    if (rowIndex >= 0 && rowIndex < objektiCount)
    {
        Telefons* telefons = telefoni[rowIndex];

        // Lietotājs izvēlas, kuru metodi izmantot
        int metodeIndex = ComboBoxMetode->ItemIndex;
        float rezultats;

        if (metodeIndex == 0)  // Rēķināt pēc vienības cenas
        {
            float vienibasCena = 5.0;  // Piemērs vienības cenai
            rezultats = telefons->rekinsParAtminu(vienibasCena);
        }
        else if (metodeIndex == 1)  // Rēķināt pēc vienības cenas ar atlaidi
        {
            float vienibasCena = 5.0;  // Piemērs vienības cenai
            float atlaide = 10.0;      // Piemērs atlaidei procentos
            rezultats = telefons->rekinsParAtminu(vienibasCena, atlaide);
        }

        ShowMessage("Rēķina rezultāts: " + FloatToStr(rezultats) + " EUR");
    }
    else
    {
        ShowMessage("Lūdzu, izvēlieties objektu no saraksta!");
    }
}

// Destruktors: iznīcināt visus dinamiski izveidotos objektus
__fastcall TForm1::~TForm1()
{
    for (int i = 0; i < objektiCount; i++)
    {
        delete telefoni[i];
    }
}
