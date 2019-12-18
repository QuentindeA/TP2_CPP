#if ! defined ( LOAD_FUNCTIONS_H )
#define LOAD_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

void loadFromFile(Catalogue *monCatalogue);
const TrajetSimple *makeTrajetSimple(std::string readLine);
const TrajetCompose *makeTrajetCompose(std::string newLine, int nbTrajet, std::ifstream & in);

#endif
