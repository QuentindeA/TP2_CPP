/*******************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Louis ROB et Quentin DE ANDRIA
    e-mail               : louis.rob@insa-lyon.fr quentin.de-andria@insa-lyon.fr
*******************************************************************************/

//------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ---

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>

using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Save(string &textToSave) const
{
    textToSave = textToSave + "s|" + start + "|" + end + "|" + mean + "\n";
}



void TrajetSimple::Afficher ( ) const
{
    Trajet::Afficher();
    cout << " en " << mean << endl;
} //----- Fin de Afficher


//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( const char* startPoint, const char* endPoint,
                             const char* transportMean )
                            : Trajet ( startPoint, endPoint)

{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif

    mean = new char[strlen(transportMean)+1];
    strcpy(mean,transportMean);

} //----- Fin de TrajetSimple (constructeur de copie)


TrajetSimple::~TrajetSimple ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif

    delete[] mean;
} //----- Fin de ~TrajetSimple
