#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
    
Par* tabla = NULL;

void add_or_update(const char* key, int value){
    Par* par;
    HASH_FIND_STR(tabla,key,par);
    if (par == NULL)
    {
        par = (Par*)malloc(sizeof(Par));
        par->key = strdup(key);
        par->value = value;
        HASH_ADD_STR(tabla,key,par);
        printf("added: %s -- %d\n", par->key, par->value);
    } else{
        par->value = value;
        printf("upted: %s -- %d\n", par->key, par->value);
    }
    
}

void add_or_increment(const char* key){
    int value = 1;
    Par* par;
    HASH_FIND_STR(tabla,key,par);
    if(par){
        par->value ++;
    }else{
        par = (Par*)malloc(sizeof(Par));
        par->key = strdup(key);
        par->value = value;
        HASH_ADD_STR(tabla,key,par);
        printf("added: %s -- %d\n", par->key, par->value);
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

/* int main(){
    add_update("nodo A", 1);
    add_update("nodo B", 1);
    add_update("nodo C", 1);
    show();
    add_update("nodo A", 3);
    show();
} */



