
#define finka(a, b) a##b
#define nkvd(a, b) finka(a, b)

#include<stdlib.h>
#include "array_decl.h"


//initializes members of [vec] structure for empty array
void nkvd(NAME,_init)(NAME *vec)
{
    vec->n = 0;
    vec->cap = 1;
    vec->arr = (TYPE*)malloc(sizeof(TYPE));
}
//makes array [vec] empty and frees its array buffer [vec->arr]
//note: this function can be called many times
void nkvd(NAME,_destroy)(NAME *vec)
{
    if(vec->arr) free(vec->arr);
    vec->n = 0;
    vec->cap = 0;
}
void nkvd(NAME,_reserve)(NAME *vec , int capacity )
{
    while (vec->cap <= capacity)
    {
        vec->arr = (TYPE*)realloc(vec->arr, sizeof(TYPE) * vec->cap * 2);
        vec->cap *= 2;
    }
}
//adds element [value] to the end of array [vec]
//returns index of the added elements
int nkvd(NAME,_push)(NAME *vec , TYPE value)
{
    if (vec->n == vec->cap) nkvd(NAME,_reserve)(vec, vec->cap);
    vec->arr[vec->n++] = value;
    return vec->n - 1;
}
//removes the last element from array [vec]
//returns removed element
TYPE nkvd(NAME,_pop)(NAME *vec)
{
    return vec->arr[--vec->n];
}
//ensures that array [vec] has enough storage for [capacity] elements
//note: address of elements surely won’t change before [vec->n] exceeds capacity
//lements at the end are removed
void nkvd(NAME,_resize)(NAME *vec , int newCnt , TYPE fill)
{
    if (newCnt > vec->cap) nkvd(NAME,_reserve)(vec, newCnt);
    if (vec->n < newCnt)
    {
        for(int step = vec->n; step < newCnt; step++)
        {
            vec->arr[step] = fill;
        }
    }
    vec->n = newCnt;
}
//inserts elements [arr[0]], [arr[1]], [arr[2]], ..., [arr[num-1]]
//in-between elements [vec->arr[where-1]] and [vec->arr[where]]
//note: the whole array [arr] cannot be part of array [vec]
//[where] may vary from 0 to [vec->n], [num] can also be zero
void nkvd(NAME,_insert)(NAME *vec , int where , TYPE *arr , int num)
{
    if (vec->n + num > vec->cap) nkvd(NAME,_reserve)(vec, vec->n + num);
    for(int step = 0; step < num; step++)
    {
        vec->arr[step+where+num]= vec->arr[step+where];
        vec->arr[step+where] = arr[step];
    }
    vec->n += num;
}
//removes elements [vec->arr[k]] for k = [where], [where+1], ..., [where+num-1]
//all the elements starting from [where+num]-th are shifted left by [num] positions
void nkvd(NAME,_erase)(NAME *vec , int where , int num)
{
    nkvd(NAME,_resize)(vec, vec->n + num, 0);
    for(int step = 0; step < num; step++)
    {
        vec->arr[where + step] = vec->arr[where + num + step];
    }
}