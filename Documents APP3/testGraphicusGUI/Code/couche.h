/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe Couche gere un vecteur de pointeur de formes
 *    geometriques en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

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

#endif
