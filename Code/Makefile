.PHONY: all, clean

CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic -std=c++11 -DMAP

LIBS += -lpthread

PROG = Catalogue.o Trajet.o TrajetSimple.o TrajetCompose.o


all: $(PROG)

Catalogue.o: Catalogue.cpp Catalogue.h
	$(CC) $(CFLAGS) -c -o $@ $<

Trajet.o: Trajet.cpp Trajet.h
	$(CC) $(CFLAGS) -c -o $@ $<

TrajetSimple.o : TrajetSimple.cpp TrajetSimple.h
	$(CC) $(CFLAGS) -c -o $@ $<

TrajetCompose.o: TrajetCompose.cpp TrajetCompose.h
	$(CC) $(CFLAGS) -c -o $@ $<

Trajet: Trajet.o
	$(CC) -o $@ $^ $(LIBS)


clean:
	rm -f $(PROGS) *.o
