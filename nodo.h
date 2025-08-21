#pragma once
#include <stdlib.h>q

typedef struct Nodo
{
    int id; 
    char nombre[50];
    struct Enlace* enlaces;
}Nodo;
