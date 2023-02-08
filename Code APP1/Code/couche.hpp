#ifndef COUCHE_H
#define COUCHE_H

#include "vecteur.h"

#define INITIALISEE 0
#define ACTIVE 1
#define INACTIVE 2


class Couche
{
private:
	Vecteur* vecteur;
	int status;
public:
	Couche();
	~Couche();
	
	
    Forme* GetItem(int index);
    
    
    bool AddItem(Forme* item);
    
    Forme* RemoveItem(int index);
	
	void afficher(ostream & s);
	
	float GetAire();
	
	bool Translater(int x, int y);
	
	bool Reset();
	
	
	bool SetStatus(short s); //0:INITIALISEE 1:ACTIVE 2:INACTIVE
	

};

// Méthodes
Couche::Couche()
{
	vecteur = new Vecteur;
	status = INITIALISEE;
}

Couche::~Couche()
{ 
	delete vecteur;
}

bool Couche::AddItem(Forme* item)
{
	if (status != ACTIVE) return false;
	return vecteur->AddItem(item);
}

Forme* Couche::RemoveItem(int index)
{
	if (status != ACTIVE) return nullptr;
	return vecteur->RemoveItem(index);
}

Forme* Couche::GetItem(int index)
{
	return vecteur->GetItem(index);
}

float Couche::GetAire()
{
	return vecteur->Aire();
}

bool Couche::Translater(int x, int y)
{
	if (status != ACTIVE) return false;
	vecteur->Translater(x,y);
	return true;
}

bool Couche::Reset()
{
	status = INITIALISEE;
	vecteur->Vider();
	return true;
}

bool Couche::SetStatus(short s)
{
	if (s < 0 || s > 2) return false;
	if (s == INITIALISEE) return false;
	status = s;
	return true;
}

void Couche::afficher(ostream & s)
{
	if (status == INITIALISEE)
	{
		cout << "Couche initialisee" <<endl;
	}
	else if (status == ACTIVE)
	{
		if (GetAire() == 0)
		{ cout << "Couche active" <<endl; }
		else vecteur->afficher(s);
	}
	else
	{
		if (GetAire() == 0)
		{ cout << "Couche inactive" <<endl; }
		else vecteur->afficher(s);
	}	
		
}

#endif
