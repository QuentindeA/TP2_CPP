/*******************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Louis ROB et Quentin DE ANDRIA
    e-mail               : louis.rob@insa-lyon.fr quentin.de-andria@insa-lyon.fr
*******************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------
#if !defined(CATALOGUE_H)
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Permet de créer une liste de trajets disponibles et d'ajouter des trajets
// possibles dans cette liste
//------------------------------------------------------------------------

class Catalogue
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    void AddTrajet(const Trajet *newTrajet);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Afficher() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Search ( const char * startPoint, const char * endPoint ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Catalogue();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Catalogue();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés

private:
    //------------------------------------------------------- Attributs privés
    const Trajet ** listTrajet;
    unsigned int nbTrajet;
    unsigned int maxTrajet;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H
