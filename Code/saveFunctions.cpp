#include "saveFunctions.h"

#include <iostream>
#include <fstream>
#include "Catalogue.h"
#include "Trajet.h"

using namespace std;

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
                int debut = 0;
                int fin = 0;
                cout << "Choisissez botre intervalle :" << endl;
                cin >> debut;
                cin >> fin;
                saveAll(outFile, monCatalogue, debut, fin);
                break;
        default:
                cout << "Votre choix n'est pas dans les possibilitees." << endl;
                break;
    }
}

bool saveAll(ofstream &outFile, Catalogue * monCatalogue, unsigned int begin = 0, unsigned int end = 0)
{
    string text = "";
    if (end == 0) end = monCatalogue->getNbTrajet();
    for(unsigned int i=begin; i<end; ++i ){
        monCatalogue->getListTrajet()[i]->Save(text);
        outFile << text << endl;
        text = "";
    }
    return true;
}

bool saveByTrajectType(ofstream &outFile, Catalogue * monCatalogue)
{
    string text = "";
    for(unsigned int i=0; i<monCatalogue->getNbTrajet(); i++ ){
        monCatalogue->getListTrajet()[i]->Save(text);
        outFile << text << endl;
        text = "";
    }
    return true;
}

bool saveByCityName(ofstream &outFile, Catalogue * monCatalogue)
{
    int mode = 0;
    string ville1;
    string ville2;
    cout << "Quelle mode ?" << endl;
    cin >> mode;

    switch (mode)
    {
        case 1:
                cout << "Quelle est votre ville de depart" << endl;
                cin >> ville1;
                break;
        case 2:
                cout << "Quelle est votre ville d'arrivee" << endl;
                cin >> ville1;
                break;
        case 3:
                cout << "ville d'arrivee" << endl;
                cin >> ville1;
                cout << "ville de depart" << endl;
                cin >> ville2;
                break;
    }

    string text = "";
    for(unsigned int i=0; i<monCatalogue->getNbTrajet(); i++ ){
        if(mode == 1 && strcmp(ville1.c_str(), monCatalogue->getListTrajet()[i]->GetStart()) == 0)
        {
            monCatalogue->getListTrajet()[i]->Save(text);
            outFile << text << endl;
            text = "";
        }
        else if(mode == 2 && strcmp(ville1.c_str(), monCatalogue->getListTrajet()[i]->GetEnd()) == 0)
        {
            monCatalogue->getListTrajet()[i]->Save(text);
            outFile << text << endl;
            text = "";
        }
        else if(mode == 3
                && strcmp(ville1.c_str(), monCatalogue->getListTrajet()[i]->GetStart()) == 0
                && strcmp(ville2.c_str(), monCatalogue->getListTrajet()[i]->GetEnd()) == 0)
        {
            monCatalogue->getListTrajet()[i]->Save(text);
            outFile << text << endl;
            text = "";
        }

    }
    return true;
}

bool saveInterval(ofstream &outFile, Catalogue * monCatalogue)
{
    return true;
}
