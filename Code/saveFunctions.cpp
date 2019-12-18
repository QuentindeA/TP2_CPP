#include "saveFunctions.h"
#include <iostream>
#include <ofstream>

use namespace std;

void saveToFile(Catalogue *monCatalogue)
{
    //initialisation du fichier
    cout << "Nom du fichier de sauvegarde : ";
    string filePath;
    cin >> filePath;
    ofstream outFile(filePath);
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
                saveAll(outFile, monCatalogue);
                break;
        case 2:
                saveByTrajectType(outFile, monCatalogue);
                break;
        case 3:
                saveByCityName(outFile, monCatalogue);
                break;
        case 4:
                saveInterval(outFile, monCatalogue);
                break;
        default:
                cout << "Votre choix n'est pas dans les possibilitees." << endl;
                break;
    }
}

bool saveAll(ostream)
