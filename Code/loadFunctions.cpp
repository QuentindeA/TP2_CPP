#include <iostream>
#include <fstream>

#include "loadFunctions.h"

void loadFromFile(Catalogue *monCatalogue)
{
    string filePath;
    string newLine;

    cout << "Entrez le nom du fichier :" << endl;
    cin >> filePath;
    ifstream in(filepath);
    in >> newLine;
    while(!newLine[0].eof())
    {
    if (newLine[0] = 's')
        makeTrajetSimple(newLine);
    else if (newLine[0] = 'c')
        makeTrajetCompose(newLine, in);
	}

    monCatalogue.AddTrajet();
}

const TrajetSimple *makeTrajetSimple(string readLine)
{
    char *startPoint = char[MAX_LENGTH];
    char *endPoint = char[MAX_LENGTH];
    char *mean = char[MAX_LENGTH];

    const TrajetSimple *ts = new const TrajetSimple(startPoint, endPoint, mean);

    return ts;
}

const TrajetCompose *makeTrajetCompose(string newLine, fstream in)
{

}
