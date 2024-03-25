#include <stdio.h>
#include <stdlib.h>
#include "sol.h"
typedef struct elem{
    int to;
    int weight;
}Elem;
typedef struct vec{
    Elem* arr;
    size_t cap;
    size_t top;
}Vec;

Vec* graphVC;
//==============================================
//implement these functions in your solution:
//this function is called first to initialize graph
//you are expected to read graph here and fill internal data structures
void vecAdd(Vec* vector, int to, int weight)
{
    if (vector->cap == 0)
    {
        vector->cap = 1;
        vector->arr = (Elem*)malloc(sizeof(Elem));        
    }
    else if (vector->cap == vector->top)
    {
        vector->cap *= 2;
        vector->arr = (Elem*)realloc(vector->arr,sizeof(Elem) * vector->cap);
    }
    vector->arr[vector->top].to = to;
    vector->arr[vector->top++].weight = weight;
}
void init ()
{
    int n = getVerticesCount();
    graphVC = (Vec*)calloc(n,sizeof(Vec));
    
    for(int step = 0; step < n; step++)
    {
        graphVC[step].cap = 0;
        graphVC[step].top = 0;
    }

    Edge temp;
    int flag = readEdge(&temp);
    while (flag)
    {
        vecAdd(&graphVC[temp.from], temp.to, temp.weight);
        vecAdd(&graphVC[temp.to], temp.from, temp.weight);
        flag = readEdge(&temp);
    } 
}
//returns number of edges indicent to vertex iVertex
int getEdgesCount(int iVertex )
{
    return graphVC[iVertex].top;
}
//returns iIndex-th edge incident to the vertex iVertex
//it must have .from == Vertex and .to denoting the other end
Edge getIncidentEdge(int iVertex , int iIndex )
{
    Edge result;
    result.from = iVertex;
    result.to = graphVC[iVertex].arr[iIndex].to;
    result.weight = graphVC[iVertex].arr[iIndex].weight;
    return result;
}