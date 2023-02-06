/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests. 
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "tests.h"

void Tests::tests_unitaires_formes()
{
	cout << "Tests unitaires Formes" <<endl;
	// Création d'un rectangle 5x8 aux coordonnées (0,0)
	Rectangle* r1 = new Rectangle();
	r1->SetLongueur(5);
	r1->SetHauteur(8);
	r1->afficher(cout);
	
	// Création d'un cercle de rayon 3  aux coordonnées (2,7)
	Cercle* ce1 = new Cercle();
	ce1->SetRayon(3);
	ce1->translater(2, 7);
	ce1->afficher(cout);
	
	// Création d'un carre de côté unitaire aux coordonnées (-5,1)
	Carre* c1 = new Carre();
	c1->translater(-5, 1);
	c1->afficher(cout);
	
	// Création d'un carre de côté 2.46 aux coordonnées (0,0)
	Carre* c2 = new Carre();
	c2->SetCote(2.46);
	c2->afficher(cout);
	
	// Création d'un rectangle -6x2 aux coordonnées (-1,-1)
	Rectangle* r2 = new Rectangle();
	r2->SetLongueur(-6);
	r2->SetHauteur(2);
	r2->translater(-1, -1);
	r2->afficher(cout);
	
	cout <<endl<<endl;
}

void Tests::tests_unitaires_vecteur()
{
	cout << "Tests unitaires Vecteurs" <<endl;
	// Formes utilisées
	Rectangle* r1 = new Rectangle();
	r1->SetLongueur(5);
	r1->SetHauteur(8);
	
	Cercle* ce1 = new Cercle();
	Carre* c1 = new Carre();
	Carre* c2 = new Carre(); 
	Carre* c3 = new Carre();
	Carre* c4 = new Carre();
	
	Vecteur v1;
	cout << "Taille du vecteur: " << v1.GetSize() << endl;
	cout << "Capacité du vecteur: " << v1.GetCapacity() << endl;
	
	cout << "Contenu du vecteur: " << endl; v1.afficher(cout);
	
	cout << endl;
	
	cout << "Ajout de 6 formes au vecteur" << endl;
	v1.AddItem(r1); v1.AddItem(ce1); v1.AddItem(c1); v1.AddItem(c2);
	v1.AddItem(c3); v1.AddItem(c4);
	
	cout << "Taille du vecteur: " << v1.GetSize() << endl;
	cout << "Capacité du vecteur: " << v1.GetCapacity() << endl;
	
	cout << "Contenu du vecteur: " << endl; v1.afficher(cout);
	
	cout << endl;
	
	cout << "Retrait des trois dernières formes" << endl;
	v1.RemoveItem(5); v1.RemoveItem(4); v1.RemoveItem(3);
	
	cout << "Taille du vecteur: " << v1.GetSize() << endl;
	cout << "Capacité du vecteur: " << v1.GetCapacity() << endl;
	
	cout << "Contenu du vecteur: " << endl; v1.afficher(cout);
	
	cout << endl;
	
	cout << "Retrait de la première forme" << endl;
	v1.RemoveItem(0);
	
	cout << "Taille du vecteur: " << v1.GetSize() << endl;
	cout << "Capacité du vecteur: " << v1.GetCapacity() << endl;
	
	cout << "Contenu du vecteur: " << endl; v1.afficher(cout);
	
	cout << endl;
	
	cout << "Translation des formes du vecteur de (-5, 10)" << endl;
	v1.Translater(-5, 10);
	
	cout << "Contenu du vecteur: " << endl; v1.afficher(cout);
	
	cout << endl;
	
	cout << "Réinitialisation du vecteur" << endl;
	v1.Vider();
	
	cout << "Taille du vecteur: " << v1.GetSize() << endl;
	cout << "Capacité du vecteur: " << v1.GetCapacity() << endl;
	
	cout <<endl<<endl;
}

