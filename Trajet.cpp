/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Louis ROB et Quentin DE ANDRIA
    e-mail               : louis.rob@insa-lyon.fr quentin.de-andria@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const char * Trajet::GetStart ( ) const
// Algorithme :
//
{
    return start;
} //----- Fin de Méthode


const char * Trajet::GetEnd ( ) const
// Algorithme :
//
{
    return end;
} //----- Fin de Méthode

void Trajet::Afficher ( ) const
// Algorithme :
//
{
    cout << "de " << start << " a " << end ;
} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( const char * startPoint, const char * endPoint )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
    start = startPoint;
    end = endPoint;
} //----- Fin de Ensemble


Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //----- Fin de ~Ensemble


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

