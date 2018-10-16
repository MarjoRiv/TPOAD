#include <cassert>
#include "Graphe.h"
#include "Sommet.h"
#include "Arc.h"

using namespace std;

void Graphe::add_sommet(int id)
{
	//assert(id == sommets.size()); //??
	sommets.push_back(Sommet());
	sommets[id].set_id(id);
}

const Sommet& Graphe::get_sommet(int id)
{
	//assert((id > 0) && (id < sommets.size()));
	return sommets[id];
}

void Graphe::add_arc(int id, int orig, int dest, int cout)
{
	//assert(id == arcs.size()); // ??
	arcs.push_back(Arc());
	arcs[id].set_id(id);

	arcs[id].set_orig(orig);
	sommets[orig].add_out(id);

	arcs[id].set_dest(dest);
	sommets[dest].add_in(id);

	arcs[id].set_cout(cout);
}

// Suite
const Arc& Graphe::get_arc(int id)
{
//    assert((id > 0) && (id < arcs.size()));
    return arcs[id];
}

int Graphe::nb_sommet()
{
    return sommets.size();
}

int Graphe::nb_arcs()
{
    return arcs.size();
}

void Graphe::afficher()
{
    cout << "Affichage du graphe" << endl;
}
