﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Aplikacija.h"
#include <algorithm>
#include "pomocna.h"
#include <string>
#include <utility>
#include <list>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    Slika->Canvas->Brush->Color = clWhite;
	Slika->Canvas->FillRect(Rect(0, 0, Slika->Width, Slika->Height));
}

//---------------------------------------------------------------------------

void __fastcall TForm1::SlikaMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	Tacka nova(X,Y);
	tacke.push_back(nova);
	nova.Crtaj(Slika);
}


//---------------------------------------------------------------------------

void __fastcall TForm1::DugmeOcistiClick(TObject *Sender)
{
	Slika->Canvas->Brush->Color = clWhite;
	Slika->Canvas->FillRect(Rect(0, 0, Slika->Width, Slika->Height));
	Slika->Canvas->Brush->Color = clBlack;
	Slika->Canvas->FrameRect(Rect(0, 0, Slika->Width, Slika->Height));
	Slika->Canvas->Brush->Color = clWhite;

	tacke.clear();

}

//---------------------------------------------------------------------------

void __fastcall TForm1::DugmeGenerisiRandomTackeClick(TObject *Sender)
{
	int broj_tacaka = InputBrojTacakaRandom->Text.ToInt();

	for(int i = 0 ; i < broj_tacaka; i++) {
		tacke.push_back(Tacka(rand() % Slika->Width, rand() % Slika->Height));
		tacke[tacke.size()-1].Crtaj(Slika);
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm1::SlikaMouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
    string koordinate = "X: " + to_string(X) + " Y: " + to_string(Y);
	TextKoordinate->Text = koordinate.c_str();
}

//---------------------------------------------------------------------------

void __fastcall TForm1::DugmeOptimalnaKruznicaBrzoClick(TObject *Sender)
{
   // r je poluprečnik koji se učitava iz Edit polja za unošenje poluprečnika.
   double r = InputPoluprecnik->Text.ToInt();
   // maxBrTacakaUKruznici koristi se za praćenje globalnog najvećeg broja tačaka u kružnici.
   int maxBrTacakaUKruznici = 1;
   // n je veličina vektora tačke.
   int n = tacke.size();
   // optimalnaKruznica služi za praćenje najoptimalnije kružnice.
   Kruznica optimalnaKruznica(Tacka(tacke[0].x+r,tacke[0].y),r);

   // Za svaku tačku se pronalazi njena optimalna kružnica tako što se računa
   // maksimalan broj tačaka koje se mogu naći u kružnici poluprečnika r koju
   // rotiramo oko te tačke.
   // Ako se pronađe kružnica koja sadrži više tačaka od trenutne globalo optimalne
   // kružnice, ažurira se najoptimalnija kružnica.
   for(int i = 0; i < n; i++){
		// Vektor uglovi čuva parove vrijednosti uglova rotacije i bool.
		// Prva komponenta para je double i čuva alpha i beta vrijednosti.
		// alpha predstavlja vrijednost ugla za koji tačka ulazi u kružnicu
		// i za njega je druga komponenta para, bool, jednaka true.
		// beta predstavlja vrijednost ugla za koji tačka izlazi iz kružnice
		// i za njega je druga komponenta para, bool, jednaka false.
		vector<pair<double, bool>> uglovi;

		// Za svaku tačku se računa njena udaljenost od svih ostalih tačaka.
		for(int j = 0; j < n; j++){
			if(i != j){

				double dx = tacke[j].x - tacke[i].x;
				double dy = tacke[j].y - tacke[i].y;
				double dist = sqrt(dx * dx + dy * dy);

				// Ukoliko je udaljenost između tačaka tacke[i] i tacke[j] veća od 2*r
				// tačka tacke[j] ne može ni ući u kružnicu ni izaći iz nje pa se
				//posmatraju samo tačke čija je udaljenost <= 2*r.
				if(dist <= 2*r) {
				// A je ugao između duži čije su krajnje tačke tacke[i] i tacke[j] i x-ose.
				// Računa se po formuli
				// A = tan^(-1)((tacke[i].y - tacke[i].y) / (tacke[j].x - tacke[i].x)).
				double A = atan2(dy,dx);
				// B je ugao između duži čije su krajnje tačke tacke[i] i centar kružnice
				// i duži čije su krajnje tačke tacke[i] i tacke[j].
				// Računa se po formuli B = cos^(-1)(dist/(2*r)) .
				double B = acos(dist / (2 * r));

				// alpha predstavlja vrijednost ugla za koji tačka ulazi u kružnicu.
				double alpha = A-B;
				// beta predstavlja vrijednost ugla za koji tačka izlazi iz kružnice.
				double beta = A+B;

				uglovi.push_back(make_pair(alpha, true));
				uglovi.push_back(make_pair(beta, false));

				}

			}
		}
		// Sortiranje vektora uglovi.
		sort(uglovi.begin(), uglovi.end());
		// brojac se koristi za računanje trenutnog broja tačaka u kružici.
		int brojac = 1;

		// Kroz sortirani vektor uglovi prolazi se u rastućem poretku.
		// brojač se povećava za 1 svaki put kada tačka uđe u kružnicu.
		// brojač se smanjuje za 1 svaki put kada tačka izađe iz kružnice.
		// Druga komponenta u vektoru parova, bool, govori o tome da li je
		// ugao ulazni ili izlazni.
		for(auto it = uglovi.begin(); it!= uglovi.end(); it++){
			// Ako je ugao ulazni, brojač se povećava.
			if((*it).second)
				brojac++;
			else // Ako je ugao izlazni, brojač se smanjuje.
				brojac--;

			// Ako je trenutni broj tačaka u kružnici veći od dosadašnjeg najvećeg
			// broja tačaka, ažuriraju se maxBrTacakaUKruznici i optimalnaKružnica.
			if (brojac > maxBrTacakaUKruznici) {
			maxBrTacakaUKruznici = brojac;

			// Centar kružnice se računa pomoću formula za pretvaranje
			// polarnih koordinata u Kartezijeve koordinate. Polarne koordinate
            // (r,ugao) pretvaraju se u Kartezijeve koordinate (x,y) fomulama:
			// x = r * cos(ugao) i y = r * sin(ugao)
			double centarX = tacke[i].x + r * cos((*it).first);
			double centarY = tacke[i].y + r * sin((*it).first);

			optimalnaKruznica = Kruznica(Tacka(centarX,centarY), r);

			}
		}
   }

   // Iscrtava globalno najoptimalniju kružnicu.
   optimalnaKruznica.Crtaj(Slika);

   // Iscrtava tačke
   // Potrebno je iscrtati ponovo tačke jer se unutrašnjost iscrtane optimalne kružice
   // ispuni nekom bojom.
   for(Tacka& T : tacke)
   	T.Crtaj(Slika);

}
//---------------------------------------------------------------------------

