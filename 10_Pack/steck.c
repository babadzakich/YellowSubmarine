#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define maximum 1000000
#define minimum -1000000

typedef struct Stack{
    int top;
    int capacity;
    int max;
    int min;
    int* array;
}stack_s;

void push (stack_s* stack)
{
    if(stack->capacity == 0) // if stack is empty
    {
        stack->array = (int*)malloc(sizeof(int));
        stack->capacity++;
    }
    else if(stack->top == stack->capacity) // if stack`s capacity is full we realloc it
    {
        stack->array = realloc(stack->array, sizeof(int) * stack->capacity * 2);
        stack->capacity *= 2;
    }
    scanf("%d", &stack->array[stack->top]);//if stack`s capacity is not full, we add number to it, changing min and max, and increasing top value
    stack->min = stack->array[stack->top] < stack->min ? stack->array[stack->top] : stack->min;
    stack->max = stack->array[stack->top] > stack->max ? stack->array[stack->top] : stack->max;
    stack->top++;
}

void pop (stack_s* stack)
{
    printf("%d\n", stack->array[stack->top - 1]);//we print the value
    if(stack->top == 1)//if we delete the last element in stack we free it reseting it`s values
    {
        free(stack->array);
        stack->capacity = 0;
        stack->top --;
        stack->min = maximum;
        stack->max = minimum;
    }
    else
    {
        if (stack->array[stack->top - 1] == stack->min)//if we delete minimum we must recalculate  the minimum of stack
        {
            stack->min = maximum;
            for(int step = 0; step < stack->top-1; step++)
            {
                stack->min = stack->array[step] < stack->min ? stack->array[step] : stack->min;
            }
        }
        if (stack->array[stack->top-1] == stack->max)// if we delete maximum we recalculate it
        {
            stack->max = minimum;
            for(int step = 0; step < (stack->top-1); step++)
            {
                stack->max = stack->array[step] > stack->max ? stack->array[step] : stack->max;
            }
        }
        stack->array[--(stack->top)] = 0;
    }
}

int main()
{
    int amountOfOperations;
    scanf("%d", &amountOfOperations);
    stack_s stack;
    stack.capacity = stack.top = 0;
    stack.max = minimum;
    stack.min = maximum;
    for(int step = 0; step < amountOfOperations; step++)
    {
        char operation[5];
        scanf("%s", operation);
        if (strcmp(operation,"push") == 0)
        {
            push(&stack);
        }
        else if(strcmp(operation, "pop") == 0)
        {
            pop(&stack);
        }
        else if(strcmp(operation, "min")==0)
        {
            printf("%d\n", stack.min);
        }
        else
        {
            printf("%d\n", stack.max);
        }
    }
    free(stack.array);
    return 0;
}