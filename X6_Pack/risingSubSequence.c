#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF __INT32_MAX__
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

typedef struct 
{
    int number;
    int index;
}Container;

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

int binarySearch(Container* array, int right, int key)
{
    int left = 0;
    while (left < right) 
    {
        int mid = (left + right) / 2;

        if (array[mid].number < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return left;
}

int main(void)
{
    Stack.top = Stack.cap = 0;

    freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
 
    int size;
    scanf("%d", &size);
    int* array = (int*)malloc(sizeof(int) * size);
    for(int step = 0; step < size; step++)
    {
        scanf("%d", &array[step]);
    }
    
    Container* sequence = (Container*)malloc(sizeof(Container) * size);
    int* previous = (int*)malloc(sizeof(int) * (size));
    int length = 1;
    for(int step = 1; step < size; step++)
    {
        sequence[step].number = INF;
    }

    sequence[0].number = array[0];
    sequence[0].index = 0;
    previous[0] = -1;
    for(int step = 1; step < size; step++)
    {
        if (array[step] > sequence[length - 1].number)
        {
            previous[step] = sequence[length - 1].index;
            sequence[length].number = array[step];
            sequence[length].index = step;
            length++;
        }
        else
        {
            int index = binarySearch(sequence, size-1, array[step]);
            if (!index)
            {
                previous[step] = -1;
            }
            else
            {
                previous[step] = sequence[index - 1].index;
            }
            sequence[index].number = array[step];
            sequence[index].index = step;
            
        }
    }

    printf("%d\n", length);
    int temp = sequence[length - 1].index;
    while(temp != -1)
    {
        add_Vector(&Stack, temp);
        temp = previous[temp];
    }

    while(Stack.top > 0)
    {
        int index = Stack.array[--Stack.top];
        printf("A[%d] = %d\n", index + 1, array[index]);
    }
    
    free(sequence);
    free(previous);
    free(array);
    if (Stack.cap > 0)free(Stack.array);
    return 0;
}