void Tests::tests_unitaires_couche()
{
	cout << "Tests unitaires Couche" <<endl;
	Couche co1;
	Rectangle* r1 = new Rectangle();
	Cercle* ce1 = new Cercle();
	Carre* c1 = new Carre();
	
	cout << "État de la couche au départ" <<endl;
	co1.afficher(cout);
	cout << endl;
	
	
	cout << "Ajout d'un item à l'état initialisée" <<endl;
	co1.AddItem(r1);
	
	co1.afficher(cout);
	cout << "L'aire de la couche est: " << co1.GetAire() << endl;
	cout << endl;
	
	
	cout << "Ajout d'un item à l'état active" <<endl;
	co1.SetStatus(ACTIVE);
	
	co1.AddItem(r1); co1.AddItem(c1);
	
	co1.afficher(cout);
	cout << "L'aire de la couche est: " << co1.GetAire() << endl;
	cout << endl;
	
	
	cout << "Retrait d'un item à l'état active" <<endl;
	co1.RemoveItem(0);
	
	co1.afficher(cout);
	cout << "L'aire de la couche est: " << co1.GetAire() << endl;
	cout << endl;
	
	
	cout << "Translation à l'état active" <<endl;
	co1.Translater(2,6);
	
	co1.afficher(cout);
	cout << "L'aire de la couche est: " << co1.GetAire() << endl;
	cout << endl;
	
	
	cout << "Réinitialisation de la couche" <<endl;
	co1.Reset();
	
	co1.afficher(cout);
	cout << "L'aire de la couche est: " << co1.GetAire() << endl;
	
	cout <<endl<<endl;
}

void Tests::tests_unitaires_canevas()
{
	cout << "Tests unitaires Canevas" <<endl;
	Canevas can;
	Rectangle* r1 = new Rectangle();
	Cercle* ce1 = new Cercle();
	Carre* c1 = new Carre();
	
	
	cout << "État du canevas au départ" <<endl;
	can.afficher(cout);
	cout << "L'aire du canevas est: " << can.aire() << endl;
	cout << endl;
	
	
	cout << "Activer la couche 2" <<endl;
	can.activerCouche(2);
	can.afficher(cout);
	cout << "L'aire du canevas est: " << can.aire() << endl;
	cout << endl;
	
	
	cout << "Ajouter un rectangle, un carre et un cercle unitaires"<<endl;
	can.ajouterForme(r1); can.ajouterForme(ce1); can.ajouterForme(c1);
	can.afficher(cout);
	cout << "L'aire du canevas est: " << can.aire() << endl;
	cout << endl;
	
	
	cout << "Réinitialiser le canevas"<<endl;
	can.reinitialiser();
	can.afficher(cout);
	cout << "L'aire du canevas est: " << can.aire() << endl;
	cout << endl;
	
	cout <<endl<<endl;
}

void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   tests_unitaires_formes();
   tests_unitaires_vecteur();
   tests_unitaires_couche();
   tests_unitaires_canevas();
}

void Tests::tests_application()
{
   // Fait tous les tests applicatifs
   tests_application_cas_01();
   tests_application_cas_02();
   tests_unitaires();

   
}

void Tests::tests_application_cas_01()
{
   cout << "TESTS APPLICATION (CAS 01)" << endl; 
   
	Canevas can;
	
	// ÉTAPE 1 //
	{
		bool res1 = 0, res2 = 0;
		Rectangle* r1 = new Rectangle();
		res1 = can.ajouterForme(r1);
	
		Carre* c1 = new Carre();
		c1->SetCote(10);
		c1->translater(-19, 2);
		res2 = can.ajouterForme(c1);
	
		if (res1 && res2) cout << "Étape 1 terminée avec succès" << endl;
		else cout << "Échec à l'étape 1" << endl;
	}
	
	// ÉTAPE 2 //
	{
		bool result = 0;
		result = can.activerCouche(1);
		if (result) cout << "Étape 2 terminée avec succès" << endl;
		else cout << "Échec à l'étape 2" << endl;
	}
	
	// ÉTAPE 3 //
	{
		bool result = 0;
		Cercle* ce1 = new Cercle();
		ce1->SetRayon(4);
		result = can.ajouterForme(ce1);
		if (result) cout << "Étape 3 terminée avec succès" << endl;
		else cout << "Échec à l'étape 3" << endl;
	}
	
	// ÉTAPE 4 //
	{
		can.afficher(cout); cout;
		cout << "Étape 4 terminée sans valeur de retour" << endl;
	}
	
	// ÉTAPE 5 //
	{
		cout << "Aire du canevas: " << can.aire() << endl;
		cout << "Étape 5 terminée, valeur ci-haut" << endl;
	}
	
	cout << endl << endl;
}

