#include <iostream>
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

#define MAX_LENGTH 100

using namespace std;

void separator();
TrajetSimple* makeTrajetSimple();
TrajetCompose* makeTrajetCompse();
void search(Catalogue * monCatalogue);


int main()
{
    bool quit = false;
    //char answer = '0';
    char* answer = new char[MAX_LENGTH]; //Je crois qu'il ne veut pas que l'on face comme ça

    Catalogue * monCatalogue = new Catalogue();

    while ( !quit )
    {
        separator();

        cout << " 1 - Ajout d'un trajet simple" << endl;
        cout << " 2 - Ajout d'un trajet compose" << endl;
        cout << " 3 - Affichage du catalogue" << endl;
        cout << " 4 - Recherche d'un parcourt" << endl;
        cout << " 5 - Quitter" << endl;

        cout << "   Reponse : ";
        cin >> answer;

        cout << "------------------------------------" << endl;

        switch (answer[0]) {
            case '1' :
                monCatalogue->AddTrajet(makeTrajetSimple());
                break;
            case '2' :
                monCatalogue->AddTrajet(makeTrajetCompse());
                break;
            case '3' :
                monCatalogue->Afficher();
                break;
            case '4' :
                search(monCatalogue);
                break;
            case '5' :
                quit = true;
                break;
            default :
                cout << "Inscrivez un chiffre entre 1 et 5" << endl;
                break;
        }
    }
    delete(answer);
    delete(monCatalogue);
}

void separator()
{
    cout << "------------------------------------" << endl << endl << endl;
    cout << "               MENU";
    cout << endl << "------------------------------------" << endl;
}

void search(Catalogue * monCatalogue)
{
    char* startPoint = new char[MAX_LENGTH];
    char* endPoint = new char[MAX_LENGTH];

    cout << "Lieu de depart : ";
    cin >> startPoint;
    cout << "Lieu d'arrivee : ";
    cin >> endPoint;

    monCatalogue->Search(startPoint, endPoint);

    delete(startPoint);
    delete(endPoint);
}

TrajetSimple* makeTrajetSimple()
{
    char* startPoint = new char[MAX_LENGTH];
    char* endPoint = new char[MAX_LENGTH];
    char* mean = new char[MAX_LENGTH];

    cout << "Point de depart : ";
    cin >> startPoint;
    cout << "Point d'arrive : ";
    cin >> endPoint;
    cout << "Moyen de transport : ";
    cin >> mean;

    TrajetSimple* ts = new TrajetSimple(startPoint, endPoint, mean);

    delete(startPoint);
    delete(endPoint);
    delete(mean);

    return ts;
}

TrajetCompose* makeTrajetCompse()
{
    int nbTrajetSimple;
    int i;

    cout << "Combien de trajet simple dans le trajet compose ?" << endl;
    cin >> nbTrajetSimple;

    TrajetSimple ** mesTrajetsSimples = new TrajetSimple*[nbTrajetSimple];

    for ( i = 0; i < nbTrajetSimple; i++ )
    {
        mesTrajetsSimples[i] = makeTrajetSimple();
    }

    return new TrajetCompose(mesTrajetsSimples, nbTrajetSimple);
}
