#include "vecteur.h"


Vecteur::Vecteur()
{
	capacity=1;
	items = new Forme*[capacity];
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
    
bool Vecteur::AddItem(Forme* it)
{
	if (it == nullptr) return false;
	size++;

	if (size > capacity)
	{
    	capacity *= 2;
    	Forme** cpyItems = new Forme*[capacity];
		
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
    
Forme* Vecteur::RemoveItem(int index)
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
