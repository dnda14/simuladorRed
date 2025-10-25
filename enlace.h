#include <stdlib.h>
#include <stdio.h>

#include "nodo.h"


typedef struct Enlace{
    char* origen;
    char* destino;
    char* tipo;
    float ancho_banda;
    int latencia;
    float perdida;
    float weight;
} Enlace;

Enlace* createEnlace(char* origen, char* destino,char* tipo, float ancho_banda, float latencia, float perdida);