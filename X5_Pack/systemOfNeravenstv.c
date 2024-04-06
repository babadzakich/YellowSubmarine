#include <stdio.h>
#include <stdlib.h>

typedef struct vector
{
    size_t cap;
    size_t top;
    int* array;
    int color;
    int time, depth;
}Vector;

typedef struct tout
{
    int time;
    int vertice;
}Tout;
int toutStep = 0;
int time;
int flag = 0;

int func_name(const void *arg1, const void *arg2)
{
    if (((Tout*)arg1)->time > ((Tout*)arg2)->time) return -1;
    else if (((Tout*)arg1)->time == ((Tout*)arg2)->time) return 0;
    else return 1;
}

void add_Vector(Vector * array, int num)
{
    if (array->cap == 0)
    {
        array->cap = 1;
        array->array = (int*)malloc(sizeof(int));
    }
    else if(array->cap == array->top)
    {
        array->cap *= 2;
        array->array = (int*)realloc(array->array, sizeof(int) * array->cap);
    }
    array->array[array->top++] = num;
}
int steck_pop(Vector *vector)
{
    return vector->array[--vector->top];
}

void dfs(Vector* graph, int vertice, Tout* tout)
{
    if (flag)return;
    time++;
    graph[vertice].depth = time; 
    graph[vertice].color = 1;
    for(int step = 0; step < graph[vertice].top; step++)
    {
        int v = graph[vertice].array[step];
        if (graph[v].color == 0)
        {
            dfs(graph, v, tout);
        }
        else if(graph[v].color == 1)
        {
            flag = 1;
            return;
        }
    }
    graph[vertice].color = 20;
    time ++;
    graph[vertice].time = time;
    tout[toutStep++].vertice = vertice;
}

int main(void)
{
    time = 0;
    int variables, equalities;
    scanf("%d %d", &variables, &equalities);
    Vector* i = (Vector*)calloc(variables,sizeof(Vector));
    Vector* graph = i - 1;
    for(int step = 0; step < variables; step++)
    {
        i[step].cap = 0;
        i[step].top = 0;
        i[step].time = 0;
        i[step].color = 0;
        i[step].depth = 0;
    }
    Tout* tout = (Tout*)calloc(variables, sizeof(Tout));
    for(int step = 0; step < equalities; step++)
    {
        int var1, var2;
        scanf("%d %d", &var1, &var2);
        add_Vector(&graph[var1], var2);
    }
    for(int step = 1; step <= variables; step++)
    {
        if (graph[step].color == 0)
        {
            dfs(graph, step, tout);
        }
    }
    if (!flag)
    {
        printf("YES\n");
        // qsort(tout, variables, sizeof(Tout), func_name);
        int* result = (int*)malloc(sizeof(int)*variables);
        for(int step = 0; step < variables; step++)
        {
            result[tout[variables - step - 1].vertice-1] = step+1;
        }
        for(int step = 0; step < variables; step++) printf("%d ", result[step]);
        free(result);
    }
    else printf("NO\n");
    free(tout);
    for(int step = 0; step < variables; step++)
    {
        if (i[step].array) free(i[step].array);
    }
    free(i);
    return 0;
}