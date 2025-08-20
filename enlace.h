#include <stdlib.h>
#include <stdio.h>

#include "nodo.h"


typedef struct Enlace{
    Nodo* destino;
    int ancho_banda;
    int latencia;
    float perdida;
    float weight;
    struct Enlace* siguiente;   
} Enlace;

Enlace* createEnlace(Nodo* destino, int anch_banda, int latencia, float perdida);