#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s{
    int value;
    struct Node_s *next;
}Node;

// union callbackFunc
// {
//     void *ptr;
//     int number;
// };


Node* insertion(Node* node, int value)
{
    Node* new = (Node*)malloc(sizeof(Node));
    new->next = node->next;
    node->next = new;
    new->value = value;
    return new;
}

void* summa(void* summa, int* value)
{
    if (*value % 2 == 0)
    {
        *((int*)summa) += *value; 
    }
}
//тип указателя на функцию, которую можно передавать как callback
typedef void (* callback )( void * ctx , int * value );
//здесь ctx –- это контекст, который передаётся в func первым аргументом
//последние два параметра задают массив, по элементам которого нужно пройтись
void arrayForeach ( void * ctx , callback func , int * arr , int n )
{
    for(int step = 0; step < n; step++)
    {
        func(ctx, &arr[step]);
    }
    printf("%d ", *(int*)ctx);
}

void linkedListForEach(void * ctx , callback func , Node* head)
{
    Node* step = head->next;
    while (step != head)
    {
        func(ctx, &step->value);
        Node* temp = step->next;
        free(step);
        step = temp;
    }
    printf("%d",*(int*)ctx);
    
}

int main()
{
    int amountOfNumbers;
    callback summaryF = summa;
    scanf("%d", &amountOfNumbers);
    int* array = (int*)malloc(sizeof(int)*amountOfNumbers);
    for (int step = 0; step < amountOfNumbers; step++)
    {
        scanf("%d", &array[step]);
    }
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = head;
    Node* temp = head;
    for (int step = 0; step < amountOfNumbers; step++)
    {
        temp = insertion(temp, array[step]);
    }
    void *counter = malloc(sizeof(int));
    *((int*)counter) = 0;
    arrayForeach(counter, summaryF, array, amountOfNumbers);
    *((int*)counter) = 0;
    linkedListForEach(counter, summaryF, head);
    free(array);
    free(head);
    free(counter);
    return 0;

}