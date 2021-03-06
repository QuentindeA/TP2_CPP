#include <iostream>
#include <fstream>


#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "loadFunctions.h"
#include "saveFunctions.h"

using namespace std;

static const unsigned int MAX_LENGTH = 100;

void separator();
const TrajetSimple *makeTrajetSimple();
const TrajetCompose *makeTrajetCompose();
void search(Catalogue *monCatalogue);

int main()
{
    bool quit = false;
    //char answer = '0';
    string answer;

    Catalogue *monCatalogue = new Catalogue();

    while (!quit)
    {
        separator();

        cout << " 1 - Ajout d'un trajet simple" << endl;
        cout << " 2 - Ajout d'un trajet compose" << endl;
        cout << " 3 - Affichage du catalogue" << endl;
        cout << " 4 - Recherche d'un parcours" << endl;
        cout << " 5 - Charger des trajets depuis un fichier" << endl;
        cout << " 6 - Sauvegarder le catatalogue dans un fichier" << endl;
        cout << " 7 - Quitter" << endl;

        cout << "   Reponse : ";
        cin >> answer;
        cin.ignore();
        cout << "------------------------------------" << endl;

        switch (answer[0])
        {
        case '1':
            monCatalogue->AddTrajet(makeTrajetSimple());
            break;
        case '2':
            monCatalogue->AddTrajet(makeTrajetCompose());
            break;
        case '3':
            monCatalogue->Afficher();
            break;
        case '4':
            search(monCatalogue);
            break;
        case '5':
            loadFromFile(monCatalogue);
            break;
        case '6':
            saveToFile(monCatalogue);
            break;
        case '7':
            quit = true;
            break;
        default:
            cout << "Inscrivez un chiffre entre 1 et 7" << endl;
            break;
        }
    }
    delete monCatalogue;

    return 0;
}

void separator()
{
    cout << "------------------------------------" << endl
         << endl
         << endl;
    cout << "               MENU";
    cout << endl
         << "------------------------------------" << endl;
}

void search(Catalogue *monCatalogue)
{
    const char *startPoint;
    const char *endPoint;

    string start;
    string end;

    cout << "Lieu de depart : ";
    getline(cin, start);
    startPoint = start.c_str();
    cout << "Lieu d'arrivee : ";
    getline(cin, end);
    endPoint = end.c_str();

    monCatalogue->Search(startPoint, endPoint);

}

const TrajetSimple *makeTrajetSimple()
{
    const char *startPoint;
    const char *endPoint;
    const char *mean;

    string start;
    string end;
    string sMean;
    cout << "Point de depart : ";
    getline(cin, start);
    startPoint = start.c_str();
    cout << "Point d'arrive : ";
    getline(cin, end);
    endPoint = end.c_str();
    cout << "Moyen de transport : ";
    getline(cin, sMean);
    mean = sMean.c_str();

    const TrajetSimple *ts = new const TrajetSimple(startPoint, endPoint, mean);

    //delete[] startPoint;
    //delete[] endPoint;
    //delete[] mean;

    return ts;
}

const TrajetCompose *makeTrajetCompose()
{
    int nbTrajetSimple;
    int i;

    cout << "Combien de trajet simple dans le trajet compose ?" << endl;
    cin >> nbTrajetSimple;
    cin.ignore();
    const TrajetSimple **mesTrajetsSimples = new const TrajetSimple *[nbTrajetSimple];

    for (i = 0; i < nbTrajetSimple; i++)
    {
        mesTrajetsSimples[i] = makeTrajetSimple();
    }

    return new const TrajetCompose(mesTrajetsSimples, nbTrajetSimple);
}
