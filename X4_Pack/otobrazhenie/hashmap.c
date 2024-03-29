#include "hashmap.h"
#include <stdlib.h>
#include <stdint.h>

//creates and returns new hash table with:
// [ef] –- function which compares keys for equality
// [hf] –- function which produces a hash for a key
// [size] –- prescribed size/capacity of the hash table (number of cells)
__attribute__((visibility(HASHMAP_API))) HashMap HM_Init ( EqualFunc ef , HashFunc hf , int size )
{
    HashMap table;
    table.ef = ef;
    table.hf = hf;
    table.size = size;
    table.table = (vector*)malloc(sizeof(vector) * size);
    for (int step = 0; step < size; step++)
    {
        table.table[step].cap = 1;
        table.table[step].top = 0;
        table.table[step].keys = (cpvoid*)malloc(sizeof(cpvoid));
        table.table[step].values = (cpvoid*)malloc(sizeof(cpvoid));
    }
    return table;
}

//frees memory of hash map [self]
//note: called exactly once for every hash map created by HM_Init
__attribute__((visibility(HASHMAP_API))) void HM_Destroy ( HashMap * self )
{
    for(int step = 0; step < self->size; step++)
    {
        free(self->table[step].keys);
        free(self->table[step].values);
    }
    free(self->table);
}

//returns value corresponding to the specified key [key] in hash map [self]
//if [key] is not present in the map, then returns NULL
__attribute__((visibility(HASHMAP_API))) cpvoid HM_Get ( const HashMap * self , cpvoid key )
{
    uint32_t hash = self->hf(key) % self->size;
    for(int step = 0; step < self->table[hash].top; step++)
    {
        if (self->ef(key, self->table[hash].keys[step]))
        {
            return self->table[hash].values[step];
        }
    }
    return NULL;
}

//sets value [value] for the key [key] in hash map [self]
//if [self] already has some value for [key], it is overwritten
__attribute__((visibility(HASHMAP_API))) void HM_Set ( HashMap * self , cpvoid key , cpvoid value )
{
    uint32_t hash = self->hf(key) % self->size;
    if(self->table[hash].cap == 0)
    {
        self->table[hash].cap = 1;
        self->table[hash].values = (cpvoid*)malloc(sizeof(cpvoid));
        self->table[hash].keys = (cpvoid*)malloc(sizeof(cpvoid));
        self->table[hash].keys[self->table[hash].top] = &key;
        self->table[hash].values[self->table[hash].top++] = &value;
    }
    else
    {
        int flag = 1;
        for(int step = 0; step < self->table[hash].top; step++)
        {
            if(self->ef(key, self->table[hash].keys[step]))
            {
                self->table[hash].values[step] = value;
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            if (self->table[hash].cap == self->table[hash].top)
            {
                self->table[hash].cap *= 2;
                self->table[hash].keys = (cpvoid*)realloc(self->table[hash].keys, sizeof(cpvoid) * self->table[hash].cap);
                self->table[hash].values = (cpvoid*)realloc(self->table[hash].values, sizeof(cpvoid) * self->table[hash].cap);
            }
            self->table[hash].keys[self->table[hash].top] = key;
            self->table[hash].values[self->table[hash].top++] = value;
        }
    }
}