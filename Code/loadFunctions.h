#if ! defined ( LOAD_FUNCTIONS_H )
#define LOAD_FUNCTIONS_H

#include <iostream>
#include <fstream>

void loadFromFile(Catalogue *monCatalogue);
const TrajetSimple *makeTrajetSimple(std::string readLine);
const TrajetCompose *makeTrajetCompose(std::string newLine, int nbTrajet, std::ifstream & in);

#endif
