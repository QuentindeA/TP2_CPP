/*******************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Louis ROB et Quentin DE ANDRIA
    e-mail               : louis.rob@insa-lyon.fr quentin.de-andria@insa-lyon.fr
*******************************************************************************/

//-------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) --------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes
#define RALLONGEMENT 5

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::AddTrajet(const Trajet *newTrajet)
// Algorithme :
//  Si la liste est emplie : avant d'insérer un nouvel élément on crée une
//  nouvelle zone mémoire plus grande puis on affecte les anciennes
//  valeurs dans la nouvelle liste et on supprime l'ancienne liste
{
    unsigned int i;

    if (nbTrajet == maxTrajet)
    {
        maxTrajet += RALLONGEMENT;
        const Trajet **listTrajetPlusGrande = new const Trajet *[maxTrajet];
        for (i = 0; i < nbTrajet; i++)
        {
            listTrajetPlusGrande[i] = listTrajet[i];
        }
        delete[] listTrajet;
        listTrajet = listTrajetPlusGrande;
    }

    listTrajet[nbTrajet] = newTrajet;
    nbTrajet++;
} //----- Fin de AddTrajet

void Catalogue::Afficher() const
{
    unsigned int i;

    cout << "Trajets disponibles dans le catalogue : " << endl;

    for (i = 0; i < nbTrajet; i++)
    {
        listTrajet[i]->Afficher();
    }
} //----- Fin de Afficher

void Catalogue::Search(const char *startPoint, const char *endPoint) const
// Algorithme :
//
{
    cout << "technique 1 :" << endl;
    unsigned int i;
    for (i = 0; i < nbTrajet; i++)
    {
        if (strcmp(listTrajet[i]->GetStart(), startPoint) == 0 &&
            strcmp(listTrajet[i]->GetEnd(), endPoint) == 0)
        {
            listTrajet[i]->Afficher();
        }
    }
    cout << endl;
    cout << "technique 2 :" << endl;
    etape *itineraire = NULL;
    advancedSearch(itineraire, *startPoint, *endPoint);
} //----- Fin de Search

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue()
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    nbTrajet = 0;
    maxTrajet = RALLONGEMENT;
    listTrajet = new const Trajet *[maxTrajet]; //(sizeof(Trajet) * maxTrajet);
} //----- Fin de Catalogue

Catalogue::~Catalogue()
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

    unsigned int i;

    for (i = 0; i < nbTrajet; i++)
    {
        delete listTrajet[i];
    }
    delete[] listTrajet;
} //----- Fin de ~Catalogue

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void Catalogue::advancedSearch(etape *&itineraire, const char &posAct,
                               const char &target) const
// Algorithme :
//   On utilise une liste doublement chaînée permettant de stocker le chemin
//   en cours
//   Parcours en profondeur des chemins possibles. Dès qu'on chemin n'est
//   pas possible on remonte d'un cran et on essaye les autres possibilités
//   Si l'objectif est atteinte on affiche le chemin puis on continue la
//   recherche pour d'autres possibilités
{
    //on crée le maillont supp
    etape nouvelleEtape;

    for (unsigned int i = 0; i < nbTrajet; ++i)
    {
        if (strcmp(&posAct, listTrajet[i]->GetStart()) == 0)
        {
            //si fin trouvé on affiche
            if (strcmp(&target, listTrajet[i]->GetEnd()) == 0)
            {
                etape *parcoursList = itineraire;
                bool premiereIter = true;
                while ((parcoursList != itineraire || premiereIter) && parcoursList != NULL)
                {
                    premiereIter = false;
                    (parcoursList->way)->Afficher();
                    parcoursList = parcoursList->next;
                }
                listTrajet[i]->Afficher();
                cout << endl;
            }
            else
            {
                //Si n'appartient pas alors on ajoute
                etape *parcoursList = itineraire;
                bool premiereIter = true;
                bool dejaPresent = false;
                while ((parcoursList != itineraire || premiereIter) && parcoursList != NULL && dejaPresent == false)
                {
                    premiereIter = false;
                    if (parcoursList->way == listTrajet[i])
                    {
                        dejaPresent = true;
                    }
                    parcoursList = parcoursList->next;
                }
                if (dejaPresent == false)
                {
                    //on ajoute
                    nouvelleEtape.way = listTrajet[i];
                    if (itineraire == NULL)
                    {
                        itineraire = &nouvelleEtape;
                        nouvelleEtape.next = &nouvelleEtape;
                        nouvelleEtape.previous = &nouvelleEtape;
                    }
                    else
                    {
                        nouvelleEtape.previous = itineraire->previous;
                        nouvelleEtape.next = itineraire;
                        itineraire->previous = &nouvelleEtape;
                        nouvelleEtape.previous->next = &nouvelleEtape;
                    }

                    //on réitère en profondeur
                    advancedSearch(itineraire, *(nouvelleEtape.way)->GetEnd(), target);
                }
            }
        }
    }
    //On supprime le dernier
    if (itineraire != NULL)
    {
        if (itineraire->next != itineraire)
        {
            itineraire->previous = itineraire->previous->previous;
            itineraire->previous->next = itineraire;
        }
        else
        {
            itineraire = NULL;
        }
    }
} //----- Fin de advancedSearch
