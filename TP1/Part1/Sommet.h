#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include <iostream>
#include <vector>
#include <cassert>

class Sommet
{
protected:
	int id;
	std::vector<int> in_arcs;
	std::vector<int> out_arcs;
public:
	//Sommet();
	void set_id(int); int get_id();
	void add_in(int); int get_in(int);
	void add_out(int); int get_out(int);
	int nb_in(); int nb_out();
	void afficher();
};

#endif // SOMMET_H_INCLUDED
