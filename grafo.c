#include "red.h"
#include "loadValores.c"


Grafo* crearGrafo(){
    struct Grafo* grafo = malloc(sizeof(struct Grafo)); 
    
    if (grafo == NULL)
    {
        printf("Error attempintg creatiion of red");
        return NULL;
    }

    grafo->numNodos = 0;
    grafo->numEnlaces = 0;

    for (int i = 0; i < 255; i++) {
        grafo->nodos[i] = NULL;
    }
    
    return grafo;
}

void insertNode(struct Grafo* grafo, Nodo* nodo){
    if (grafo == NULL || nodo == NULL) {
        printf("Grafo o nodo es NULL\n");
        return;
    }
    
    if (grafo->numNodos >= 255) {
        printf("Grafo lleno\n");
        return;
    }

    grafo->nodos[grafo->numNodos++] = nodo;

}

void loadNodos(){
    
}

void freeGrafo(struct Grafo* grafo){
    if(grafo == NULL) return;

    for(int i = 0; i < grafo->numNodos; i++){
        if(grafo->nodos[i] != NULL){
            free(grafo->nodos[i]);
        }
    }

    free(grafo);
    grafo = NULL;           
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
