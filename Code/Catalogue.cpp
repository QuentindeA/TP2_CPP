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
} //----- Fin de Méthode

void Catalogue::Afficher() const
{
    unsigned int i;

    cout << "Trajets disponibles dans le catalogue : " << endl;

    for (i = 0; i < nbTrajet; i++)
    {
        listTrajet[i]->Afficher();
    }
} //----- Fin de Méthode

void Catalogue::Search(const char *startPoint, const char *endPoint) const
// Algorithme :
//
{
    unsigned int i;
    for (i = 0; i < nbTrajet; i++)
    {
        if (strcmp(listTrajet[i]->GetStart(), startPoint) == 0 &&
            strcmp(listTrajet[i]->GetEnd(), endPoint) == 0)
        {
            listTrajet[i]->Afficher();
        }
    }
} //----- Fin de Méthode

void Catalogue::AdvancedSearch(const char *position, const char *&target,
                               const char *&listTrajetsCourrants)
// Algorithme :
//
{
    bool dejaAffiche = false;

    //ajoute la position acutelle en fin de liste
    elem *currentPosition = new elem;
    strcpy(currentPosition->localisation, position);
    currentPosition->mean = NULL;
    currentPosition->next = NULL;
    if (listTrajetsCourrants == NULL)
    {
        listTrajetsCourrants = currentPosition;
    }
    else
    {
        elem *parcoursList = listTrajetsCourrants;
        while (parcoursList->next != NULL)
        {
            parcoursList = parcoursList->next;
        }
        parcoursList->next = currentPosition;
    }

    for (int i = 0; i < nbTrajet; ++i)
    {
        if (strcmp(*listTrajets[i].getStart(), position) == 0) //check pointeur
        {
            if (strcmp(*listTrajets[i].getEnd(), target) == 0)
            {
                //on rajoute la target dans la liste
                elem *goal = new elem;
                strcpy(goal->localisation, target);
                goal->mean = NULL;
                currentPosition->next = NULL;
                elem *parcoursList = listTrajetsCourrants;
                while (parcoursList->next != NULL)
                {
                    parcoursList = parcoursList->next;
                }
                //on rajoute le mean aussi
                strcpy(parcoursList->mean, *listTrajets[i].getMean()); //Comment on a le Mean ??
                parcoursList->next = goal;

                //On affiche listTrajetsCourrants
                parcourList = listTrajetsCourrants;
                while (parcourList != NULL)
                {
                    if (!dejaAffiche)
                    {
                        cout << "Trajets disponibles dans le catalogue : " << endl;
                        dejaAffiche = true;
                    }
                    cout << "de " << parcoursList->localisation << " a " << end;
                    mean = parcoursList->mean;
                    parcourList = parcourList->next;
                    cout << parcoursList->localisation << end;
                    cout << " en " << mean << end;
                }

                //On delete les deux derniers elem de listTrajetsCourrants --> backtracking
                parcourList = listTrajetsCourrants;
                parcoursList = parcoursList->next;
                elem *parcoursList2 = listTrajetsCourrants;
                if (parcoursList->next == NULL) //cas ou 2 elem
                {
                    delete parcoursList->localisation;
                    delete parcoursList2->next;
                }
                else
                {
                    parcoursList = parcoursList->next;
                    parcoursList2 = parcoursList2->next;
                    elem *parcoursList3 = listTrajetsCourrants;
                    if (parcoursList->next == NULL) //cas ou 3 elem
                    {
                        delete parcoursList->localisation;
                        delete parcoursList2->next;
                        delete parcoursList2->mean;
                        delete parcoursList2->localisation;
                        delete parcoursList3->next;
                    }
                    else //cas ou plus que 3 elem
                    {
                        while (parcourList != NULL)
                        {
                            parcoursList = parcoursList->next;
                            parcoursList2 = parcoursList2->next;
                            parcoursList3 = parcoursList3->next;
                        }
                        delete parcoursList->localisation;
                        delete parcoursList2->next;
                        delete parcoursList2->mean;
                        delete parcoursList2->localisation;
                        delete parcoursList3->next;
                    }
                }
                break;
            }
            else
            {
                //on check qu'on est pas déjà passé par ici
                elem *parcoursList = listTrajetsCourrants;
                while (parcourList->next != NULL)
                {
                    if (strcmp(parcoursList->localisation, *listTrajets[i].getEnd()) == 1)
                    {
                        AdvancedSearch(*listTrajets[i].getEnd(), target, listTrajetsCourrants);
                    }
                }
            }
        }
    }
    //On supprime la position courante en remontant d'une position --> backtracking
    parcourList = listTrajetsCourrants;
    parcoursList = parcoursList->next;
    elem *parcoursList2 = listTrajetsCourrants;
    if (parcoursList->next == NULL) //cas ou 2 elem
    {
        delete parcoursList->localisation;
        delete parcoursList2->next;
    }
    else
    {
        parcoursList = parcoursList->next;
        parcoursList2 = parcoursList2->next;
        elem *parcoursList3 = listTrajetsCourrants;
        if (parcoursList->next == NULL) //cas ou 3 elem
        {
            delete parcoursList->localisation;
            delete parcoursList2->next;
            delete parcoursList2->mean;
            delete parcoursList2->localisation;
            delete parcoursList3->next;

            position = parcoursList3->localisation;
        }
        else //cas ou plus que 3 elem
        {
            while (parcourList != NULL)
            {
                parcoursList = parcoursList->next;
                parcoursList2 = parcoursList2->next;
                parcoursList3 = parcoursList3->next;
            }
            delete parcoursList->localisation;
            delete parcoursList2->next;
            delete parcoursList2->mean;
            delete parcoursList2->localisation;
            delete parcoursList3->next;

            position = parcoursList3->localisation;
        }
    }
}

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
