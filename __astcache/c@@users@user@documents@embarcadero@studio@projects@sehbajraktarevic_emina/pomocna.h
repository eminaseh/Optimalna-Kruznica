//---------------------------------------------------------------------------

#ifndef pomocnaH
#define pomocnaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <vector>

using namespace std;

struct Tacka {
    double x, y;
	Tacka(double x, double y): x(x), y(y){}
	void Crtaj(TImage*, TColor boja = clRed);
};

//---------------------------------------------------------------------------

struct Kruznica {
	Tacka centar;
	double r;
	Kruznica(Tacka centar, double r): centar(centar), r(r){}
	void Crtaj(TImage*, TColor boja = clGreen);
};

//---------------------------------------------------------------------------

#endif
