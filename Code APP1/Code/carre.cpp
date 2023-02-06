#include "carre.h"

Carre::Carre()
{
    ancrage.x = 0;
    ancrage.y = 0;
    cote = 1;
}

Carre::~Carre()
{
}

void Carre::SetCote(int c)
{
	if (c < 0) cote = -c;
	else cote = c;
}
    
int Carre::GetCote()
{ return cote; }

double Carre::aire()
{ return cote*cote; }

void Carre::afficher(ostream & s)
{
	s << "Carre(x=" << ancrage.x << ", y=" << ancrage.y <<
	", c=" << cote << ", aire=" << aire() << ")" << endl;
}



