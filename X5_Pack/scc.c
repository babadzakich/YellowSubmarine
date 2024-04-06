#include <stdio.h>
#include <stdlib.h>

int tout_step = 0;
int time = 0;
int curComponent = 1;
typedef struct vector
{
    size_t cap;
    size_t top;
    int* to;
    char color;
    int component;
}Vector;

typedef struct edge
{
    int depth, vertice;
}Depth;


void add_Vector(Vector * array, int to)
{
    if (array->cap == 0)
    {
        array->cap = 1;
        array->to = (int*)malloc(sizeof(int));
    }
    else if(array->cap == array->top)
    {
        array->cap *= 2;
        array->to = (int*)realloc(array->to, sizeof(int) * array->cap);
    }
    array->to[array->top++] = to;
}
int steck_pop(Vector *vector)
{
   // return vector->array[--vector->top];
}

void dfs(Vector* graph, int vertice, int* tout)
{
    time ++;
    graph[vertice].color = 1;
    for(int step = 0; step < graph[vertice].top; step++)
    {
        int v = graph[vertice].to[step];
        if(graph[v].color == 0)
        {
            dfs(graph, v, tout);
        }
    }
    graph[vertice].color = 2;
    graph[vertice].component = curComponent;
    time ++;
    tout[tout_step++] = vertice;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertices, edges;
    scanf("%d %d", &vertices, &edges);
    Vector* graph0 = (Vector*)malloc(sizeof(Vector) * vertices);
    Vector* reverse_graph0 = (Vector*)malloc(sizeof(Vector) * vertices);
    Vector* graph = graph0 - 1;
    Vector* reverse_graph = reverse_graph0 - 1;
    for(int step = 0; step < vertices; step++)
    {
        graph0[step].color = 0;
        graph0[step].cap = 0;
        graph0[step].top = 0;
        graph0[step].component = 0;
        reverse_graph0[step].color = 0;
        reverse_graph0[step].cap = 0;
        reverse_graph0[step].top = 0;
        reverse_graph0[step].component = 0;
    }

    for(int step = 0; step < edges; step++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        add_Vector(&graph[from], to);
        add_Vector(&reverse_graph[to], from);
    }

    int* tout = (int*)calloc(vertices + 1, sizeof(int));

    for(int step = 1; step <= vertices; step++)
    {
        if(graph[step].color == 0)
        {
            dfs(graph, step, tout);
        }
    }
    int counter = 0;
    int* temp = (int*)calloc(vertices, sizeof(int));
    tout_step = 0;
    curComponent = 1;
    for(int step = vertices - 1; step >= 0; step--)
    {
        if(reverse_graph[tout[step]].color == 0)
        {
            dfs(reverse_graph, tout[step], temp);
            counter++;
            curComponent++;
        }
    }
    printf("%d\n", counter);
    for(int step = 1; step <= vertices; step++)printf("%d ", reverse_graph[step].component);
    free(temp);
    free(tout);
    for(int step = 0; step < vertices; step++)
    {
        if(graph0[step].cap > 0) free(graph0[step].to);
        if(reverse_graph0[step].cap > 0) free(reverse_graph0[step].to);
    }
    return 0;
}