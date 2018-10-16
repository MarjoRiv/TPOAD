#include "instance.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void lecture_instance(Data& D)
{
    ifstream instance("STARTING_CODE/INSTANCES/la01.dat");
    string ligne;
    int n, m;//, machine, duree;
    getline(instance, ligne);
    cout << ligne <<endl;
    instance >> n;
    instance >> m;
    cout << n << " " << m << endl;
    D.set_m(m);
    D.set_n(n);
}
