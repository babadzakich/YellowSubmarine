#include <stdio.h>
#include <stdlib.h>

typedef struct edge
{
    int x;
    int y;
}Edge;

typedef struct vector
{
    size_t cap;
    size_t top;
    Edge* array;
    int color;
    int depth;
}Vector;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int corr(int x, int y, int X, int Y) 
{
    if (x < 0 || y < 0 || x >= X || y >= Y) return 0;
    return 1;
} 

void add_Vector(Vector * array, int x, int y)
{
    if (array->cap == 0)
    {
        array->cap = 1;
        array->array = (Edge*)malloc(sizeof(Edge));
    }
    else if(array->cap == array->top)
    {
        array->cap *= 2;
        array->array = (Edge*)realloc(array->array, sizeof(Edge) * array->cap);
    }
    array->array[array->top].x = x;
    array->array[array->top++].y = y;
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
        int b = in.top;
        in.top --;
        add_Vector(&out, in.array[b - 1].x, in.array[b - 1].y);
    }
}

Edge queue_pop()
{
    if (out.top == 0)
    {
        perebroska();
    }
    return out.array[--out.top];
}

int main(void)
{
    queue_init();
    int height = 0, width = 0;
    scanf("%d %d\n", &height, &width);
    char** matrix = (char**)malloc(sizeof(char*) * height);
    int ** matrixColor = (int**)malloc(sizeof(int*) * height);
    int sx = 0, sy = 0;
    int fx = 0, fy = 0;
    for(int step = 0; step < height; step++)
    {
        matrix[step] = (char*)malloc(width+1);
        matrixColor[step] = (int*)malloc(sizeof(int) * (width+1));
        fgets(matrix[step], width + 1, stdin);
        for(int step2 = 0; step2 < width; step2++) 
        {
            matrixColor[step][step2] = -1;
            if(matrix[step][step2] == 'S')
            {
                sx = step2;
                sy = step;
            } 
            if (matrix[step][step2] == 'F')
            {
                fx = step2;
                fy = step;
            }
        }
        getchar();
    }
    matrixColor[sy][sx] = 0;
    matrix[sy][sx] = '*';
    add_Vector(&in, sx, sy);
    while(out.top != 0 || in.top != 0)
    {
        Edge vert = queue_pop();
        for(int step = 0; step < 4; step++)
        {
            int x1 = vert.x + dx[step];
            int y1 = vert.y + dy[step];
            if(corr(x1, y1, width, height) && (matrix[y1][x1] == '.' || matrix[y1][x1] == 'F')) 
            {
                matrix[y1][x1] = '*';
                matrixColor[y1][x1] = matrixColor[vert.y][vert.x] + 1;
                add_Vector(&in, x1, y1);
            }
        }
        matrix[vert.y][vert.x] = '#';
    }
    printf("%d\n", matrixColor[fy][fx]);
    for(int step = 0; step < height; step++)
    {
        if (matrixColor[step])free(matrixColor[step]);
        if (matrix[step])free(matrix[step]);
    }
    free(matrixColor);
    free(matrix);
    free(in.array);
    free(out.array);
    return 0;
}