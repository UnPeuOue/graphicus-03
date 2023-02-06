#include "cercle.h"

Cercle::Cercle()
{
    ancrage.x = 0;
    ancrage.y = 0;
    rayon = 1;
}

Cercle::~Cercle()
{
}

void Cercle::SetRayon(int r)
{
	if (r < 0) rayon = -r;
	else rayon = r;
}

int Cercle::GetRayon()
{ return rayon; }

double Cercle::aire()
{ return PI*rayon*rayon; }

void Cercle::afficher(ostream & s)
{
	s << "Cercle(x=" << ancrage.x << ", y=" << ancrage.y <<
	", r=" << rayon << ", aire=" << aire() << ")" << endl;
}
