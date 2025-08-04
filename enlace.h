#include "nodo.h"

typedef struct Enlace{
    Nodo* destino;
    int ancho_banda;
    int retardo;
    float perdida;
    struct Enlace* siguiente;
} Enlace;