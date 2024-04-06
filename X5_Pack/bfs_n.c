#include <stdio.h>
#include <stdlib.h>

typedef struct vector
{
    size_t cap;
    size_t top;
    int* array;
    int color;
    int depth;
}Vector;

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

int stack_pop(Vector* out)
{
    if (out->top != 0)
    {
        return out->array[--out->top];
    }
}

Vector in;
Vector out;

void queue_init()
{
    in.cap = 0;
    in.top = 0;
    out.cap = 0;
    out.top = 0;
}

void perebroska()
{
    while(in.top != 0)
    {
        add_Vector(&out, in.array[--in.top]);
    }
}

int queue_pop()
{
    if (out.top == 0)
    {
        perebroska();
    }
    return out.array[--out.top];
}



int main(void)
{
    int vertices, edges;
    scanf("%d %d", &vertices, &edges);
    queue_init();
    Vector* vectorr = (Vector*)malloc(sizeof(Vector) * vertices);
    Vector* vector = vectorr - 1;
    for(int step = 0; step < vertices; step++)
    {
        vectorr[step].cap = 0;
        vectorr[step].top = 0;
        vectorr[step].color = 0;
        vectorr[step].depth = -1;
    }
    for(int step = 0; step < edges; step++)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        add_Vector(&vector[v1], v2);
    }

    vector[1].color = 1;
    vector[1].depth = 0;
    add_Vector(&in, 1);
    while(out.top != 0 || in.top != 0)
    {
        int vert = queue_pop();
        for(int step = 0; step < vector[vert].top; step++)
        {
            int vert2 = vector[vert].array[step];
            if(vector[vert2].color == 0)
            {
                vector[vert2].color = 1;
                vector[vert2].depth = vector[vert].depth + 1;
                add_Vector(&in, vert2);
            }
        }
        vector[vert].color = 2;
    }
    for(int step = 0; step < vertices; step++)
    {
        printf("%d\n", vectorr[step].depth);
        if(vectorr[step].cap > 0) free(vectorr[step].array);
    }
    free(in.array);
    free(out.array);
    free(vectorr);
    return 0;
}