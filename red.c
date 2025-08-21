#include "red.h"



struct Graph* createGrpah(){
    struct Graph* graph = malloc(sizeof(struct Graph)); 
    graph->numNodos = 0;
    graph->numEnlaces = 0;

    if (graph == NULL)
    {
        printf("Error attempintg creatiion of graph");
        return NULL;
    }
    for (int i = 0; i < 255; i++) {
        graph->nodos[i] = NULL;
    }
    
    return graph;
}

void insertNode(struct Graph* graph, Nodo* nodo){
    graph->nodos[graph->numNodos++] = nodo;

}


void freeGraph(struct Graph* graph){
    if(graph == NULL) return;
    free(graph);
    graph = NULL;           
}

void findPath(struct Graph* graph, int start, int end){
    if(graph ==NULL){
        pritf("graph is null");
        return;
    }
    Nodo *ruta;
    ruta = useDijkstra(graph, start, end);
    printf("Finding path from %d to %d\n", start, end);
}
