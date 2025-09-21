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
    findPath(red->grafo, start, end);
}
