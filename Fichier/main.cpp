#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Lecture
int main()
{
    ifstream fichier("fichier.txt");
    if(!fichier)
    {
        cout << "Erreur d'ouverture du fichier!"<< endl;
        return -1;
    }
    //cout << "Tout va bien" << endl;
    string ligne;
    while(!fichier.eof())  //Tant qu'on a pas atteint la fin du fichier
    {
        getline(fichier, ligne);
        cout << ligne << endl;
    }
    return 0;
}
/* Ecriture
int main()
{
    //ofstream fichier("monFichier.txt"); // ecrase le fichier s'il existe
    ofstream fichier("monFichier.txt", ios::app); // ajouter les à la fin du fichier
    if(!fichier)
    {
        cout << "Erreur d'ouverture du fichier" << endl;
        return -1;
    }
    cout << "Fichier ouvert avec succes!" << endl;
    fichier << "J'ajoute une nouvelle ligne." << endl;
    fichier << "Sans ecfraser le contenu du fichier" << endl;
    return 0;
}
*/

