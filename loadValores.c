#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"
#include "grafo.h"
#include "enlace.h"

#include "cJSON.h"
#include "hash.h"


char* readFile(const char* filename){
    FILE* file = fopen(filename, "r");
    if(!file){
        printf("Error al cargar el json %s \n", filename);
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long tam = ftell(file);
    rewind(file);

    char* data = (char*)malloc(tam +1);
    fread(data, 1, tam, file);
    data[tam]= '\0';
    fclose(file);

    return data;
}


Nodo* loadValores(const char *filename){
    char* dataJson = readFile(filename);
    if(dataJson == NULL) return 0;

    cJSON* json = cJSON_Parse(dataJson);
    free(dataJson);
    if(!json) return NULL;

    cJSON* nodosJson = cJSON_GetObjectItemCaseSensitive(json, "nodos");
    int numNodos = cJSON_GetArraySize(nodosJson);

    Nodo* nodos = malloc(sizeof(Nodo) * numNodos);

    cJSON* nodoJson;
    int i=0;
    cJSON_ArrayForEach(nodoJson, nodosJson){
        nodos[i].id = i;
        nodos[i].nombre = strdup(nodoJson->valuestring);
        i++;
    }



    cJSON* enlacesJson = cJSON_GetObjectItemCaseSensitive(json, "enlaces");
    int numEnlaces = cJSON_GetArraySize(enlacesJson);
    Enlace* enlaces = malloc(sizeof(Enlace) *numEnlaces);

    cJSON* enlaceJson;
    int j = 0;
    cJSON_ArrayForEach(enlaceJson, enlacesJson){
        cJSON* origenJson = cJSON_GetObjectItemCaseSensitive(enlaceJson,"origen");
        add_or_increment(origenJson->valuestring);
        cJSON* destinoJson = cJSON_GetObjectItemCaseSensitive(enlaceJson, "destino");
        cJSON* tipoJson = cJSON_GetObjectItemCaseSensitive(enlaceJson, "tipo");
        cJSON* anchoBandaJson = cJSON_GetObjectItemCaseSensitive(enlaceJson, "anchoBanda");
        
        cJSON* latenciaJson = cJSON_GetObjectItemCaseSensitive(enlaceJson, "retardo");
        cJSON* perdidaJson = cJSON_GetObjectItemCaseSensitive(enlaceJson, "perdidad");

        enlaces[j] = *createEnlace(
            strdup(origenJson->valuestring),
            strdup(destinoJson->valuestring),
            strdup(tipoJson->valuestring),
            strtof(anchoBandaJson->valuestring,NULL),

            strtof(latenciaJson->valuestring, NULL),
            strtof(perdidaJson->valuestring,NULL)

        );


        j++;        

    }
    

    Grafo* grafo = malloc(sizeof(Grafo));

    cJSON_Delete(json);
    return nodos;

}

int main(){
    Nodo* nodos = loadValores("topologia.json");
    if(nodos == NULL){
        printf("Error al cargar los nodos\n");
        return 1;
    }

    // Imprimir los nodos cargados
    for(int i = 0; i < 4; i++){ // Suponiendo que hay 5 nodos
        printf("Nodo ID: %d, Nombre: %s\n", nodos[i].id, nodos[i].nombre);
        free(nodos[i].nombre); // Liberar la memoria asignada para el nombre
    }

    free(nodos); // Liberar la memoria asignada para los nodos
    return 0;
}
