#include <stdio.h>
#include <stdlib.h>
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

typedef struct vector
{
    int cap;
    int top;
    int* array;
}Vector;
Vector Stack;
typedef struct backpack
{
    int weight;
    int cost;
    int pos;
}Backpack;

Backpack* plecak;
int items, max_weight;
int ** k;
int stoimoost = 0;

int compar(const void* arg1, const void* arg2)
{
    if (((Backpack*)arg1)->weight < ((Backpack*)arg2)->weight)
    {
        return 1;
    }
    else if (((Backpack*)arg1)->weight > ((Backpack*)arg2)->weight)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

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

int knapsack()
{
    for(int step = 0; step <= max_weight; step++)
    {
        k[0][step] = 0;
    }
    for(int step = 0; step <= items; step++)
    {
        k[step][0] = 0;
    }
    for(int step = 1; step <= items; step++)
    {
        for(int step2 = 1; step2 <= max_weight; step2++)
        {
            if(step2 >= plecak[step - 1].weight)
            {
                k[step][step2] = max(k[step - 1][step2], k[step-1][step2 - plecak[step - 1].weight] + plecak[step - 1].cost);
            }
            else
            {
                k[step][step2] = k[step-1][step2];
            }
        }
    }
    return k[items][max_weight];
}

void path(int a, int s)
{
    if (k[a][s] == 0) return;
    if (k[a - 1][s] == k[a][s])
    {
        path(a-1, s);
    }
    else
    {
        path(a - 1, s - plecak[a - 1].weight);
        add_Vector(&Stack, plecak[a-1].pos);
        stoimoost += plecak[a-1].weight;
    }
}
int main(void)
{
    Stack.cap = Stack.top = 0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &items, &max_weight);
    plecak = (Backpack*)calloc(items, sizeof(Backpack));
    
    for(int step = 0; step < items; step++)
    {
        plecak[step].pos = step + 1;
        scanf("%d %d", &plecak[step].weight, &plecak[step].cost);
    }   
    // qsort(plecak, items, sizeof(Backpack), compar);
    k = (int**)calloc(items + 1, sizeof(int*));
    for(int step = 0; step <= items; step++)
    {
        k[step] = (int*)calloc(max_weight + 1, sizeof(int));
    }
    int weight = knapsack();
    path(items, max_weight);
    printf("%d %d %d\n", Stack.top, stoimoost, weight);
   
    for(int step = 0; step < Stack.top; step++)
    {
        printf("%d ", Stack.array[step]);
    }
    for(int step = 0; step <= items; step++)
    {
        free(k[step]);
    }
    free(k);
    free(Stack.array);
    free(plecak);
    return 0;
}