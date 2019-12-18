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
    while(!in.eof())
    {
        if (newLine[0] == 's')
            monCatalogue->AddTrajet(makeTrajetSimple(newLine));
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
            monCatalogue->AddTrajet(makeTrajetCompose(nbTrajet, in));
    	}
        in >> newLine;
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
