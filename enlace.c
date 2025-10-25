#include "enlace.h"

Enlace* createEnlace(char* origen, char* destino, char* tipo, float ancho_banda, float latencia, float perdida) {
    if(destino== NULL && origen == NULL) return NULL;

    Enlace* enlace = malloc(sizeof( Enlace));

    if(enlace == NULL) {
        printf("Error creating enlace\n");
        return NULL;
    }

    enlace->origen = origen;
    enlace->destino = destino;
    enlace->tipo = tipo;
    enlace->ancho_banda = ancho_banda;
    
    enlace->latencia = latencia;
    enlace->perdida = perdida;
    enlace->weight = 0.34*latencia + 0.33*perdida + 0.33* (1/ancho_banda);


}