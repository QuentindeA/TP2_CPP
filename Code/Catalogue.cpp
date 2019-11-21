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

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::AddTrajet(const Trajet *newTrajet)
// Algorithme :
//
{
    if (nbTrajet == maxTrajet)
    {
        maxTrajet += RALLONGEMENT;
        Trajet *listTrajetPlusGrande = new (sizeof(Trajet) * (maxTrajet));
        for (int i = 0; i < maxTrajet - RALLONGEMENT; i++)
        {
            *listTrajetPlusGrande[i] = *listTrajet[i];
        }
        delete (listTrajet);
        listTrajet = listTrajetPlusGrande;
    }

    *listTrajet[nbTrajet] = *newTrajet;
    nbTrajet++;
} //----- Fin de Méthode

void Catalogue::Afficher() const
{
    unsigned int i;

    cout << "Trajets disponibles dans le catalogue : " << endl;

    for (i = 0; i < nbTrajet; i++)
    {
        listTrajet[i].Afficher();
    }
} //----- Fin de Méthode

void Catalogue::Search(const char *startPoint, const char *endPoint) const
// Algorithme :
//
{
    for (int i = 0; i < nbTrajet; i++)
    {
        if (strcmp(listTrajet[i].start, startPoint) == 0 &&
            strcmp(listTrajet[i].end, endPoint) == 0)
        {
            listTrajet[i].Afficher();
        }
    }
} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue()
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

    maxTrajet = 10;
    listTrajet = new (sizeof(Trajet) * maxTrajet);
} //----- Fin de Catalogue

Catalogue::~Catalogue()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

    for ( i = 0; i < nbTrajet; i++ )
    {

    }
} //----- Fin de ~Catalogue

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
