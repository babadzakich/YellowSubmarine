#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define maximum 1000000
#define minimum -1000000

typedef struct Stack{
    int top;
    int capacity;
    struct StackElement* array;
}stack_s;

struct StackElement {
    int value; 
    int min;
    int max; 
};

void push (stack_s* stack)
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
    scanf("%d", &stack->array[stack->top].value);//if stack`s capacity is not full, we add number to it, changing min and max, and increasing top value
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

void pop (stack_s* stack)
{
    printf("%d\n", stack->array[--stack->top].value);//we print the value
}

int main()
{
    int amountOfOperations;
    scanf("%d", &amountOfOperations);
    stack_s stack;
    stack.capacity = stack.top = 0;
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
            printf("%d\n", stack.array[stack.top-1].min);
        }
        else
        {
            printf("%d\n", stack.array[stack.top-1].max);
        }
    }
    free(stack.array);
    return 0;
}