#pragma once
#define PRIORITY_QUEUE_H

#include <stdbool.h>

// Estructura de la cola de prioridad
struct PriorityQueue {
    int *array;
    int size;
    int capacity;
};

// Funciones disponibles
struct PriorityQueue *create_pq(int capacity);
bool is_empty(struct PriorityQueue *pq);
bool is_full(struct PriorityQueue *pq);
int get_max(struct PriorityQueue *pq);
void heapify_up(struct PriorityQueue *pq);
void heapify_down(struct PriorityQueue *pq);


