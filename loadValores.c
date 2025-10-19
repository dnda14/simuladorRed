#include <stdio.h>
#include <stdlib.h>

#include "nodo.h"

#include "cJSON.h"


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
    char* dataJson = readfile(filename);
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

    cJSON_Delete(json);
    return nodos;


    

}
