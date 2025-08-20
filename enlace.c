#include "enlace.h"

Enlace* createEnlace(Nodo* nodo, int ancho_banda, int latencia, float perdida) {
    if(nodo== NULL) return NULL;

    Enlace* enlace = malloc(sizeof( Enlace));

    if(enlace == NULL) {
        printf("Error creating enlace\n");
        return NULL;
    }

    enlace->destino = nodo;
    enlace->ancho_banda = ancho_banda;
    enlace->latencia = latencia;
    enlace->perdida = perdida;
    enlace->weight = 0.34*latencia + 0.33*perdida + 0.33* (1/ancho_banda);

    enlace->siguiente = NULL;

}