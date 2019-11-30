/*******************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Louis ROB et Quentin DE ANDRIA
    e-mail               : louis.rob@insa-lyon.fr quentin.de-andria@insa-lyon.fr
*******************************************************************************/

//-------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) --------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes
#define RALLONGEMENT 5

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::AddTrajet(const Trajet *newTrajet)
// Algorithme :
//
{
    unsigned int i;

    if (nbTrajet == maxTrajet)
    {
        maxTrajet += RALLONGEMENT;
        const Trajet ** listTrajetPlusGrande = new const Trajet*[maxTrajet];
        for ( i = 0; i < nbTrajet; i++ )
        {
            listTrajetPlusGrande[i] = listTrajet[i];
        }
        delete[] listTrajet;
        listTrajet = listTrajetPlusGrande;
    }

    listTrajet[nbTrajet] = newTrajet;
    nbTrajet++;
} //----- Fin de Méthode

void Catalogue::Afficher() const
{
    unsigned int i;

    cout << "Trajets disponibles dans le catalogue : " << endl;

    for ( i = 0; i < nbTrajet; i++ )
    {
        listTrajet[i]->Afficher();
    }
} //----- Fin de Méthode

void Catalogue::Search(const char *startPoint, const char *endPoint) const
// Algorithme :
//
{
    unsigned int i;
    for ( i = 0; i < nbTrajet; i++ )
    {
        if (strcmp(listTrajet[i]->GetStart(), startPoint) == 0 &&
            strcmp(listTrajet[i]->GetEnd(), endPoint) == 0)
        {
            listTrajet[i]->Afficher();
        }
    }
} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue()
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    nbTrajet = 0;
    maxTrajet = RALLONGEMENT;
    listTrajet = new const Trajet*[maxTrajet];//(sizeof(Trajet) * maxTrajet);
} //----- Fin de Catalogue

Catalogue::~Catalogue()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

unsigned int i;

    for ( i = 0; i < nbTrajet; i++ )
    {
        delete listTrajet[i];
    }
    delete[] listTrajet;
} //----- Fin de ~Catalogue

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
