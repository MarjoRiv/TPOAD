#include <iostream>
#include "instance.h"
using namespace std;

int main()
{
    Data D;
    lecture_instance(D, "la01.dat");
    D.afficher_instance();
    D.afficher();
    //D.afficher_solution_makespan();
    return 0;
}
