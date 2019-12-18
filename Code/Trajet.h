/*******************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Louis ROB et Quentin DE ANDRIA
    e-mail               : louis.rob@insa-lyon.fr quentin.de-andria@insa-lyon.fr
*******************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Classe abstraite modélidant un trajet défini par un point de départ
// et un point d'arrivé.
// Elle permet d'afficher ses deux attributs sur la sortie standard.
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Save(std::string &textToSave) const = 0;

    virtual const char * GetStart ( ) const;

    virtual const char * GetEnd ( ) const;

    virtual void Afficher ( ) const;

//-------------------------------------------- Constructeurs - destructeur
    Trajet (const char * startPoint, const char * endPoint);
    // Mode d'emploi :
    //   startPoint correspond au point de départ du trajet
    //   endPoint correspond au point d'arrivé du trajet
    // Contrat :
    //   les chaines pointées par startPoint et endPoint doivent être allouées

    virtual ~Trajet ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    char * start;
    char * end;

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
