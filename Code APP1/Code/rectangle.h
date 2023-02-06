#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "forme.h"

class Rectangle : public Forme
{
private:
    int longueur;
    int hauteur;
public:
    Rectangle();
    
    ~Rectangle();
    
    // Setters
    void SetLongueur(int l);
    void SetHauteur(int h); 
    
    // Getters
    int GetLongueur();
    int GetHauteur();
    double aire() override;
    
    void afficher(ostream & s);

};

#endif
