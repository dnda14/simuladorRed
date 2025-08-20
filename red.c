#pragma once
#include <stdlib.h>
#include "nodo.h"
#include "dijkstra.c"
#include "enlace.h"


struct Graph{
    Nodo nodos[255];
    int numNodos;

    int enlaces[255][255];
    int numEnlaces;

    struct Enlace *enlaceList;
};

struct Graph* createGrpah(){
    struct Graph* graph = malloc(sizeof(struct Graph)); 
    graph->numNodos = 0;
    graph->numEnlaces = 0;

    if (graph == NULL)
    {
        printf("Error attempintg creatiion of graph");
        return NULL;
    }

    graph->enlaceList = malloc(sizeof(struct Edge) * 255);

    if ((graph->enlaceList) == NULL)
    {
        printf("error attempting creation of list of enlaces");
        free(graph);
        return NULL;
    }
    
    return graph;
}

void insertNode(struct Graph* graph, int vertice){
    graph->vertices[graph->numNodos++] = vertice;

}

void insertEdge(struct Graph* graph, struct Enlace * enlace){
    graph->enlaceList[graph->numEnlaces++] = *enlace;
    graph->enlaces[enlace->from][enlace->to] = enlace->weight;

}

void freeGraph(struct Graph* graph){
    if(graph == NULL) return;
    free(graph->enlaceList);
    free(graph);
    graph = NULL;           
}

void findPath(struct Graph* graph, int start, int end){
    if(graph ==NULL){
        pritf("graph is null");
        return;
    }
    int *ruta;
    ruta= useDijkstra(graph, start, end);
    printf("Finding path from %d to %d\n", start, end);
}
