#include "Sommet.h"

using namespace std;

void Sommet::set_id(int i)
{
    id=i;
}
int Sommet::get_id()
{
    return id;
}
void Sommet::add_in(int id)
{
	in_arcs.push_back(id);
}

int Sommet::get_in(int pos)
{
	//assert((pos >= 0) && (pos < in_arcs.size()));
	return in_arcs[pos];
}
int Sommet::nb_in()
{
	return in_arcs.size();
}
void Sommet::afficher()
{
	cout << "id=" << id << "in=[";
	for (int i = 0; i < nb_in();++i)
	{
		cout << " " << in_arcs[i];
	}
	cout << "] out = [";
	for (int i = 0; i < nb_out();++i)
	{
		cout << " " << out_arcs[i];
	}
	cout << "]";
}
//Suite
void Sommet::add_out(int id) //Ajout sommet sortant
{
    out_arcs.push_back(id);
}
int Sommet::get_out(int pos)
{
    //assert( ( pos >= 0) && ( pos < out_arcs.size() ) );
    return out_arcs[pos];
}
int Sommet::nb_out()
{
    return out_arcs.size();
}
