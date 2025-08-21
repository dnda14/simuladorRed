#pragma once
#include <stdlib.h>
#include "nodo.h"
#include "dijkstra.c"
#include "enlace.h"


struct Graph{
    Nodo* nodos[255];
    int numNodos;

    int numEnlaces;

};