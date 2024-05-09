#include <stdio.h>
#include <stdlib.h>
#define MIN(X, Y) ((X) > (Y) ? (Y) : (X))


int mark[100002];
int F[100002];

typedef struct 
{
    int from, to;
    int flow;
    int capacity;
}Edge;
Edge Edges[10002];
typedef struct 
{
    size_t cap;
    size_t top;
    int* array;
}Vector;

Vector in, out;

void add_Vector(Vector * array, int to)
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
    array->array[array->top++] = to;
}

void perebroska()
{
    while(in.top > 0)
    {
        add_Vector(&out, in.array[--in.top]);
    }
}

int dequeue()
{
    if (out.top == 0)
    {
        perebroska();
    }
    return out.array[--out.top];
}

int main(void)
{
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
 
    in.cap = in.top = out.cap = out.top = 0;
    
    int vertice, edgess;
    scanf("%d %d", &vertice, &edgess);
    
    int edgesCount = 0;
    
    Vector* graph = (Vector*)calloc(vertice+2, sizeof(Vector));
    for(int step = 0; step <= vertice; step++)
    {
        graph[step].cap = graph[step].top = 0;
    }

    for(int step = 0; step < edgess; step++)
    {
        int from, to, flow;
        scanf("%d %d %d", &from, &to, &flow);
        Edges[edgesCount].from = from;
        Edges[edgesCount].to = to;
        Edges[edgesCount].flow = 0;
        Edges[edgesCount].capacity = flow;
        add_Vector(&graph[from], edgesCount);
        edgesCount++;
        Edges[edgesCount].from = to;
        Edges[edgesCount].to = from;
        Edges[edgesCount].flow = 0;
        Edges[edgesCount].capacity = flow;
        add_Vector(&graph[to], edgesCount);
        edgesCount++;
    }

    long long max_flow = 0;
    
    while (1)
    {
        for(int step = 0; step <= vertice; step++)
        {
            mark[step] = 0;
            F[step] = 0;
        }
        mark[1] = 1;
        F[1] = 0;
        add_Vector(&in, 1);
        while (out.top > 0 || in.top > 0)
        {
            int u = dequeue();
            for(int step = 0; step < graph[u].top; step++)
            {
                int edge = graph[u].array[step];
                int v = Edges[edge].to;
                if (Edges[edge].capacity - Edges[edge].flow > 0)
                {
                    if (!mark[v])
                    {
                        mark[v] = 1;
                        add_Vector(&in, v);
                        F[v] = edge;
                    }
                }
            }
        }
        if (!mark[vertice]) break;

        int CP = 2000001;
        int x = vertice;
        while (x != 1)
        {
            int y = F[x];
            CP = MIN(CP, Edges[y].capacity - Edges[y].flow);
            x = Edges[y].from;
        }

        x = vertice;
        while (x != 1)
        {
            int y = F[x];
            Edges[y].flow += CP;
            Edges[y^1].flow -= CP;
            
            
            x = Edges[y].from;
        }
        max_flow += CP;
    }
    printf("%lld\n", max_flow);
    for(int step = 0; step <= vertice + 1; step++) if (graph[step].cap) free(graph[step].array);
    free(graph);
    return 0;
}