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
typedef struct
{
    char *localisation;
    struct elem *next;
} elem;

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Modélise une liste de trajets.
// Il est possible d'ajouter de nouveaux trajets, d'afficher la liste des
// trajets disponibles ainsi que de faire des recherches de parcours
//------------------------------------------------------------------------

class Catalogue
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    void AddTrajet(const Trajet *newTrajet);
    // Mode d'emploi :
    //   Fournir un pointeur vers un nouveau Trajet qui sera ajouté
    //   dans la liste de pointeurs de Trajets
    // Contrat :
    //   Le trajet pointé doit être alloué

    void Afficher() const;

    void Search(const char *startPoint, const char *endPoint) const;
    // Mode d'emploi :
    //   Fournir un pointeur vers le point de départ et un autre vers le point
    // d'arrivé correspondant au parcours souhaité
    // Contrat :
    //   Nécessite que les chaînes de caractère pointées soient allouées

    void AdvancedSearch(const char *position, const char *&target,
                        const char *&listTrajetsCourrants);
    // Mode d'emploi :
    //
    //
    //

    //-------------------------------------------- Constructeurs - destructeur
    Catalogue();

    virtual ~Catalogue();

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés

private:
    //------------------------------------------------------- Attributs privés
    const Trajet **listTrajet;
    unsigned int nbTrajet;
    unsigned int maxTrajet;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H
