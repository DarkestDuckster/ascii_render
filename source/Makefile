IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

EXE = Renderer.exe

LIBS= -lm

_DEPS = Vector.h Screen.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Vector.o Screen.o Rasterizer.o Triangle.o Scene.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(IDIR)/%.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE): $(OBJ) main.c
	$(CC) -c -o $(ODIR)/main.o main.c $(CFLAGS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(EXE) 
