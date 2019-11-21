.PHONY: all, clean

CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic -std=c++11 -DMAP

LIBS += -lpthread

PROG = demo


all: $(PROG)


demo: demo.o Catalogue.o Trajet.o TrajetSimple.o TrajetCompose.o
	$(CC) -o $@ $^ $(LIBS)

demo.o: demo.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

Catalogue.o: Catalogue.cpp Catalogue.h
	$(CC) $(CFLAGS) -c -o $@ $<

Trajet.o: Trajet.cpp Trajet.h
	$(CC) $(CFLAGS) -c -o $@ $<

TrajetSimple.o : TrajetSimple.cpp TrajetSimple.h
	$(CC) $(CFLAGS) -c -o $@ $<

TrajetCompose.o: TrajetCompose.cpp TrajetCompose.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(PROGS) *.o
