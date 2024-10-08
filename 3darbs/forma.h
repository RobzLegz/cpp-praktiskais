#ifndef FormaH
#define FormaH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include "telefons.h"  // Iekļauj klases Telefons .h failu

class TForm1 : public TForm
{
__published:    // Komponenti, kas būs uz formas
    TEdit *EditModelis;
    TEdit *EditAtmina;
    TEdit *EditCena;
    TButton *ButtonPievienot;
    TStringGrid *StringGrid1;
    TComboBox *ComboBoxMetode;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TButton *ButtonRekins;
    
    void __fastcall ButtonPievienotClick(TObject *Sender);
    void __fastcall ButtonRekinsClick(TObject *Sender);

private:    // Privātā daļa
    Telefons *telefoni[10];  // Masīvs no norādēm uz Telefons klases objektiem
    int objektiCount;        // Izveidoto objektu skaits

public:     // Publiskā daļa
    __fastcall TForm1(TComponent* Owner);
    void PievienotJaunuObjektu();  // Metode jauna objekta pievienošanai
    void AtjaunotStringGrid();     // Atjauno StringGrid ar datiem
};

#endif
