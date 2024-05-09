#include <stdio.h>
#include <stdlib.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

int time = 0;

struct pair{
    int to;
    int pos;
    int isMulti;
};
typedef struct vector
{
    size_t cap;
    size_t top;
    struct pair* array;
    char color;
}Vector;

Vector Stack;

int func_name(const void *arg1, const void *arg2)
{
    if (((struct pair*)arg1)->to < ((struct pair*)arg2)->to) return -1;
    else if (((struct pair*)arg1)->to == ((struct pair*)arg2)->to) return 0;
    else return 1;
}

void add_Vector(Vector * array, int to, int number)
{
    if (array->cap == 0)
    {
        array->cap = 1;
        array->array = (struct pair*)malloc(sizeof(struct pair));
    }
    else if(array->cap == array->top)
    {
        array->cap *= 2;
        array->array = (struct pair*)realloc(array->array, sizeof(struct pair) * array->cap);
    }
    array->array[array->top].pos = number;
    array->array[array->top].isMulti = 0;
    array->array[array->top++].to = to;
}
int steck_pop(Vector *vector)
{
   // return vector->array[--vector->top];
}

void dfs(Vector* graph, int vertice, int* enter, int* ret, int p, int pos, int pstep)
{
    enter[vertice] = ret[vertice] = ++time;
    graph[vertice].color = 2;
    for(int step = 0; step < graph[vertice].top; step++)
    {
        int u = graph[vertice].array[step].to;
        if (u == p) 
        {
            if (graph[vertice].array[step].pos != pos)
            {
                graph[u].array[pstep].isMulti = 1;
                graph[vertice].array[step].isMulti = 1;
            }
            continue;
        }
        if (graph[u].color == 2)
        {
            ret[vertice] = MIN(ret[vertice], enter[u]);
        }
        if(graph[u].color == 0)
        {
            dfs(graph, u, enter, ret, vertice, graph[vertice].array[step].pos, step);
            ret[vertice] = MIN(ret[vertice], ret[u]);
            if (ret[u] > enter[vertice])
            {
                if(graph[vertice].array[step].isMulti != 1) add_Vector(&Stack, graph[vertice].array[step].pos, 0);
            }
        }
    }
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Stack.top = 0;
    Stack.cap = 0;

    int vertices, edges;
    scanf("%d %d", &vertices, &edges);
    Vector* graph0 = (Vector*)malloc(sizeof(Vector) * vertices);
    Vector* graph = graph0 - 1;
    int* enter = (int*)calloc(vertices + 1, sizeof(int));
    int* ret = (int*)calloc(vertices + 1, sizeof(int));
    for(int step = 0; step < vertices; step++)
    {
        graph0[step].color = 0;
        graph0[step].cap = 0;
        graph0[step].top = 0;
    }

    int number = 1;
    for(int step = 0; step < edges; step++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        add_Vector(&graph[from], to, number);
        add_Vector(&graph[to], from, number);
        number++;
    }

    for(int step = 1; step <= vertices; step++)
    {
        if(graph[step].color == 0)
        {
            dfs(graph, step, enter, ret, -1, 0, 0);
        }
    }
    qsort(Stack.array, Stack.top, sizeof(struct pair), func_name);
    printf("%zu\n", Stack.top);
    for(int step = 0; step < Stack.top; step++)
    {
        printf("%d ", Stack.array[step].to);
    }
    free(Stack.array);
    free(enter);
    free(ret);
    for(int step = 0; step < vertices; step++)
    {
        if(graph0[step].cap > 0) free(graph0[step].array);
    }
    return 0;
}