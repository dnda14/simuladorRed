#include "red.h"

Grafo* crearGrafo(){
    struct Grafo* grafo = malloc(sizeof(struct Grafo)); 
    grafo->numNodos = 0;
    grafo->numEnlaces = 0;

    if (grafo == NULL)
    {
        printf("Error attempintg creatiion of red");
        return NULL;
    }
    for (int i = 0; i < 255; i++) {
        grafo->nodos[i] = NULL;
    }
    
    return grafo;
}

void insertNode(struct Grafo* grafo, Nodo* nodo){
    grafo->nodos[grafo->numNodos++] = nodo;
}


void freeGraph(struct Red* red){
    if(red == NULL) return;
    free(red);
    red = NULL;           
}

void findPath(struct Red* red, int start, int end){
    if(red ==NULL){
        printf("red is null");
        return;
    }
    Nodo *ruta;
    ruta = useDijkstra(red, start, end);
    printf("Finding path from %d to %d\n", start, end);
}
