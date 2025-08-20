#pragma once
#include <stdlib.h>

#include "dijkstra.c"

struct Edge{
    int to;
    int weight;
    int from;
};
struct Graph{
    int vertices[255];
    int numVertices;

    int edges[255][255];
    int numEdges;

    struct Edge *edgeList;
};

struct Graph* createGrpah(){
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = 0;
    graph->numEdges = 0;

    if (graph == NULL)
    {
        printf("Error attempintg creatiion of graph");
        return NULL;
    }
    graph->edgeList = malloc(sizeof(struct Edge) * 255);
    if ((graph->edgeList) == NULL)
    {
        printf("error attempting creation of list of edges");
        free(graph);
        return NULL;
    }
    
    return graph;
}

void insertNode(struct Graph* graph, int vertice){
    graph->vertices[graph->numVertices++] = vertice;

}

void insertEdge(struct Graph* graph, struct Edge * edge){
    graph->edgeList[graph->numEdges++] = *edge;
    graph->edges[edge->from][edge->to] = edge->weight;

}

void freeGraph(struct Graph* graph){
    if(graph == NULL) return;
    free(graph->edgeList);
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
