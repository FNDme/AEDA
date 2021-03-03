IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g

ODIR=../src
LDIR =../lib

LIBS=-lm

_OBJ = hormiga.o mundo.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: hormiga_langton

$(ODIR)/hormiga.o: $(ODIR)/hormiga.cc  
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/mundo.o: $(ODIR)/mundo.cc  
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/main.o: $(ODIR)/main.cc  
	$(CC) -c -o $@ $< $(CFLAGS)

hormiga_langton: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~