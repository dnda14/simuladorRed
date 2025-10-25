#pragma once

#include "uthash.h"

typedef struct {
    char* key;
    int value;
    UT_hash_handle hh;
} Par;

extern Par* tabla;

void add_or_update(const char* key, int value);
void add_or_increment(const char* key);
Par* search(const char* key);
void delete(const char* key);
void show();
void deleteAll();
