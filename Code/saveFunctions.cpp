#include "saveFunctions.h"

void saveToFile(Catalogue *monCatalogue)
{
    //initialisation du fichier
    cout << "Nom du fichier de sauvegarde : ";
    string filePath;
    cin >> filePath;
    ofstream out(filePath);
    //Fin initialisation

    //MENU
    int choice;
    cout << "Choix de la façon de sauvegarde" << endl;
    cout << "1 : Sauvegarder tout" << endl;
    cout << "2 : Sauvegarde d'un certain type de trajet" << endl;
    cout << "3 : Sauvegarde selon la ville de depart et/ou D'arrivee" << endl;
    cout << "4 : Saubegarde des trajets dans un intervalle" << endl;
    cin >> choice;
    switch(choice)
    {
        case 1:

                break;
        case 2:
                break;
        case 3:
                break;
        case 4:
                break;
        default:
                break;
    }
}
