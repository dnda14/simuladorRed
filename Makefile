CC = gcc
LIBS = -lws2_32

SRC1 = servidor.c
SRC2 = cliente.c

EXE1 = servidor.exe
EXE2 = cliente.exe

all: $(EXE1) $(EXE2)

$(EXE1): $(SRC1)
	$(CC) $(SRC1) -o $(EXE1) $(LIBS)

$(EXE2): $(SRC2)
	$(CC) $(SRC2) -o $(EXE2) $(LIBS)

run1: $(EXE1)
	./$(EXE1)

run2: $(EXE2)
	./$(EXE2)

clean:
	@echo "Borrando todos los ejecutables..."
	rm -f $(EXE1) $(EXE2)
	@echo "Limpieza completa."
