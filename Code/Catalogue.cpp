/*******************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Louis ROB et Quentin DE ANDRIA
    e-mail               : louis.rob@insa-lyon.fr quentin.de-andria@insa-lyon.fr
*******************************************************************************/

//-------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ----------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::AddTrajet ( const Trajet * )
// Algorithme :
//
{
} //----- Fin de Méthode

void Catalogue::Afficher ( ) const
// Algorithme :
//
{
    unsigned int i;

    cout << "Trajets disponibles dans le catalogue : " << endl;

    for ( i = 0; i < nbTrajet; i++ )
    {
        listTrajet[i].Afficher();
    }
} //----- Fin de Méthode

void Catalogue::Search ( const char * startPoint, const char * endPoint ) const
// Algorithme :
//
{
} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

    listTrajet = 0;
    nbTrajet = 0;

} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
