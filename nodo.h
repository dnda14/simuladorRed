#pragma once
#include <stdlib.h>

typedef struct Nodo
{
    int id; 
    char* nombre;
    struct Enlace* enlaces;
}Nodo;
