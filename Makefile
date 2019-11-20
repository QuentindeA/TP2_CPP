.PHONY: all, clean

CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic -std=c++11 -DMAP

LIBS += -lpthread

PROG = Trajet.o TrajetSimple.o


all: $(PROG)


Trajet.o: Trajet.cpp Trajet.h
	$(CC) $(CFLAGS) -c -o $@ $<

TrajetSimple.o : TrajetSimple.cpp TrajetSimple.h
	$(CC) $(CFLAGS) -c -o $@ $<

Trajet: Trajet.o
	$(CC) -o $@ $^ $(LIBS)


clean:
	rm -f $(PROGS) *.o
