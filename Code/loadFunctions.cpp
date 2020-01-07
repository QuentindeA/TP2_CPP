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
    inFile >> newLine;

    while(!inFile.eof())
    {
        if ( numeroTrajet >= debut && ( fin == 0 || numeroTrajet <= fin ) )
        {
            cout << newLine << endl;
            cout << numeroTrajet << " " << debut << " " << fin << endl;
            if (newLine[0] == 's')
            {
                monCatalogue->AddTrajet(makeTrajetSimple(newLine));
                numeroTrajet++;
            }
            else if (newLine[0] == 'c')
            {
                int len = newLine.length()-1;
                char * nbTrajetString = new char[len];
                for( int i = 0; i < len; ++i)
                {
                    nbTrajetString[i] = newLine[i+2];
                }
                int nbTrajet = atoi(nbTrajetString);
                delete[] nbTrajetString;
                monCatalogue->AddTrajet(makeTrajetCompose(nbTrajet, inFile));
                numeroTrajet++;
            }
        }
        else
        {
            if ( numeroTrajet < debut )
            {
                nextTrajet(inFile);
                numeroTrajet++;
            }
            else
            {
                break;
            }
        }
        inFile >> newLine;
    }
}

void loadByTrajectType(ifstream &inFile, Catalogue *monCatalogue)
{

}

void loadByCityName(ifstream &inFile, Catalogue *monCatalogue)
{

}

void nextTrajet(ifstream &inFile)
{
    string newLine;
    cout << "on passe : " << endl;
    inFile >> newLine;
    cout << newLine << endl;
    while( !inFile.eof() && (newLine[0] == 's' || newLine[0] == 'c'))
    {
        cout << newLine << endl;
        inFile >> newLine;
    }
}

const TrajetSimple *makeTrajetSimple(string &readLine)
{
	int lenLine = readLine.length();
	int offset = 2;

	int option=0; //0:start 1:end 2:mean
    char *startPoint = new char[lenLine];
    char *endPoint = new char[lenLine];
    char *mean = new char[lenLine];

	for(int i = 2; i < lenLine; ++i)
	{
		char nextC = readLine[i];
		if(nextC != '|')
		{
			switch (option)
			{
				case(0):
					startPoint[i-offset] = nextC;
					break;
				case(1):
					endPoint[i-offset] = nextC;
					break;
				default:
					mean[i-offset] = nextC;
					break;
			}
		}
		else
		{
            switch (option)
			{
                case(0):
                    startPoint[i-offset] = '\0';
                    break;
                case(1):
                    endPoint[i-offset] = '\0';
                    break;
                default:
                    mean[i-offset] = '\0';
                    break;
            }
            offset = i+1;
			option++;
		}
	}

    const TrajetSimple *ts = new const TrajetSimple(startPoint, endPoint, mean);

    delete[] startPoint;
    delete[] endPoint;
    delete[] mean;

    return ts;
}

const TrajetCompose *makeTrajetCompose(int nbTrajet, ifstream &in)
{
	string newLine;

	const TrajetSimple **mesTrajetsSimples = new const TrajetSimple *[nbTrajet];

	for(int i = 0; i < nbTrajet; ++i)
	{
		in >> newLine;
		//if (newLine[0] = 's')
			mesTrajetsSimples[i] = makeTrajetSimple(newLine);
		//else
		//	mesTrajetsSimples[i] = makeTrajetCompose(newLine, in);
	}
	return new TrajetCompose(mesTrajetsSimples, nbTrajet);
}