void Tests::tests_application_cas_02()
{
    cout << "TESTS APPLICATION (CAS 02)" << endl;  
	Canevas can;
	
	// ÉTAPE 1 //
	{
		bool res1 = 0, res2 = 0;
		Cercle* ce1 = new Cercle();
		res1 = can.ajouterForme(ce1);
	
		Carre* c1 = new Carre();
		c1->SetCote(3);
		c1->translater(3, 6);
		res2 = can.ajouterForme(c1);
	
		if (res1 && res2) cout << "Étape 1 terminée avec succès" << endl;
		else cout << "Échec à l'étape 1" << endl;
	}
	
	// ÉTAPE 2 //
	{
		can.afficher(cout); cout;
		cout << "Étape 2 terminée sans valeur de retour" << endl;
	}
	
	// ÉTAPE 3 //
	{
		cout << "Aire du canevas: " << can.aire() << endl;
		cout << "Étape 3 terminée, valeur ci-haut" << endl;
	}
	
	// ÉTAPE 4 //
	{
		bool result = 0;
		result = can.translater(10,5);
		if (result) cout << "Étape 4 terminée avec succès" << endl;
		else cout << "Échec à l'étape 4" << endl;
	}
	
	// ÉTAPE 5 //
	{
		can.afficher(cout); cout;
		cout << "Étape 5 terminée sans valeur de retour" << endl;
	}
	
	// ÉTAPE 6 //
	{
		cout << "Aire du canevas: " << can.aire() << endl;
		cout << "Étape 6 terminée, valeur ci-haut" << endl;
	}
	
	
	cout << endl << endl;
}







