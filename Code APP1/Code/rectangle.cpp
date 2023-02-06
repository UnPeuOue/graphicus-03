#include "rectangle.h"

Rectangle::Rectangle()
{
    ancrage.x = 0;
    ancrage.y = 0;
    longueur = 1;
    hauteur = 1;
}

Rectangle::~Rectangle()
{
}

void Rectangle::SetLongueur(int l)
{
	if (l <0) longueur = -l;
	else longueur = l;
}

void Rectangle::SetHauteur(int h)
{
	if (h <0) hauteur = -h;
	else hauteur = h;
}
    
int Rectangle::GetLongueur()
{ return longueur; }

int Rectangle::GetHauteur()
{ return hauteur; }

double Rectangle::aire()
{ return longueur*hauteur; }

void Rectangle::afficher(ostream & s)
{
	s << "Rectangle(x=" << ancrage.x << ", y=" << ancrage.y <<
	  ", l=" << longueur << ", h=" << hauteur << ", aire=" <<
	  aire() << ")" << endl;
}


