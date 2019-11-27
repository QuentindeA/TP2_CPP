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
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher (  ) const
// Algorithme :
//
{
    int unsigned i;
    for ( i = 0; i<nbTrajet-1; i++ )
    {
        cout << "de " << listTrajet[i]->GetStart();
        cout << " a " << listTrajet[i]->GetEnd();
        cout << " - " ;
    }
    if ( nbTrajet > 0 )
    {
        cout << "de " << listTrajet[nbTrajet-1]->GetStart();
        cout << " a " <<listTrajet[nbTrajet-1]->GetEnd();
        cout << endl;
    }

} //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose (  const TrajetSimple ** list,
                                const unsigned int sizeList )
                                : Trajet (  list[0]->GetStart(),
                                            list[sizeList-1]->GetEnd() ),
                                listTrajet ( list ),
                                nbTrajet ( sizeList )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif

} //----- Fin de Ensemble


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de ~Ensemble


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
