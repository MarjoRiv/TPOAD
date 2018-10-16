#include <iostream>
#include <fstream>
#include "Graphe.h"

using namespace std;

int main()
{
    ifstream is("toto.txt");
    if(!is)
    {
        cout << "Erreur d'ouverture du fichier" << endl;
        exit(1);
    }
    Graphe g;
    int s,a;
    is >> s >> a;
    //cout << "s = " << s << " et a = " << a << endl;
    for(int i=0; i<a; i++)
    {
        int orig, dest, cout;
        is >> orig >> dest >> cout;
        g.add_arc(i, orig, dest, cout);
    }
    g.afficher();
    cout << "ca marche!" << endl;
    return 0;
}

/*
int main()
{
    Graphe g("toto.txt");
    Dijkstra dijk(g);
    cout << dijk(0,15);
    return 0;
}
*/
