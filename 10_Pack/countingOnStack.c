#include <stdio.h>
#include <stdlib.h>
#define moduleRing 1000000007

typedef struct Stack_S{
    int top;
    int size;
    long long* array;
}Stack;

void push (Stack* stack, long long element)
{
    if (stack->size == 0)
    {
        stack->array = (long long*)malloc(sizeof(long long));
        stack->size = 1;
    }
    else
    {
        if (stack->top == stack->size)
        {
            stack->array = realloc(stack->array, sizeof(long long) * stack->size * 2);
            stack->size *=2;
        }
    }
    stack->array[stack->top++] = (element + moduleRing) % moduleRing;
}

void multiplication(Stack* stack)
{
    long long numberOne, numberTwo, numberThree;
    numberOne = stack->array[--stack->top];
    stack->array[stack->top] = 0;
    numberTwo = stack->array[--stack->top];
    stack->array[stack->top] = 0;
    numberThree = numberOne * numberTwo;
    push(stack, numberThree);
}

void summary(Stack* stack)
{
    long long numberOne, numberTwo, numberThree;
    numberOne = stack->array[--stack->top];
    stack->array[stack->top] = 0;
    numberTwo = stack->array[--stack->top];
    stack->array[stack->top] = 0;
    numberThree = numberOne + numberTwo;
    push(stack, numberThree);
}

void substraction(Stack* stack)
{
    long long numberOne, numberTwo, numberThree;
    numberOne = stack->array[--stack->top];
    stack->array[stack->top] = 0;
    numberTwo = stack->array[--stack->top];
    stack->array[stack->top] = 0;
    numberThree = numberTwo - numberOne;
    push(stack, numberThree);
}

int main()
{
    Stack stack;
    int amountOfOperations;
    scanf("%d", &amountOfOperations);
    stack.size = 0;
    stack.top = 0;
    for (int step = 0; step < amountOfOperations; step++)
    {
        char element[12];
        scanf("%s", element);
        if (element[0] != '*' && element[0] != '+' && element[0] != '-')
        {
            long long digitElement = atoll(element);
            push(&stack, digitElement);
        }
        else if (element[0] == '*')
        {
            multiplication(&stack);
        }
        else if (element[0] == '+')
        {
            summary(&stack);
        }
        else
        {
            substraction(&stack);
        }       
    }
    printf("%lld", stack.array[0]);
    free(stack.array);
}