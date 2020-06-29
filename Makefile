IDIR =include
CC=gcc
CFLAGS=-I$(IDIR)
OPTS = -Wall -Wextra -pedantic

SRCDIR=src

ODIR=obj
LDIR =../lib

EXE = renderer.exe

LIBS= -lm -lcurses

_DEPS = Vector.h Screen.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = screen.o vector.o renderable.o region.o border.o selectable.o intersectable.o rasterizer.o square.o dynamic_array.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRCDIR)/%.c $(IDIR)/%.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE): $(OBJ) $(SRCDIR)/main.c
	$(CC) -c -o $(ODIR)/main.o $(SRCDIR)/main.c $(CFLAGS) $(OPTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(OPTS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(EXE)