void Tests::tests_validation(Canevas* can)
{
	// ÉTAPE 1 //
	{
		bool result = 0;
		cout << "TESTS VALIDATION" << endl << endl;
		// ÉTAPE 1 //
		result = can->activerCouche(1);
		if (result) cout << "Étape 1 terminée avec succès" << endl;
		else cout << "Échec à l'étape 1" << endl;
		
		
	}
	
	// ÉTAPE 2 //
	{
		bool res1 = 0, res2 = 0, res3 = 0;
		Rectangle* r1 = new Rectangle();
		r1->SetLongueur(2);
		r1->SetHauteur(3);
		res1 = can->ajouterForme(r1);
	
		Carre* c1 = new Carre();
		c1->SetCote(4);
		c1->translater(2, 3);
		res2 = can->ajouterForme(c1);
	
		Cercle* ce1 = new Cercle();
		ce1->SetRayon(6);
		ce1->translater(7, 8);
		res3 = can->ajouterForme(ce1);
		if (res1 && res2 && res3) cout << "Étape 2 terminée avec succès" << endl;
		else cout << "Échec à l'étape 2" << endl;
	}
	
	// ÉTAPE 3 //
	{
		bool result = 0;
		result = can->activerCouche(2);
		if (result) cout << "Étape 3 terminée avec succès" << endl;
		else cout << "Échec à l'étape 3" << endl;
	}
	
	// ÉTAPE 4 //
	{
		bool result = 0;
		Rectangle* r2 = new Rectangle();
		r2->SetLongueur(4);
		r2->SetHauteur(5);
		result = can->ajouterForme(r2);
		if (result) cout << "Étape 4 terminée avec succès" << endl;
		else cout << "Échec à l'étape 4" << endl;
	}
	
	// ÉTAPE 5 //
	{
		can->afficher(cout); cout;
		cout << "Étape 5 terminée sans valeur de retour" << endl;
	}
	
	// ÉTAPE 6 //
	{
		cout << "Aire du canevas: " << can->aire() << endl;
		cout << "Étape 6 terminée, valeur ci-haut" << endl;
	}
	
	
	cout << endl << endl;
	
	
	// ÉTAPE 7 //
	{
		bool res1 = 0, res2 = 0, res3 = 0, res4 = 0; 
		res1 = can->activerCouche(0);
	
		Rectangle* r3 = new Rectangle();
		res2 = can->ajouterForme(r3);
	
		Carre* c2 = new Carre();
		res3 = can->ajouterForme(c2);
	
		Cercle* ce2 = new Cercle();
		res4 = can->ajouterForme(ce2);
		if (res1 && res2 && res3 && res4) cout << "Étape 7 terminée avec succès" << endl;
		else cout << "Échec à l'étape 7" << endl;
	}
	
	// ÉTAPE 8 //
	{
		bool res1 = 0, res2 = 0;
		res1 = can->activerCouche(1);
		res2 = can->translater(5,5);
		if (res1 && res2) cout << "Étape 8 terminée avec succès" << endl;
		else cout << "Échec à l'étape 8" << endl;
	}
	
	// ÉTAPE 9 //
	{
		bool result = 0;
		result = can->ResetCouche(2);
		if (result) cout << "Étape 9 terminée avec succès" << endl;
		else cout << "Échec à l'étape 9" << endl;
	}
	
	// ÉTAPE 10 //
	{
		bool result = 0;
		result = can->ResetCouche(3);
		if (result) cout << "Étape 10 terminée avec succès" << endl;
		else cout << "Échec à l'étape 10" << endl;
	}
	
	// ÉTAPE 11 //
	{
		bool result = 0;
		result = can->ResetCouche(4);
		if (result) cout << "Étape 11 terminée avec succès" << endl;
		else cout << "Échec à l'étape 11" << endl;
	}
	
	// ÉTAPE 12 //
	{
		can->afficher(cout);
		cout << "Étape 12 terminée sans valeur de retour" << endl;
	}
	
	// ÉTAPE 13 //
	{
		cout << "Aire du canevas: " << can->aire() << endl;
		cout << "Étape 13 terminée, valeur ci-haut" << endl;
	}
	
	
	cout << endl << endl;
	
	
	// ÉTAPE 14 //
	{
		bool res1 = 0, res2 = 0;
		res1 = can->activerCouche(1);
		res2 = can->retirerForme(0);
		if (res1 && res2) cout << "Étape 14 terminée avec succès" << endl;
		else cout << "Échec à l'étape 14" << endl;
	}
	
	// ÉTAPE 15 //
	{
		can->afficher(cout);
		cout << "Étape 15 terminée sans valeur de retour" << endl;
	}
		
	// ÉTAPE 16 //
	{
		cout << "Aire du canevas: " << can->aire() << endl;
		cout << "Étape 16 terminée, valeur ci-haut" << endl;
	}
	
	
	cout << endl << endl;
	
	
	// ÉTAPE 17 //
	{
		bool result = 0;
		result = can->reinitialiser();
		if (result) cout << "Étape 17 terminée avec succès" << endl;
		else cout << "Échec à l'étape 17" << endl;
	}
	
	// ÉTAPE 18 //
	{
		can->afficher(cout);
		cout << "Étape 18 terminée sans valeur de retour" << endl;
	}
	
	// ÉTAPE 19 //
	{
		cout << "Aire du canevas: " << can->aire() << endl;
		cout << "Étape 19 terminée, valeur ci-haut" << endl;
	}
	cout << endl << endl;
}




