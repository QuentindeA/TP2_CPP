#if ! defined ( SAVEFUNCTIONS_H )
#define SAVEFUNCTIONS_H

#include <ofstream>

void saveToFile(Catalogue *monCatalogue);

bool saveAll(ofstream outFile, Catalogue * monCatalogue);
bool saveByTrajectType(ofstream outFile, Catalogue * monCatalogue);
bool saveByCityName(ofstream outFile, Catalogue * monCatalogue);
bool saveInterval(ofstream outFile, Catalogue * monCatalogue);



#endif // SAVEFUNCTIONS_H
