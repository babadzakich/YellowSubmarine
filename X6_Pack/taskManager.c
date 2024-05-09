#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int from, to;
    int flow;
    int capacity;
}Edge;
int students, tasks, sovmestimosti;
int grapf[101][101];
int mtx[202];
int mty[202]; // с какой вершиной сматчена вершина правой доли (-1, если ни с какой)
int used[202]; // вспомогательный массив для поиска пути dfs-ом

typedef struct 
{
    size_t cap;
    size_t top;
    int* array;
}Vector;

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

int dfs(int v)
{
    if (used[v])
    {
        return 0;
    }
    used[v] = 1;
    for(int step = 1; step <= tasks; step++)
    {
        if (grapf[v][step])
        {
            if(mty[step] == -1 || dfs(mty[step]))
            {
                mtx[v] = step;
                mty[step] = v;
                return 1;
            }
        }
    }
    return 0;
}

int main(void)
{
    Stack.top = Stack.cap = 0;

    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    
    scanf("%d %d %d", &students, &tasks, &sovmestimosti);
    // Vector* graph = (Vector*)malloc(sizeof(Vector) * (students + 1));
    // for(int step = 1; step <= students; step++)
    // {
    //     graph[step].cap = graph[step].top = 0;
    // }
    
    for(int step = 0; step < sovmestimosti; step++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        // add_Vector(&graph[from], to);
        grapf[from][to] = 1;
    }

    int cnt = 0;
    memset(mty, -1, sizeof(mty));
    memset(mtx, -1, sizeof(mtx));

    for (int step = 1; step <= students; step++) 
    {
        memset(used, 0, sizeof(used));
        if (dfs(step))
        {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    for(int step = 1; step <= students; step++)
    {
        if (mtx[step] != -1)
        {
            printf("%d %d\n", step, mtx[step]);
        }
    }
    for(int step = 0; step <= students; step++)
    {
        // if(!graph[step].cap)free(graph[step].array);
    }
    return 0;
}