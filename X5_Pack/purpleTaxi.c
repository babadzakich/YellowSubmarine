#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

typedef struct vector
{
    size_t cap;
    size_t top;
    int* to;
    char color;
}Vector;

int flag = 0;
int flag2 =0;
int cycle = 0;

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

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int vertices, edges, minLengthAsk, minTimeAsk;
    scanf("%d %d %d %d", &vertices, &edges, &minLengthAsk, &minTimeAsk);
    Vector stack;
    stack.cap = stack.top = 0;
    int** matrix = (int**)malloc(sizeof(int*) * (vertices));
    int** next = (int**)malloc(sizeof(int*) * (vertices));
    for(int step = 0; step < vertices; step++)
    {
        matrix[step] = (int*)malloc(vertices * sizeof(int));
        next[step] = (int*)malloc(vertices * sizeof(int));
        for(int step2 = 0; step2 < vertices; step2++)
        {
            matrix[step][step2] = 1000001;
            next[step][step2] = vertices;
        }
    }

    for(int step = 0; step < edges; step++)
    {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        matrix[from - 1][to - 1] = MIN(weight, matrix[from - 1][to - 1]);
        matrix[to - 1][from - 1] = MIN(weight, matrix[to - 1][from - 1]);
        next[from - 1][to - 1] = to - 1;
        next[to - 1][from - 1] = from - 1;
    }

    for(int k = 0; k < vertices; k++)
    {
        for(int i = 0; i < vertices; i++)
        {
            for(int j = 0; j < vertices; j++)
            {
                if (matrix[i][j] > matrix[i][k] + matrix[k][j])
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    for(int step = 0; step < minLengthAsk; step++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        int c = from - 1;
        while (c != to -1)
        {
            add_Vector(&stack, c+1);
            c = next[c][to-1];
        }
        add_Vector(&stack, to);
        printf("%d  %d  ", matrix[from-1][to-1], stack.top);
        for(int step2 = 0; step2 < stack.top; step2++)
        {
            printf("%d ", stack.to[step2]);
        }
        stack.top = 0;
        printf("\n");
    }

    for(int step = 0; step < minTimeAsk; step++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        printf("%d\n", matrix[from-1][to-1]);
    }
    free(stack.to);
    for(int step = 0; step < vertices; step++)
    {
        free(matrix[step]);
        free(next[step]);
    }
    free(matrix);
    free(next);
    return 0;
}