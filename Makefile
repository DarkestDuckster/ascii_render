IDIR =include
CC=gcc
CFLAGS=-I$(IDIR)

SRCDIR=src

ODIR=obj
LDIR =../lib

EXE = Renderer.exe

LIBS= -lm

_DEPS = Vector.h Screen.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Vector.o Screen.o Rasterizer.o Triangle.o Scene.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRCDIR)/%.c $(IDIR)/%.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE): $(OBJ) $(SRCDIR)/main.c
	$(CC) -c -o $(ODIR)/main.o $(SRCDIR)/main.c $(CFLAGS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(EXE) 
