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
    if(red ==NULL){
        pritf("red is null");
        return;
    }
    Nodo *ruta;
    ruta = useDijkstra(red, start, end);
    printf("Finding path from %d to %d\n", start, end);
}
