#include "red.h"

struct Red* createRed(){
    struct Red* red = malloc(sizeof(struct Red)); 
    
    if (red == NULL)
    {
        printf("Error attempintg creatiion of red");
        return NULL;
    }
    red->grafo = crearGrafo();

    return red;
}


void findPath(struct Red* red, int start, int end){
    if(red == NULL || red->grafo == NULL){
        printf("Red o grafo es NULL\n");
        return;
    }
    
    printf("Buscando ruta de %d a %d\n", start, end);
    Nodo* ruta = useDijkstra(red, start, end);
    
    if (ruta != NULL) {
        printf("Ruta encontrada\n");
    } else {
        printf("No se encontró ruta\n");
    }
}

void freeRed(struct Red* red){
    if(red == NULL) return;
        
    if(red->grafo != NULL) {
        freeGrafo(red->grafo);
    }
    free(red);
}
