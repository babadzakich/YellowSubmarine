#include<stdio.h>
#include<stdlib.h>

typedef struct vector
{
    size_t cap;
    size_t top;
    int* array;
    char color;
}Vector;

int flag = 0;
int flag2 =0;
int cycle = 0;

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

void dfs(Vector* graph, int vertice, Vector* Stack)
{
    if (flag) return;
    
    graph[vertice].color = 1;
    for(int step = 0; step < graph[vertice].top; step++)
    {
        int v = graph[vertice].array[step];
        if (graph[v].color == 0)
        {
            dfs(graph, v, Stack);
            if (flag)
            {
                if (!flag2)
                {
                    add_Vector(Stack, vertice);
                }
                if (vertice == cycle) flag2 = 1;
                return;
            }
        }
        else if(graph[v].color == 1)
        {
            flag = 1;
            cycle = v;
            add_Vector(Stack, vertice);
            return;
        }
    }
    graph[vertice].color = 2;
}


int main(void)
{
    int vertices, edges;
    scanf("%d %d", &vertices, &edges);
    Vector* graph0 = (Vector*)calloc(vertices, sizeof(Vector));
    Vector* graph = graph0 - 1;
    for(int step = 0; step < vertices; step++)
    {
        graph0[step].cap = 0;
        graph0[step].top = 0;
        graph0[step].color = 0;
    }
    Vector Stack;
    Stack.cap = 0;
    Stack.top = 0;
    
    for(int step = 0; step < edges; step++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        add_Vector(&graph[from], to);
    }

    for(int step = 1; step <= vertices; step++)
    {
        if(graph[step].color == 0)
        {
            dfs(graph, step, &Stack);
            if (flag)
            {
                printf("%d\n", Stack.top);
                while(Stack.top > 0)
                {
                    printf("%d ", steck_pop(&Stack));
                }
                break;
            }
        }
    }
    if (!flag) printf("-1");
    if (Stack.cap > 0)free(Stack.array);
    for(int step = 0; step < vertices; step++) if (graph0[step].cap > 0) free(graph0[step].array);
    free(graph0);
    return 0;
}