#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct PriorityQueue
{
    int *array;
    int size;
    int capacity;
};

struct PriorityQueue *create_pq(int capacity)
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

void heapify_up(struct PriorityQueue *pq, int index)
{
    /*
     - The parent of a node at index `i` is at index `(i - 1) / 2`.
     */

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
void heapify_down(struct PriorityQueue *pq, int index)
{
    /*
     - The children of a node at index `i` are at indices `2 * i + 1` and `2 * i + 2`.
     */

     
}

int main() {
    // Create a priority queue and simulate an insertion
    int heap_array[5] = {20, 15, 10, 5, 18};
    struct PriorityQueue pq = {heap_array, 5, 5};
    int new_element_index = 4; // We just inserted '18' at index 4

    printf("Array before heapify_up: ");
    for (int i = 0; i < pq.size; i++) {
        printf("%d ", pq.array[i]);
    }
    printf("\n");

    // Call the correct heapify_up function
    heapify_up(&pq, new_element_index);

    printf("Array after heapify_up: ");
    for (int i = 0; i < pq.size; i++) {
        printf("%d ", pq.array[i]);
    }
    printf("\n");

    return 0;
}