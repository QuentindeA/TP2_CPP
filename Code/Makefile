ECHO=@echo
RM=@rm
COMP=g++
EDL=g++
RMFLAGS=-f
CPPFLAGS=-Wall -Werror -ansi -pedantic -std=c++11
DEBUGFLAGS= -DMAP -g
EDLFLAGS=
INT=menu.h Catalogue.h Trajet.h TrajetSimple.h TrajetCompose.h saveFunctions.h loadFunctions.h
REAL=$(INT:.h=.cpp)
OBJ=$(INT:.h=.o)
EXE=exec
LIBS= #-lpthread ?
CLEAN=clean

.PHONY : $(CLEAN)

default : $(EXE)

debug: CPPFLAGS+= $(DEBUGFLAGS)
debug: $(EXE)

menu.o : menu.cpp
Catalogue.o : Catalogue.cpp Catalogue.h
Trajet.o : Trajet.cpp Trajet.h
TrajetSimple.o : TrajetSimple.cpp TrajetSimple.h
TrajetCompose.o : TrajetCompose.cpp TrajetCompose.h
saveFunctions.o : saveFunctions.cpp saveFunctions.h
loadFunctions.o :  loadFunctions.cpp loadFunctions.h

%.o : %.cpp
	$(ECHO) compil de \<$@\>
	$(COMP) $(CPPFLAGS) -c $<


$(EXE) : $(OBJ)
	$(ECHO) "edition des liens de <$(EXE)>"
	$(EDL) -o $(EXE) $(OBJ) $(LIBS)

$(CLEAN) :
	$(RM) $(RMFLAGS) $(OBJ) $(EXE) core

#options de make :
#	-s silence
#	-t touch
#	-p toutes les réglès implicites + info du makefile dans le meme dossier
#	-i ingore errors in commands
#	-k keep going after erros
