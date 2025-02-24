﻿//---------------------------------------------------------------------------

#ifndef AplikacijaH
#define AplikacijaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <vector>
#include "pomocna.h"
#include <queue>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Slika;

	TButton *DugmeOcisti;
	TEdit *InputBrojTacakaRandom;
	TButton *DugmeGenerisiRandomTacke;
	TEdit *TextKoordinate;
	TEdit *InputPoluprecnik;
	TLabel *LabelBrojTacaka;
	TLabel *LabelPoluprecnik;
	TButton *DugmeOptimalnaKruznicaBrzo;
	void __fastcall DugmeOcistiClick(TObject *Sender);
	void __fastcall DugmeGenerisiRandomTackeClick(TObject *Sender);
	void __fastcall SlikaMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall SlikaMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall DugmeOptimalnaKruznicaBrzoClick(TObject *Sender);

private:	// User declarations
	vector<Tacka> tacke;

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
