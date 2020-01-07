#if ! defined ( LOAD_FUNCTIONS_H )
#define LOAD_FUNCTIONS_H

#include <iostream>
#include <fstream>
//#include <cstring>

#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

void loadFromFile(Catalogue *monCatalogue);

void loadAll(std::ifstream &inFile, Catalogue *monCatalogue, unsigned int debut = 0, unsigned int fin = 0);
void loadByTrajectType(std::ifstream &inFile, Catalogue *monCatalogue);
void loadByCityName(std::ifstream &inFile, Catalogue *monCatalogue);

#endif
