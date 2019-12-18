/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Louis ROB et Quentin DE ANDRIA
    e-mail               : louis.rob@insa-lyon.fr quentin.de-andria@insa-lyon.fr
*************************************************************************/

//---- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Save(string &textToSave) const
// Attend une chaine vide
{
    textToSave += "c|";
    textToSave += nbTrajet;
    textToSave += "\n";
    for(unsigned int i = 0; i<nbTrajet;i++)
    {
        listTrajet[i]->Save(textToSave);
    }
}


void TrajetCompose::Afficher() const
{
    int unsigned i;
    for (i = 0; i < nbTrajet - 1; i++)
    {
        listTrajet[i]->Afficher();
        cout << " - ";
    }
    if (nbTrajet > 0)
    {
        listTrajet[nbTrajet - 1]->Afficher();
        cout << endl;
    }

} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose(const TrajetSimple **list,
                             const unsigned int sizeList)
    : Trajet(list[0]->GetStart(),
             list[sizeList - 1]->GetEnd()),
      listTrajet(list),
      nbTrajet(sizeList)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de Ensemble

TrajetCompose::~TrajetCompose()
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif

    for (unsigned int i = 0; i < nbTrajet; ++i)
    {
        delete listTrajet[i];
    }
    delete[] listTrajet;

} //----- Fin de ~Ensemble

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
