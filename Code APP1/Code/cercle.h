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
    
    void afficher(ostream & s);
    
};

#endif
