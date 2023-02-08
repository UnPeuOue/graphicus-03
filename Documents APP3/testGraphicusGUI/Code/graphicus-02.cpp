/********
 * Fichier: graphicus-01.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
********/

/*******
Travail effectué par
Youcef Labassi - laby1302
Alexandre Rousseau - roua0701
*******/

#include "tests.h"

using namespace std;

int main()
{
	Canevas* can = new Canevas();
	Tests testsValidation = Tests();
	testsValidation.tests_validation(can);
   
	Tests tests;
   
	tests.tests_application();
   
	return 0;
}

