#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "priorityQueue.h"


struct PriorityQueue *create_pq(int capacity)
{
    struct PriorityQueue *pq = malloc(sizeof(struct PriorityQueue));

    if (!pq) return NULL;
    

    pq->array = malloc(capacity * sizeof(int));

    if(!pq->array) {
        free(pq);
        return NULL;
    }

    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

bool is_empty(struct PriorityQueue *pq)
{
    return pq->size == 0;
}

bool is_full(struct PriorityQueue *pq)
{
    return pq->size == pq->capacity;
}

int get_max(struct PriorityQueue *pq)
{
    if (!is_empty(pq))
    {
        return pq->array[0];
    }
    printf("Queue is empty\n");
    return 0;
}

int resize(struct PriorityQueue *pq)
{
    if (!pq) return 0;

    int newCap = pq->capacity * 2;
    int *newArr = malloc(newCap * sizeof(int));
    
    if (!newArr) {
        printf("Failed to resizing.\n");
        return 0;
    }
    for (int i = 0; i < pq->size; i++)
    {
        newArr[i] = pq->array[i];
    }
    free(pq->array);
    pq->array = newArr;
    pq->capacity = newCap;
    printf("Resized queue to capacity %d.\n", pq->capacity);
    return 1;
}
void insert(struct PriorityQueue *pq , int value)
{
    if (!pq) return;
    
    if(is_full(pq)){
        printf("Queue is full\n");
        if (!resize(pq)) return;
        
    }
    pq->array[pq->size] = value;
    pq->size++;

    printf("Inserted %d into the priority queue.\n", value);
    heapify_up(pq);
}
void pop(struct PriorityQueue *pq)
{
    if (is_empty(pq))
    {
        printf("Queue is empty. Not value to pop.\n");
        return;
    }
    
    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;
    heapify_down(pq);
    printf("Popped the maximum element.\n");
}

void heapify_up(struct PriorityQueue *pq)
{
    /*
     - The parent of a node at index `i` is at index `(i - 1) / 2`.
     */
    int index = pq->size - 1;
    int indexCurrent = (index - 1) / 2;
    while (index > 0)
    {
        if (pq->array[indexCurrent] >= pq->array[index])
        {
            printf("Heapify ended\n");
            return;
        }
        else
        {
            int aux = pq->array[indexCurrent];
            pq->array[indexCurrent] = pq->array[index];
            pq->array[index] = aux;
            index = indexCurrent;
            indexCurrent = (index - 1) / 2;
        }
    }
}
void heapify_down(struct PriorityQueue *pq)
{
    /*
     - The children of a node at index `i` are at indices `2 * i + 1` and `2 * i + 2`.
    */

    if(is_empty(pq)) return;

    int size = pq->size;

    int *arrayAux = pq ->array;
    

    int indexCurrent = 0;

    while (1)
    {

        int aux;
        int leftChildIndex = 2 * indexCurrent + 1;
        int rightChildIndex = 2 * indexCurrent + 2;
        int max;
        if (leftChildIndex >= size)
        {
            printf("\nHeapify ended\n");
            break;
        }

        if (rightChildIndex >= size)
        {
            max = leftChildIndex;
           
        }else{
            max = (arrayAux[leftChildIndex] > arrayAux[rightChildIndex]) ? leftChildIndex : rightChildIndex;
        }
        
        if (arrayAux[indexCurrent] >= arrayAux[max])
        {
           printf("\nHeapify ended\n");
            break;
        }
        
        
        aux = arrayAux[indexCurrent];
        arrayAux[indexCurrent] = arrayAux[max];
        arrayAux[max] = aux;

        indexCurrent = max;
        
       
        

    }
    
}

int main() {
    // Create a priority queue and simulate an insertion
    int heap_array[5] = {9, 15, 10, 5, 2};
    struct PriorityQueue pq = {heap_array, 5, 5};
    int new_element_index = 4; // We just inserted '18' at index 4

    printf("Array before heapify_up: ");
    for (int i = 0; i < pq.size; i++) {
        printf("%d ", pq.array[i]);
    }
    printf("\n");

    // Call the correct heapify_up function
    heapify_down(&pq);

    printf("Array after heapify_up: ");
    for (int i = 0; i < pq.size; i++) {
        printf("%d ", pq.array[i]);
    }
    printf("\n");

    return 0;
}