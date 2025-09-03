#pragma once

#include <stdlib.h>
#include "nodo.h"
#include "enlace.h"

typedef struct Grafo{
    Nodo* nodos[255];
    int numNodos;
    int numEnlaces;

} Grafo;