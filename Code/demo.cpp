#include <iostream>
#include "Catalogue.h"
#include "TrajetSimple.h"

#define MAX_LENGTH 100

using namespace std;

void separator();
void addTrajetSimple(Catalogue * monCatalogue);
void addTrajetCompose(Catalogue * monCatalogue);
void search(Catalogue * monCatalogue);

int main()
{
    bool quit = false;
    //char answer = '0';
    char* answer = new char[MAX_LENGTH]; //Je crois qu'il ne veut pas que l'on face comme ça

    Catalogue * monCatalogue = new Catalogue();

    while ( !quit )
    {
        cout << " 1 - Ajout d'un trajet simple" << endl;
        cout << " 2 - Ajout d'un trajet compose" << endl;
        cout << " 3 - Affichage du catalogue" << endl;
        cout << " 4 - Recherche d'un parcourt" << endl;
        cout << " 5 - Quitter" << endl;
        separator();

        cin >> answer;

        switch (answer[0]) {
            case '1' :
                cout << endl; separator();
                addTrajetSimple(monCatalogue);
                break;
            case '2' :
                cout << endl; separator();
                addTrajetCompose(monCatalogue);
                break;
            case '3' :
                cout << endl; separator();
                monCatalogue->Afficher();
                separator();
                break;
            case '4' :
                cout << endl; separator();
                search(monCatalogue);
                break;
            case '5' :
                quit = true;
                break;
            default :
                cout << endl;
                separator();
                cout << "Inscrivez un chiffre entre 1 et 5" << endl;
                break;
        }
    }
    delete(answer);
    delete(monCatalogue);
}
void separator()
{
    cout << "--------------------------------------------" << endl;
}
void addTrajetSimple(Catalogue * monCatalogue)
{
    char* startPoint = new char[MAX_LENGTH];
    char* endPoint = new char[MAX_LENGTH];
    char* mean = new char[MAX_LENGTH];

    cout << "Point de depart :" << endl;
    cin >> startPoint;
    cout << "Point d'arrive :" << endl;
    cin >> endPoint;
    cout << "Moyen de transport :" << endl;
    cin >> mean;

    monCatalogue->AddTrajet(new TrajetSimple(startPoint, endPoint, mean));

    delete(startPoint);
    delete(endPoint);
    delete(mean);
}
void addTrajetCompose(Catalogue * monCatalogue)
{

}
void search(Catalogue * monCatalogue)
{
    char* startPoint = new char[MAX_LENGTH];
    char* endPoint = new char[MAX_LENGTH];

    cout << "Lieu de depart :" << endl;
    cin >> startPoint;
    cout << "Lieu d'arrivee :" << endl;
    cin >> endPoint;

    monCatalogue->Search(startPoint, endPoint);

    delete(startPoint);
    delete(endPoint);
}
