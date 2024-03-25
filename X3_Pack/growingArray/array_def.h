#define finka(A, B) A ## B
#define nkvd(A, B) finka(A, B)
#define sigma(A) nkvd(NAME, A)
#include<stdlib.h>

void sigma(_reserve)(NAME *vec , int capacity )
{
    if(vec->cap < capacity)
    {
        if (vec->cap * 2 < capacity) vec->cap = capacity;
        else vec->cap *= 2;
        vec->arr = (TYPE*)realloc(vec->arr, sizeof(TYPE) * vec->cap);
    }
}

void sigma(_init)(NAME *vec)
{
    vec->n = 0;
    vec->cap = 0;
    vec->arr = NULL;
}

void sigma(_destroy)(NAME *vec)
{
    if(vec->arr) free(vec->arr);
    sigma(_init)(vec);
}

int sigma(_push)(NAME *vec , TYPE value)
{
    sigma(_reserve)(vec, vec->n+1);
    vec->arr[vec->n++] = value;
    return vec->n - 1;
}

TYPE sigma(_pop)(NAME *vec)
{
    return vec->arr[--vec->n];
}

void sigma(_resize)(NAME *vec , int newCnt , TYPE fill)
{
    sigma(_reserve)(vec, newCnt);
    for(int step = vec->n; step < newCnt; step++)
    {
        vec->arr[step] = fill;
    }
    vec->n = newCnt;
}

void sigma(_insert)(NAME *vec , int where , TYPE *arr , int num)
{
    if (vec->n + num > vec->cap) sigma(_reserve)(vec, vec->cap + num);
    for (int step = vec->n - 1; step >= where; step--) 
    {
        vec->arr[step + num] = vec->arr[step];
    }
    for(int step = 0; step < num; step++)
    {
        vec->arr[where + step] = arr[step];
    }
    vec->n += num;
}

void sigma(_erase)(NAME *vec , int where , int num)
{
    for(int step = where+num; step < vec->n; step++)
    {
        vec->arr[step - num] = vec->arr[step];
    }
    vec->n -= num;
}