#include "red.h"
#include <stdio.h>
#include <Queue/priorityQueue.h>
Nodo* useDjikstra(Nodo* origen, Nodo* destino, struct Red* red){
    if (red == NULL || red->grafo == NULL) {
        printf("Red o grafo es NULL\n");
        return NULL;
    }
    struct PriorityQueue *pq = create_pq(255);
    
    printf("Ejecutando Dijkstra de %d a %d\n", origen, destino);
    
    
     

    printf("Ruta mas corta: %s -> %s\n", origen->nombre, destino->nombre);
}

