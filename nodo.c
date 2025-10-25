#include "nodo.h"
#include "enlace.h"


Nodo* createNodo(int id,char nombre[50]){
    Nodo* nodo = malloc(sizeof(Nodo));
    if (nodo==NULL)
    {
       printf("error creating nodo\n");
       return NULL;
    }
    nodo->id=id;
    nodo->enlaces= NULL;
    strncpy(nodo->nombre, nombre, sizeof(nodo->nombre) - 1);//copia segura evitando overflow
    nodo->nombre[sizeof(nodo->nombre) - 1] = '\0';
    return nodo;

}

void addEnlace(Nodo* nodo, Enlace* enlace){
    if (!nodo)
    {
        printf("nodo does not exit \n");
    }
        
    
}