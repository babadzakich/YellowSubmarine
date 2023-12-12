#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Stack_s{
    int top;
    int capacity;
    struct StackElement* array;
}Stack;

struct StackElement {
    int value; 
    int min;
    int max; 
};

void enqueue (Stack* stack, int number)
{
    if(stack->capacity == 0) // if stack is empty
    {
        stack->array = (struct StackElement*)malloc(sizeof(struct StackElement));
        stack->capacity++;
    }
    else if(stack->top == stack->capacity) // if stack`s capacity is full we realloc it
    {
        stack->array = realloc(stack->array, sizeof(struct StackElement) * stack->capacity * 2);
        stack->capacity *= 2;
    }
    stack->array[stack->top].value = number;//if stack`s capacity is not full, we add number to it, changing min and max, and increasing top value
    if (stack->top == 0)
    {
        stack->array[stack->top].min = stack->array[stack->top].max = stack->array[stack->top].value; 
    }
    else
    {
        if (stack->array[stack->top-1].min > stack->array[stack->top].value)
        {
            stack->array[stack->top].min = stack->array[stack->top].value;
        }
        else
        {
            stack->array[stack->top].min = stack->array[stack->top - 1].min;
        }
        if (stack->array[stack->top-1].max < stack->array[stack->top].value)
        {
            stack->array[stack->top].max = stack->array[stack->top].value;
        }
        else
        {
            stack->array[stack->top].max = stack->array[stack->top-1].max;
        }
    }
    stack->top ++;
    
}

void stackCopy(Stack* departure, Stack* destination)
{
    while(departure->top != 0)
    {
        enqueue(destination, (departure->array[--departure->top].value));

    }
}

void dequeue (Stack* in, Stack* out)
{
    if(out->top == 0)
    {
        stackCopy(in, out);
    }
    printf("%d\n", out->array[--out->top].value);//we print the value
    
}

int max(Stack* in, Stack* out)
{
    if (in->top == 0)
    {
        return (out->array[out->top-1].max);
    }
    else if(out->top == 0)
    {
        return (in->array[in->top-1].max);
    }
    else
    {
        return (in->array[in->top-1].max > out->array[out->top-1].max ? in->array[in->top-1].max : out->array[out->top-1].max);
    }
}

int min(Stack* in, Stack* out)
{
    if (in->top == 0)
    {
        return out->array[out->top-1].min;
    }
    else if(out->top == 0)
    {
        return in->array[in->top-1].min;
    }
    else
    {
        return in->array[in->top-1].min < out->array[out->top-1].min ? in->array[in->top-1].min : out->array[out->top-1].min;
    }
}

int main()
{
    int amountOfOperations;
    scanf("%d", &amountOfOperations);
    Stack in, out;
    in.capacity = in.top = out.capacity = out.top = 0;
    for(int step = 0; step < amountOfOperations; step++)
    {
        char operation[8];
        scanf("%s", operation);
        if(strncmp(operation, "enqueue", 7) == 0)
        {
            int number;
            scanf("%d", &number);
            enqueue(&in, number);
        }
        else if(strncmp(operation, "dequeue", 7) == 0)
        {
            dequeue(&in, &out);
        }
        else if(strncmp(operation, "max", 3) == 0)
        {
            //int max = in.array[in.top-1].max > out.array[out.top-1].max ? in.array[in.top-1].max : out.array[out.top-1].max; 
            printf("%d\n", max(&in, &out));
        }
        else if (strncmp(operation, "min", 3) == 0)
        {
            //int min = in.array[in.top-1].min < out.array[out.top-1].min ? in.array[in.top-1].min : out.array[out.top-1].min; 
            printf("%d\n", min(&in, &out));
        }
    }
    
    return 0;
}