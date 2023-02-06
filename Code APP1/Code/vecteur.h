#ifndef VECTEUR_H
#define VECTEUR_H

#include "forme.h"
#include "cercle.h"
#include "rectangle.h"
#include "carre.h"

class Vecteur
{
private:
    Forme** items;
    int capacity;
    int size;
public:
    Vecteur();
	
    ~Vecteur();
 
    // Getters
    int GetSize();
    int GetCapacity();
    bool EstVide();
    Forme* GetItem(int index);
	double Aire();
    
    //Setters
    void Vider(); // DÉTRUIT ÉGALEMENT LES FORMES DU VECTEURS
    
    bool AddItem(Forme* item);
    
    Forme* RemoveItem(int index);
	
	void afficher(ostream & s);
	
	bool Translater(int x, int y);
	
};

#endif
