/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Louis ROB et Quentin DE ANDRIA
    e-mail               : louis.rob@insa-lyon.fr quentin.de-andria@insa-lyon.fr
*************************************************************************/

//------ Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ------
#if ! defined ( TRAJET_COMPOSE_H )
#define TRAJET_COMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Modélise un trajet composé de plusieurs trajets simples
// Permet d'afficher tous les trajets simples le constituant
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher ( ) const;

//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose ( const TrajetSimple ** list, const unsigned int sizeList );
    // Mode d'emploi :
    //   list correspond à un tableau de pointeurs de trajet simple
    //   sizeList correspond au nombre de trajet simple que contient list
    // Contrat :
    //   Tous les trajet simples doivent être alloués
    //   Le point d'arrivé d'un trajet simple doit correspondre au point de
    //     départ du trajet suivant
    //   sizeList doit correspondre au bon nombre d'élément de list

    virtual ~TrajetCompose ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées


//----------------------------------------------------- Attributs protégés
    const TrajetSimple ** listTrajet;
    const unsigned int nbTrajet;

};

//---------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJET_COMPOSE_H
