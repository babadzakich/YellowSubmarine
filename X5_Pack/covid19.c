#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

typedef struct vector
{
    size_t cap;
    size_t top;
    int* to;
    long long* weight;
    char color;
}Vector;

Vector Stack;

void add_Vector(Vector * array, int to, long long weight)
{
    if (array->cap == 0)
    {
        array->cap = 1;
        array->to = (int*)malloc(sizeof(int));
        array->weight = (long long*)malloc(sizeof(long long));
    }
    else if(array->cap == array->top)
    {
        array->cap *= 2;
        array->to = (int*)realloc(array->to, sizeof(int) * array->cap);
        array->weight = (long long*)realloc(array->weight, sizeof(long long) * array->cap);
    }
    array->weight[array->top] = weight;
    array->to[array->top] = to;
    array->top++;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    Stack.cap = Stack.top = 0;

    int vertices, edges, friends;
    scanf("%d %d %d", &vertices, &edges, &friends);
    Vector* graph0 = (Vector*)malloc(sizeof(Vector) * (vertices + 1));
    Vector* graph = graph0 - 1;
    for(int step = 0; step < vertices; step++)
    {
        graph0[step].cap = graph0[step].top = 0;
    }

    int* houses = (int*)malloc(sizeof(int) * (friends + 1));
    for(int step = 0; step < friends; step++)
    {
        scanf("%d", &houses[step]);
    }

    for(int step = 0; step < edges; step++)
    {
        int from, to; 
        long long weight;
        scanf("%d %d %lld", &from, &to, &weight);
        add_Vector(&graph[from], to, weight);
    }
    
    long long* dist0 = (long long*)malloc(sizeof(long long) * (vertices + 1));
    long long* dist = dist0 - 1;

    int* path0 = (int*)malloc(sizeof(int) * (vertices + 1));
    int* path = path0 - 1;
    
    dist[1] = 0;
    
    for(int step2 = 2; step2 <= vertices; step2++)
    {
        dist[step2] = 6000000000;
    }
    
    for(int phase = 0; phase < vertices - 1; phase++)
    {
        for(int vertice = 1; vertice <= vertices; vertice++)
        {
            for(int edgeNum = 0; edgeNum < graph[vertice].top; edgeNum++)
            {
                int v = graph[vertice].to[edgeNum];
                int u = vertice;
                if (dist[v] > dist[u] + graph[u].weight[edgeNum])
                {
                    dist[v] = dist[u] + graph[u].weight[edgeNum];
                    path[v] = u;
                }
            }
        }
    }   
    for(int step = 0; step < friends; step++)
    {
        int home = houses[step];
        while(home != 1)
        {
            add_Vector(&Stack, home, 0);
            home = path[home];
        }
        add_Vector(&Stack, 1, 0);
        printf("%lld  %d  ", dist[houses[step]], Stack.top);
        while(Stack.top > 0)
        {
            printf("%d ", Stack.to[--Stack.top]);
        }
        printf("\n");
    }
    free(dist0);
    free(path0);
    for (size_t i = 0; i < vertices; i++)
    {
        if(graph0[i].to)free(graph0[i].to);
        if(graph0[i].weight)free(graph0[i].weight);
    }
    free(graph0);
    free(houses);
    free(Stack.to);
    free(Stack.weight);
    return 0;
}