#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED

#include <iostream>
#include "Arc.h"
#include "Sommet.h"

class Graphe
{
protected:
	std::vector<Sommet> sommets;
	std::vector<Arc> arcs;

public:
	//Graphe();
	void add_sommet(int); const Sommet& get_sommet(int);
	void add_arc(int, int, int, int); const Arc& get_arc(int);
	int nb_sommet(); int nb_arcs();
	void afficher();

};

#endif // GRAPHE_H_INCLUDED
