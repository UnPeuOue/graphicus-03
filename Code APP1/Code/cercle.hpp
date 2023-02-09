#ifndef CERCLE_H
#define CERCLE_H

#include "forme.h"

class Cercle : public Forme
{
private:
    int rayon;
    const float PI = 3.141593;
public:
    Cercle();
    
    ~Cercle();
    
    // Setters
    void SetRayon(int r);
    
    // Getters
    int GetRayon();
    double aire() override;
    
    ostream& afficher(ostream& s);
    
};

//Méthodes
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

ostream& Cercle::afficher(ostream & s)
{
	s << "Cercle(x=" << ancrage.x << ", y=" << ancrage.y <<
	", r=" << rayon << ", aire=" << aire() << ")" << endl;
}

#endif
