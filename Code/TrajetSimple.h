/*******************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Louis ROB et Quentin DE ANDRIA
    e-mail               : louis.rob@insa-lyon.fr quentin.de-andria@insa-lyon.fr
*******************************************************************************/

//------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) -------
#if ! defined ( TRAJET_SIMPLE_H )
#define TRAJET_SIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Classe modélisant un trajet simple défini par un point de départ, un point
// d'arrivée et d'un moyen de transport.
// Elle permet d'afficher tous ses attributs sur la sortie standard.
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Save(std::string &textToSave) const;


    void Afficher ( ) const;

//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( const char* startPoint, const char* endPoint,
                   const char* transportMean );
    // Mode d'emploi :
    //   startPoint correspond au point de départ du trajet
    //   endPoint correspond au point d'arrivé du trajet
    //   tranportMean correspond au moyen de transport utilisé pour le trajet
    // Contrat :
    //   les chaines pointées par startPoint, endPoint et transportMean
    //   doivent être allouées

    virtual ~TrajetSimple ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    char * mean;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJET_SIMPLE_H
