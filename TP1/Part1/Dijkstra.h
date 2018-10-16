#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED

class Dijkstra:public PCC
{
Dijkstra(Graphe &g):PCC(g); //{} à la place de ;
int nn (int orig, int dest); // { stock dans resultat}
}

#endif // DIJKSTRA_H_INCLUDED
