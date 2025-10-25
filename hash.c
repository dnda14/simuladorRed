#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"
    
typedef struct {
    char* key;
    int value;
    UT_hash_handle hh;
} Par;

Par* tabla = NULL;


void add_update(const char* key, int value){
    Par* p;
    HASH_FIND_STR(tabla,key,p);
    if (p == NULL)
    {
        p = (Par*)malloc(sizeof(Par));
        p->key = strdup(key);
        p->value = value;
        HASH_ADD_STR(tabla,key,p);
        printf("added: %s -- %d\n", p->key, p->value);
    } else{
        p->value = value;
        printf("upted: %s -- %d\n", p->key, p->value);
    }
    
}

Par* search(const char* key){
    Par* par;
    HASH_FIND_STR(tabla,key,par);
    return par;
}

void delete(const char* key){
    Par* par;
    HASH_FIND_STR(tabla,key,par);
    if (par)
    {
        HASH_DEL(tabla,par);
        free(par->key);
        free(par);
        printf("deleted: %s\n", key);
    }
}

void show(){
    Par* par, *tmp;
    HASH_ITER(hh,tabla,par,tmp){
        printf("%s -- %d\n", par->key, par->value);
    }
}

void deleteAll(){
    Par *par, *tmp;
    HASH_ITER(hh, tabla,par,tmp){
        HASH_DEL(tabla,par);
        free(par->key);
        free(par);
    }
}

int main(){
    add_update("nodo A", 1);
    add_update("nodo B", 1);
    add_update("nodo C", 1);
    show();
    add_update("nodo A", 3);
    show();
}



