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
typedef struct etape
{
    const Trajet *way;
    struct etape *next;
    struct etape *previous;
} etape;

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


    unsigned int getNbTrajet() const;

    const Trajet ** getListTrajet();

    void Afficher() const;

    void Search(const char *startPoint, const char *endPoint) const;
    // Mode d'emploi :
    //   Fournir un pointeur vers le point de départ et un autre vers le point
    //   d'arrivé correspondant au parcours souhaité
    // Contrat :
    //   Nécessite que les chaînes de caractère pointées soient allouées

    //-------------------------------------------- Constructeurs - destructeur
    Catalogue();

    virtual ~Catalogue();

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    void advancedSearch(etape *&itineraire, const char &posAct,
                        const char &target) const;
    // Mode d'emploi :
    //   Mettre itinéraire à NULL pour la première récursivité
    //   Fournir une référence vers le point de départ et une autre vers le point
    //   d'arrivé correspondant au parcours souhaité
    // Contrat :
    //   On priviligie la rapidité à la mémoire par l'utilisation d'une liste
    //   doublement chaînée au lieu d'une simple

    //----------------------------------------------------- Attributs protégés

private:
    //------------------------------------------------------- Attributs privés
    const Trajet **listTrajet;
    unsigned int nbTrajet;
    unsigned int maxTrajet;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H
