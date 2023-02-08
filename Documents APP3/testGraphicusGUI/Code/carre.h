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
    void afficher(ostream & s);
    
};

#endif
