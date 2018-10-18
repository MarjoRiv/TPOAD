#include "instance.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void lecture_instance(Data& D, string f_instance)
{
    f_instance = "STARTING_CODE/INSTANCES/" + f_instance;
    ifstream instance(f_instance);
    if(!instance)
    {
        cout << "Erreur d'ouverture du fichier !" << endl;
    }
    string ligne;
    int n, m;//, machine, duree;
    getline(instance, ligne);
    //cout << ligne <<endl;
    instance >> n;
    instance >> m;
    cout << n << " " << m << endl;
    D.set_m(m);
    D.set_n(n);
}
