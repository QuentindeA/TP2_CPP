#include "loadFunctions.h"
#include "Trajet.h"

using namespace std;

void loadFromFile(Catalogue *monCatalogue)
{
    string filePath;
    string newLine;

    cout << "Entrez le nom du fichier :" << endl;
    cin >> filePath;
    ifstream in(filePath);
    in >> newLine;
    while(!newLine[0].eof())
    {
    if (newLine[0] = 's')
        monCatalogue.addTrajet(makeTrajetSimple(newLine));
    else if (newLine[0] = 'c')
    {
		int len = newLine.length-1
		char * nbTrajetString[len];
		for( int i = 0; i < len; ++i)
		{
			nbTrajetString[i] = newLine[i+2];
		}
		int nbTrajet = atoi(nbTrajetString);
        monCatalogue.addTrajet(makeTrajetCompose(newLine, nbTrajet, in));
	}
}

    monCatalogue.AddTrajet();
}

const TrajetSimple *makeTrajetSimple(string &readLine)
{
	int lenLine = readLine.length;
	int offset;

	int option=0; //0:start 1:end 2:mean 
    char *startPoint = char[lenLine];
    char *endPoint = char[lenLine];
    char *mean = char[lenLine];

	for(int i = 0; i < lenLine; ++i)
	{
		char nextC = readLine[i];
		if(nextC != '|')
		{
			switch (option)
			{
				case(0):
					startPoint[i] = nextC;
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
			offset = i+1;
			option++;
		}
	}

    const TrajetSimple *ts = new const TrajetSimple(startPoint, endPoint, mean);

    return ts;
}

const TrajetCompose *makeTrajetCompose(string newLine, int nbTrajet, fstream &in)
{
	string newLine;
	
	const TrajetSimple **mesTrajetsSimples = new const TrajetSimple *[nbTrajetSimple];

	for(int i = 0; i < nbTrajet; ++i)
	{
		in >> newLine;
		//if (newLine[0] = 's')
			mesTrajetsSimples[i] = makeTrajetSimple(newLine);
		//else 
		//	mesTrajetsSimples[i] = makeTrajetCompose(newLine, in);
	}
	return new TrajetCompose(mesTrajetsSimples);
}
