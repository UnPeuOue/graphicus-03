#
# Auteur: C.-A. Brunet
# Date: 08 janvier 2018
# Description: compilation de graphicus-01. Ce fichier fait partie de 
#	la distribution de Graphicus.
#

graphicus-02:graphicus-02.o tests.o canevas.o couche.o vecteur.o forme.o cercle.o rectangle.o carre.o
	g++ -o graphicus-02 graphicus-02.o tests.o canevas.o couche.o vecteur.o forme.o cercle.o rectangle.o carre.o

graphicus-02.o: graphicus-02.cpp tests.h canevas.h couche.h vecteur.h forme.h rectangle.h cercle.h carre.h coordonnee.h
	g++ -c graphicus-02.cpp

tests.o: tests.cpp tests.h canevas.h couche.h vecteur.h forme.h rectangle.h cercle.h carre.h coordonnee.h
	g++ -c tests.cpp

canevas.o: canevas.cpp canevas.h couche.h vecteur.h forme.h rectangle.h cercle.h carre.h coordonnee.h
	g++ -c canevas.cpp

couche.o: couche.cpp couche.h vecteur.h forme.h rectangle.h cercle.h carre.h coordonnee.h
	g++ -c couche.cpp
	
vecteur.o: vecteur.cpp vecteur.h forme.h rectangle.h cercle.h carre.h coordonnee.h
	g++ -c vecteur.cpp

cercle.o: cercle.cpp cercle.h forme.h coordonnee.h 
	g++ -c cercle.cpp

rectangle.o: rectangle.cpp rectangle.h forme.h coordonnee.h 
	g++ -c rectangle.cpp

carre.o: carre.cpp carre.h forme.h coordonnee.h 
	g++ -c carre.cpp

forme.o: forme.cpp forme.h coordonnee.h 
	g++ -c forme.cpp

clean:
	rm  -f *.o
