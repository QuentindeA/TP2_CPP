#if ! defined ( SAVEFUNCTIONS_H )
#define SAVEFUNCTIONS_H
#include <iostream>
#include <fstream>
#include "Catalogue.h"
#include "Trajet.h"
using namespace std;

void saveToFile(Catalogue *monCatalogue);

bool saveAll(ofstream &outFile, Catalogue * monCatalogue, unsigned int begin = 0, unsigned int end = 0);
bool saveByTrajectType(ofstream &outFile, Catalogue * monCatalogue);
bool saveByCityName(ofstream &outFile, Catalogue * monCatalogue);
bool saveInterval(ofstream &outFile, Catalogue * monCatalogue);



#endif // SAVEFUNCTIONS_H
