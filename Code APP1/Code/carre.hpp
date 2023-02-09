#ifndef CARRE_H
#define CARRE_H 

#include "forme.h"

class Carre : public Forme
{
private:
    int cote;
    
public:
    Carre();
    
    ~Carre();
    
    // Setters
    void SetCote(int c);
    
    // Getters
    int GetCote();
    double aire() override;
    
    // Sortie à l'écran
    ostream& afficher(ostream & s);
};


// Méthodes

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

ostream& Carre::afficher(ostream& s)
{
	return s << "Carre(x=" << ancrage.x << ", y=" << ancrage.y <<
	", c=" << cote << ", aire=" << aire() << ")" << endl;
}


#endif
