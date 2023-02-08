#ifndef DESSIN_H
#define DESSIN_H

#define INITIALISEE 0
#define ACTIVE 1
#define INACTIVE 2

#include <iostream>
#include "couche.h"

const int MAX_COUCHES = 5;

using namespace std;

class Canevas
{
public:
   Canevas();
   ~Canevas();
   
   bool reinitialiser();
   
   bool activerCouche(int index);

   
   bool ajouterForme(Forme *p_forme);
   bool retirerForme(int index);
   
   double aire();
   bool translater(int deltaX, int deltaY);
   void afficher(ostream & s);
   
   bool ResetCouche(int index);

private:
     Couche couches[MAX_COUCHES];
     short coucheActive;
};

// Méthodes

Canevas::Canevas()
{
	couches[0].SetStatus(ACTIVE);
	couches[1].SetStatus(INITIALISEE);
	couches[2].SetStatus(INITIALISEE);
	couches[3].SetStatus(INITIALISEE);
	couches[4].SetStatus(INITIALISEE);
	coucheActive = 0;
}

Canevas::~Canevas()
{
}

bool Canevas::reinitialiser()
{
   activerCouche(0);
   for (int i = 0; i < MAX_COUCHES; i++)
   { ResetCouche(i); }
   activerCouche(0);
   return true;
}

bool Canevas::activerCouche(int index)
{
   if (index < 0 || index > 4) return false;
   couches[coucheActive].SetStatus(INACTIVE);
   couches[index].SetStatus(ACTIVE);
   coucheActive = index;
   
   return true;
}

bool Canevas::ajouterForme(Forme *p_forme)
{
   if (coucheActive < 0 || coucheActive > 4) return false;
   
   return couches[coucheActive].AddItem(p_forme);
}

bool Canevas::retirerForme(int index)
{
   if (coucheActive < 0 || coucheActive > 4) return false;
   
   Forme* itemRetire;
   itemRetire = couches[coucheActive].RemoveItem(index);
   
   if (itemRetire == nullptr) return false;
   
   return true;
}

double Canevas::aire()
{
   double aireTotale = 0;
   for (int i = 0; i <MAX_COUCHES; i++)
   {
		aireTotale += couches[i].GetAire();
   }
   
   return aireTotale;
}

bool Canevas::translater(int deltaX, int deltaY)
{
   if (coucheActive < 0 || coucheActive > 4) return false;
   
   return couches[coucheActive].Translater(deltaX, deltaY);
}

void Canevas::afficher(ostream & s)
{
	for (int i = 0; i < MAX_COUCHES; i++)
	{
		s << "----- Couche " << i << endl;
		couches[i].afficher(s);
		
	}
	
}

bool Canevas::ResetCouche(int index)
{
	return couches[index].Reset();
}


#endif
