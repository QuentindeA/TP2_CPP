#include "loadFunctions.h"
#include "Trajet.h"

using namespace std;

void loadFromFile(Catalogue *monCatalogue)
{
    string filePath;

    cout << "Entrez le nom du fichier :" << endl;
    cin >> filePath;
    ifstream inFile(filePath);


    int choice;
    cout << "Choix de la façon de chargement" << endl;
    cout << "1 : Charger tout" << endl;
    cout << "2 : Chargement d'un certain type de trajet" << endl;
    cout << "3 : Chargement selon la ville de depart et/ou d'arrivee" << endl;
    cout << "4 : Chargement des trajets dans un intervalle" << endl;
    cin >> choice;

    switch(choice)
    {
        case 1:
                loadAll(inFile, monCatalogue);
                break;
        case 2:
                loadByTrajectType(inFile, monCatalogue);
                break;
        case 3:
                loadByCityName(inFile, monCatalogue);
                break;
        case 4:
        {
                int debut;
                int fin;
                cout << "Choisissez votre intervalle :" << endl;
                cin >> debut;
                cin >> fin;
                loadAll(inFile, monCatalogue, debut, fin);
                break;
        }
        default:
                cout << "Votre choix n'est pas dans les possibilitees." << endl;
                break;
    }

}

void loadAll(ifstream &inFile, Catalogue * monCatalogue, unsigned int debut, unsigned int fin )
{
    string newLine;
    unsigned int numeroTrajet = 0;
    //inFile >> newLine;
    getline(inFile, newLine, '|');
    while(!inFile.eof())
    {
        if ( numeroTrajet >= debut && ( fin == 0 || numeroTrajet <= fin ) )
        {
            if (newLine == "s")
            {
                //monCatalogue->AddTrajet(makeTrajetSimple(newLine));
                string start;
                getline(inFile, start, '|');
                string end;
                getline(inFile, end, '|');
                string tMean;
                getline(inFile, tMean);

                monCatalogue->AddTrajet(new TrajetSimple(start.c_str(), end.c_str(), tMean.c_str()));
                numeroTrajet++;
            }
            else if (newLine == "c")
            {
                string slen;
                getline(inFile, slen);
                int nbTrajet = atoi(slen.c_str());
                const TrajetSimple **list = new const TrajetSimple *[nbTrajet];
                for(int i = 0; i<nbTrajet; ++i)
                {
                    getline(inFile, newLine, '|');
                    string start;
                    getline(inFile, start, '|');
                    string end;
                    getline(inFile, end, '|');
                    string tMean;
                    getline(inFile, tMean);
                    list[i] = new TrajetSimple(start.c_str(), end.c_str(), tMean.c_str());
                }
                monCatalogue->AddTrajet(new TrajetCompose(list, nbTrajet));
                numeroTrajet++;

            }
            getline(inFile, newLine, '!');
            getline(inFile, newLine);

        }
        else
        {
            if ( numeroTrajet < debut )
            {
                getline(inFile, newLine, '!');
                getline(inFile, newLine);
                numeroTrajet++;
            }
            else
            {
                break;
            }
        }

        getline(inFile, newLine, '|');
    }
}

void loadByTrajectType(ifstream &inFile, Catalogue *monCatalogue)
{

}

void loadByCityName(ifstream &inFile, Catalogue *monCatalogue)
{

}
