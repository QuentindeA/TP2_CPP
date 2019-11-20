.PHONY: all, clean

CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic -std=c++11 -DMAP

LIBS += -lpthread

PROG = TrajetSimple_testU


all: $(PROG)


TrajetSimple_testU.o: TrajetSimple_testU.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

TrajetSimple_testU: TrajetSimple.o TrajetSimple_testU.o Trajet.o
	$(CC) -o $@ $^ $(LIBS)


clean:
	rm -f $(PROGS) *.o
