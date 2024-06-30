//---------------------------------------------------------------------------

#pragma hdrstop

#include "pomocna.h"
#include <iostream>
#include "pomocna.h"

#include <vcl.h>

#include "Aplikacija.h"
#include <algorithm>
#include "pomocna.h"
#include <string>
#include <utility>

//---------------------------------------------------------------------------

void Tacka::Crtaj(TImage* Slika, TColor boja) {
	int velicina = 3;
	Slika->Canvas->Brush->Color = boja;
	Slika->Canvas->Ellipse(x-velicina, y-velicina, x+velicina, y+velicina);
	Slika->Canvas->Brush->Color = clWhite;
}

void Kruznica::Crtaj(TImage* Slika, TColor boja){
	Slika->Canvas->Pen->Color = boja;
	Slika->Canvas->Ellipse(centar.x-r, centar.y-r, centar.x+r, centar.y+r);
	Slika->Canvas->Pen->Color = clWhite;
}

//---------------------------------------------------------------------------

#pragma package(smart_init)
