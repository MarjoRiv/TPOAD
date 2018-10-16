#ifndef PCC_H_INCLUDED
#define PCC_H_INCLUDED

class PCC
{
protected:
    Graphe * g;
    //<--resultats
public:
PCC(Graphe &g):graphe(&g);
virtual int nn(int orig, int dest)=0;
//----- getResultat();
};


#endif // PCC_H_INCLUDED
