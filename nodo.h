#pragma once
#include <stdlib.h>

typedef struct Nodo
{
    int id; 
    char nombre[50];
    struct Enlace* enlaces;
}Nodo;
