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
Edge Edges[100002];
typedef struct 
{
    size_t cap;
    size_t top;
    int* array;
}Vector;

Vector in, out;
Vector Stack;

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
 
    in.cap = in.top = out.cap = out.top = Stack.top = Stack.cap = 0;
    
    int vertice, edgess;
    scanf("%d %d", &vertice, &edgess);
    int s, t;
    scanf("%d %d", &s, &t);
    int edgesCount = 0;
    
    Vector* graph = (Vector*)calloc(vertice+2, sizeof(Vector));
    for(int step = 0; step <= vertice + 1; step++)
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
    int cnt = 0;
    while (1)
    {
        for(int step = 0; step <= vertice; step++)
        {
            mark[step] = 0;
            F[step] = 0;
        }
        mark[s] = 1;
        F[s] = 0;
        add_Vector(&in, s);
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
        if (!mark[t]) break;

        int CP = 2000001;
        int xui = 0;
        int x = t;
        while (x != s)
        {
            int y = F[x];
            int b = Edges[y].capacity - Edges[y].flow;
            CP = MIN(CP, b);
            x = Edges[y].from;
        }

        x = t;
        while (x != s)
        {
            int y = F[x];
            Edges[y].flow += CP;
            Edges[y^1].flow -= CP;
            x = Edges[y].from;
        }
        max_flow += CP;
    }
    for(int step = 1; step <= vertice; step++)
    {
        for(int step2 = 0; step2 < graph[step].top; step2++)
        {
            int edg = graph[step].array[step2];
            if(mark[Edges[edg].from] && !mark[Edges[edg].to])
            {
                cnt++;
            }
        }
    }
    printf("%lld %d\n", max_flow, cnt);
    for(int step = 1; step <= vertice; step++)
    {
        for(int step2 = 0; step2 < graph[step].top; step2++)
        {
            int edg = graph[step].array[step2];
            if(mark[Edges[edg].from] && !mark[Edges[edg].to])
            {
                printf("%d %d\n", Edges[edg].from, Edges[edg].to);
            }
        }
    }
    return 0;
}