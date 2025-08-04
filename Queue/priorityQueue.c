#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct PriorityQueue
{
    int *array;
    int size;
    int capacity;
};

struct priorityQueue *create_pq(int capacity)
{
    struct PriorityQueue *pq = malloc(sizeof(struct PriorityQueue));
    pq->array = malloc(capacity * sizeof(int));

    return pq;
}

bool is_empty(struct PriorityQueue *pq)
{
    if (pq->size == 0)
    {
        printf("Priority Queue is empty.\n");
        return 1;
    }
    else
    {
        printf("Priority Queue is not empty.\n");
        return 0;
    }
}

bool is_full(struct PriorityQueue *pq)
{
    if (pq->size == pq->capacity)
    {
        printf("Priority Queue is full.\n");
        return 1;
    }
    else
    {
        printf("Queue is not full.\n");
        return 0;
    }
}

int get_max(struct PriorityQueue *pq)
{
    if (!is_empty(pq))
    {
        return pq->array[0];
    }
}

void heapify_up(struct PriorityQueue *pq)
{
   /*  
    - The parent of a node at index `i` is at index `(i - 1) / 2`.
    - The children of a node at index `i` are at indices `2 * i + 1` and `2 * i + 2`. 
    */
   if (pq->size == 2)
   {
        if(pq->array[0]<pq->array[1])
    {
        
    }
   }else if(pq->size>2)
   {

   }
   
}