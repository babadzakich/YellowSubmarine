#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

long long* dist;

struct pair{
    int to;
    long long weight;
    int pos;
};

typedef struct 
{
    int to;
    int pos;
}Edger;

typedef struct vector
{
    int cap;
    int top;
    struct pair* array;
    char mark;
}Vector;

typedef struct
{
    int from, to;
}Edge;

int heap2vert[100001];//heap2vert[k] --- номер вершины, расположенной на позиции k в куче
int vert2heap[100001];
int heap[100010];
int topHeap = 0;
Vector Stack;

void swap(int* num1, int*num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void add_Vector(Vector * array, int to, long long weight, int number)
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
    array->array[array->top].to = to;
    array->array[array->top].weight = weight;
    array->array[array->top].pos = number;
    array->top++;
}

void siftDown(int i)
{
    while (2 * i + 1 < topHeap)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int j = left;
        if(right < topHeap && dist[heap[right]] < dist[heap[left]])
        {
            j = right;
        }
        if(dist[heap[i]] <= dist[heap[j]]) break;
        swap(&vert2heap[heap[i]], &vert2heap[heap[j]]);
        // swap(&heap2vert[i], &heap2vert[j]);
        swap(&heap[i], &heap[j]);
        i = j;
    }
}

void siftUp(int i)
{
    while(dist[heap[i]] < dist[heap[(i - 1) / 2]])
    {
        swap(&vert2heap[heap[i]], &vert2heap[heap[(i - 1) / 2]]);
        // swap(&heap2vert[i], &heap2vert[(i - 1) / 2]);
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin()
{
    // vert2heap[heap[0]] = -1;
    int min = heap[0];
    heap[0] = heap[topHeap - 1];
    // heap2vert[0] = heap[0];
    vert2heap[heap[0]] = 0;
    topHeap--;
    siftDown(0);
    return min;
}

void insert(int key)
{
    heap[topHeap++] = key;
    vert2heap[key] = topHeap - 1;
    // heap2vert[topHeap - 1] = key;
    siftUp(topHeap - 1);
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
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
    int num = 1;
    for(int step = 0; step < edges; step++)
    {
        int from, to; 
        long long weight;
        scanf("%d %d %lld", &from, &to, &weight);
        add_Vector(&graph[from], to, weight, num);
        num++;
    }

    int* marks0 = (int*)malloc(sizeof(int) * vertices);
    int* marks = marks0 - 1;
    dist = (long long*)malloc(sizeof(long long) * (vertices + 1));
    Edger* predecessor0 = (Edger*)malloc(sizeof(Edger) * vertices);
    Edger* predecessor = predecessor0 - 1; 
    
    for (int test = 0; test < calls; test++)
    {
        int from = tests[test].from, to = tests[test].to;
        for(int step = 0; step < vertices; step++)
        {
            marks0[step] = 0;
            dist[step+1] = 60000000000;
            predecessor0[step].pos = 0;
            predecessor0[step].to = 0;
        }
        dist[from] = 0;
        insert(from);
        for(int step = 1; step <= vertices; step++)
        {
            if (step == from)continue;
            insert(step);
        }

        while(topHeap != 0)
        {
            int u = extractMin();
            marks[u] = 2;
            for(int step = 0; step < graph[u].top; step++)
            {
                int v = graph[u].array[step].to;
                if(dist[v] > dist[u] + graph[u].array[step].weight)
                {
                    dist[v] = dist[u] + graph[u].array[step].weight;
                    predecessor[v].to = u;
                    predecessor[v].pos = graph[u].array[step].pos;
                    int check = vert2heap[v];
                    siftUp(vert2heap[v]);
                }
            }
        }

        if (predecessor[to].to != 0)
        {
            int temp = to;
            while (temp != from)
            {
                add_Vector(&Stack, predecessor[temp].pos, 0, 0);
                temp = predecessor[temp].to;
            }
            add_Vector(&Stack, temp, 0, 0);
            printf("quarantine  %lld %d  ", dist[to], Stack.top - 1);
            for(int step = Stack.top - 2; step >= 0; step--)
            {
                printf("%d ", Stack.array[step].to);
            }
            Stack.top = 0;
            printf("\n");
        }
        else
        {
            printf("DOOMED\n");
        }
        
    }
    free(marks0);
    free(dist);
    free(predecessor0);
    for (int i = 0; i < vertices; i++)
    {
        if(graph0[i].cap > 0)
        {
            free(graph0[i].array);
        }
    }
    free(graph0);
    free(Stack.array);
    return 0;
}