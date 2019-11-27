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
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher ( ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur

    TrajetCompose ( TrajetSimple ** list, const unsigned int sizeList );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées


//----------------------------------------------------- Attributs protégés
    TrajetSimple ** listTrajet;
    const unsigned int nbTrajet;

};

//---------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJET_COMPOSE_H