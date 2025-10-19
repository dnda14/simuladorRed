CC = gcc
LIBS = -lws2_32
INCLUDES = -IC:\\Users\\dnda\\Documents\\Bibliotecas\\cJSON-1.7.19     # incluir carpeta donde está cJSON.h
CJSON_SRC = C:\\Users\\dnda\\Documents\\Bibliotecas\\cJSON-1.7.19\\cJSON.c

SRC1 = servidor.c
SRC2 = cliente.c

EXE1 = servidor.exe
EXE2 = cliente.exe

all: $(EXE1) $(EXE2)

$(EXE1): $(SRC1)
	$(CC) $(SRC1) $(CJSON_SRC) -o $(EXE1) $(LIBS) $(INCLUDES)

$(EXE2): $(SRC2)
	$(CC) $(SRC2) $(CJSON_SRC) -o $(EXE2) $(LIBS) $(INCLUDES)

run1: $(EXE1)
	./$(EXE1)

run2: $(EXE2)
	./$(EXE2)

clean:
	@echo "Borrando todos los ejecutables..."
	rm -f $(EXE1) $(EXE2)
	@echo "Limpieza completa."
