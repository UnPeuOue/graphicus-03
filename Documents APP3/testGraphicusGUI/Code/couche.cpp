/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"


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



