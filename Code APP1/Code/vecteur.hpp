#ifndef VECTEUR_H
#define VECTEUR_H

#include "forme.hpp"
#include "cercle.hpp"
#include "rectangle.hpp"
#include "carre.hpp"

// Forme* par exemple
template <typename T>
class Vecteur
{
private:
    T* items;
    int capacity;
    int size;
public:
    Vecteur();
	
    ~Vecteur();

	// Surcharge d'opérateurs
	const T& operator[] (int index) const
	{
		if (index < size)
			return items[index];
		else
			return nullptr;
	}

	bool operator+= (T it)
	{
		return AddItem(it);
	}

	ostream& operator<<(ostream& os, const Vecteur& v)
	{

	}



 
    // Getters
    int GetSize();
    int GetCapacity();
    bool EstVide();
    Forme* GetItem(int index);
	double Aire();
    
    //Setters
    void Vider(); // DÉTRUIT ÉGALEMENT LES FORMES DU VECTEURS
    
    bool AddItem(T item);
    
    T RemoveItem(int index);
	
	void afficher(ostream & s);
	
	bool Translater(int x, int y);
	
};

// Méthodes
Vecteur::Vecteur()
{
	capacity=1;
	items = new T[capacity];
	size = 0;
}


Vecteur::~Vecteur()
{ 
	Vider();
	delete[] items;
}
    
int Vecteur::GetSize()
{ return size; }

int Vecteur::GetCapacity()
{ return capacity; }

bool Vecteur::EstVide()
{
	for (int i = 0; i <size; i++)
	{
		if (items[i] != nullptr)
		{
			return false;
		}
	}
	return true;
}

Forme* Vecteur::GetItem(int index)
{ 
	Forme* itemCherche = nullptr;
	if (index < 0 || index >= size)
	{ return nullptr; }
	else
	{
		itemCherche = items[index];
		return itemCherche;
	}
}
    
    
//Setters
void Vecteur::Vider()
{
	for (int i = 0; i <size; i++)
	{
		delete items[i];
		items[i] = nullptr;
	}
	size = 0;
	capacity = 1;
}
    
bool Vecteur::AddItem(T it)
{
	if (it == nullptr) return false;
	size++;

	if (size > capacity)
	{
    	capacity *= 2;
    	T* cpyItems = new T[capacity];
		
        for(int i = 0; i < size-1; ++i)
        {
        	cpyItems[i] = items[i];
        }

        delete[] items;

        items = cpyItems;
    }
    
    items[size-1] = it;
    
    return true;
}
    
T Vecteur::RemoveItem(int index)
{
	if (index < 0 || index >= size) return nullptr;
	Forme* itemRemoved = nullptr;
	itemRemoved = items[index];
	for (int i = index; i < size; i++)
	{
		items[i] = items[i+1];
	}
	items[size] = nullptr;
	size--;
	return itemRemoved;
	
}

void Vecteur::afficher(ostream & s)
{
	for (int i = 0; i <size; i++)
	{
		items[i]->afficher(s);
	}
	
}

double Vecteur::Aire()
{
	double aireTotal = 0;
	for (int i = 0; i < size; i++)
	{
		aireTotal += items[i]->aire();
	}
	return aireTotal;
}

bool Vecteur::Translater(int x, int y)
{
	for (int i = 0; i < size; i++)
	{
		items[i]->translater(x,y);
	}
	return true;
}

#endif
