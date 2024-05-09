#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define module 1000000000000001
#define chiselka 3327647950551527851

typedef struct container
{
    int to;
    long long weight;
}Container;

typedef struct vector
{
    size_t cap;
    size_t top;
    Container* array;
}Vector;

void add_Vector(Vector * array, int to, long long weight)
{
    if (array->cap == 0)
    {
        array->cap = 1;
        array->array = (Container*)malloc(sizeof(Container));
    }
    else if(array->cap == array->top)
    {
        array->cap *= 2;
        array->array = (Container*)realloc(array->array, sizeof(Container) * array->cap);
    }
    array->array[array->top].weight = weight;
    array->array[array->top].to = to;
    array->top++;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int vertices, edges, start;
    scanf("%d %d %d", &vertices, &edges, &start);
    Vector* graph = (Vector*)malloc(sizeof(Vector) * (vertices + 2));
    for(int step = 0; step <= vertices + 1; step++)
    {
        graph[step].cap = graph[step].top = 0;
    }

    for(int step = 0; step < edges; step++)
    {
        int from, to; 
        long long weight;
        scanf("%d %d %lld", &from, &to, &weight);
        add_Vector(&graph[from], to, weight);
    }
    
    long long dist[3001] = {0};
    int negative[3001] = {0};
    for(int step2 = 0; step2 <= vertices; step2++)
    {
        dist[step2] =  3327647950551527851;
    }
    dist[start] = 0;
    
    for(int phase = 0; phase < vertices - 1; phase++)
    {
        for(int vertice = 1; vertice <= vertices; vertice++)
        {
            for(int edgeNum = 0; edgeNum < graph[vertice].top; edgeNum++)
            {
                int v = graph[vertice].array[edgeNum].to;
                int u = vertice;
                if (dist[v] > dist[u] + graph[u].array[edgeNum].weight && dist[u] != chiselka)
                {
                    dist[v] = (dist[u] + graph[u].array[edgeNum].weight);
                }
            }
        }
    }

    for(int phase = 0; phase < vertices - 1; phase++)
    {
        for(int vertice = 1; vertice <= vertices; vertice++)
        {
            for(int edgeNum = 0; edgeNum < graph[vertice].top; edgeNum++)
            {
                int v = graph[vertice].array[edgeNum].to;
                int u = vertice;
                if (dist[v] > dist[u] + graph[u].array[edgeNum].weight && dist[u] != chiselka)
                {
                    dist[v] = (dist[u] + graph[u].array[edgeNum].weight);
                    negative[v] = 1;
                }
                if(negative[u])negative[v] = 1;    
            }
        }
    }

    for(int step = 1; step <= vertices; step++)
    {
        if(negative[step])
        {
            printf("-\n");
        }
        else if(dist[step] == chiselka)
        {
            printf("*\n");
        }
        else
        {
            printf("%lld\n", dist[step]);
        }
    }

    for (size_t i = 0; i < vertices; i++)
    {
        if(graph[i].cap)free(graph[i].array);
    }
    free(graph);
    return 0;
}