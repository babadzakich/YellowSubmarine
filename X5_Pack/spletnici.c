#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

typedef enum Mark{WHITE = 0, GRAY = 1, BLACK = 2}Mark;

typedef struct vector
{
    int cap;
    int top;
    int* to;
    long long* weight;
    Mark mark;
}Vector;

typedef struct edge
{
    int from, to;
}Edge;

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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    Stack.cap = 0;
    Stack.top = 0;

    int vertices, edges, calls;
    scanf("%d %d %d", &vertices, &edges, &calls);
    Vector* graph0 = (Vector*)malloc(sizeof(Vector) * (vertices));
    Vector* graph = graph0 - 1;
    for(int step = 0; step < vertices; step++)
    {
        graph0[step].cap = 0;
        graph0[step].top = 0;
    }
    Edge* tests = (Edge*)malloc(sizeof(Edge) * calls);
    for(int step = 0; step < calls; step++)
    {
        scanf("%d %d", &tests[step].from, &tests[step].to);
    }

    for(int step = 0; step < edges; step++)
    {
        int from, to; 
        long long weight;
        scanf("%d %d %lld", &from, &to, &weight);
        add_Vector(&graph[from], to, weight);
        add_Vector(&graph[to], from, weight);
    }

    int* marks0 = (int*)malloc(sizeof(int) * vertices);
    int* marks = marks0 - 1;
    long long* dist0 = (long long*)malloc(sizeof(long long) * vertices);
    long long* dist = dist0 - 1;
    int* predecessor0 = (int*)malloc(sizeof(int) * vertices);
    int* predecessor = predecessor0 - 1; 
    
    for (int test = 0; test < calls; test++)
    {
        int from = tests[test].from, to = tests[test].to;
        for(int step = 0; step < vertices; step++)
        {
            marks0[step] = WHITE;
            dist0[step] = 6000000000;
            predecessor0[step] = 0;
        }
        dist[from] = 0;
        marks[from] = 1;
        int grayFlag = 1;

        while(1)
        {
            int u = 0;
            for(int step = 1; step <= vertices; step++)
            {
                if (marks[step] == 1 && ( u == 0 || dist[step] < dist[u]))
                {
                    u = step;
                }
            }
            if (u == 0)
            {
                break;
            }
            marks[u] = 2;
            for(int step = 0; step < graph[u].top; step++)
            {
                int v = graph[u].to[step];
                if(dist[v] > dist[u] + graph[u].weight[step])
                {
                    dist[v] = dist[u] + graph[u].weight[step];
                    marks[v] = 1;
                    predecessor[v] = u;
                }
            }
        }  
        // for(int vert = 1; vert <= vertices; vert++)
        // {
        //     printf("%d ", predecessor[vert]);
        // } 
        // printf("\n");
        if (marks[to] != 0)
        {
            int temp = to;
            while (temp != from)
            {
                add_Vector(&Stack, temp, 0);
                temp = predecessor[temp];
            }
            add_Vector(&Stack, temp, 0);
            printf("YES  %lld %d  ", dist[to], Stack.top);
            while (Stack.top > 0)
            {
                printf("%d ", Stack.to[--Stack.top]);
            }
            printf("\n");
        }
        else
        {
            printf("NO\n");
        }
        
    }
    free(marks0);
    free(dist0);
    free(predecessor0);
    for (int i = 0; i < vertices; i++)
    {
        if(graph0[i].cap > 0)
        {
            free(graph0[i].to);
            free(graph0[i].weight);
        }
    }
    free(graph0);
    free(Stack.to);
    free(Stack.weight);
    return 0;
}