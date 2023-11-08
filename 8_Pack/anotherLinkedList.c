#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#define beforeOperation -1
#define afterOperation 1
#define delition 0

typedef struct Node {
struct Node * prev , * next ;
double value ;
} Node ;

//создаёт пустой список
//возвращает указатель на value в голове списка (вспом. узел)
double * initList ()
{
    Node* header = (Node*)malloc(sizeof(Node));
    header->next = header;
    header->prev = header;
    return &header->value;
}
//полностью освобождает память списка
//принимает указатель на value голове списка (вспом. узел)
void freeList ( double * head )
{
    Node* start = (Node*)((void*)head - offsetof(Node, value));
    Node* step = start->next;
    while (step != start)
    {
        Node *temp = step->next;
        free(step);
        step = temp;
    }
    free(start);
    
}
//определяет следующий элемент после заданного
//(для вспом. узла возвращает первый элемент)
double * getNext ( double * curr )
{
    Node* currentNode = (Node*)((void*)curr - offsetof(Node, value));
    currentNode = currentNode->next;
    return &currentNode->value;
}
//определяет предыдущий элемент перед заданным
//(для вспом. узла возвращает последний элемент)
double * getPrev ( double * curr )
{
    Node* currentNode = (Node*)((void*)curr - offsetof(Node, value));
    currentNode = currentNode->prev;
    return &currentNode->value;
}
//создаёт и вставляет узел со значением newval сразу после узла where
double * addAfter ( double * where , double newval )
{
    Node *currentNode = (Node*)((void*)where - offsetof(Node,value));
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = newval;
    newNode->next = currentNode->next;
    newNode->prev = currentNode;
    currentNode->next->prev = newNode;
    currentNode->next = newNode;
    return &newNode->value;
}
//создаёт и вставляет узел со значением newval сразу перед узлом where
double * addBefore ( double * where , double newval )
{
    Node *currentNode = (Node*)((void*)where - offsetof(Node,value));
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = newval;
    newNode->prev = currentNode->prev;
    newNode->next = currentNode;
    currentNode->prev->next = newNode;
    currentNode->prev = newNode;
    return &newNode->value;
}
//удаляет и освобождает заданный узел
void erase ( double * what )
{
    Node *currentNode = (Node*)((void*)what - offsetof(Node,value));
    currentNode->next->prev = currentNode->prev;
    currentNode->prev->next = currentNode->next;
    double* value = &currentNode->value;
    free(currentNode);
}

double* array0[100002];
double** array = array0 + 1;

int main()
{
    int amountOfTests;
    scanf("%d", &amountOfTests);
    for(int test = 1; test <= amountOfTests; test++)
    {
        int amountOfOperations,amountOfNodes=0;
        scanf("%d", &amountOfOperations);
        array[-1] = initList();
        for (int step = 0; step < amountOfOperations; step++)
        {
            int typeOfOperation;
            scanf("%d", &typeOfOperation);
            if (typeOfOperation == beforeOperation)
            {
                int nodePosition;
                double newValue;
                scanf("%d %lf", &nodePosition, &newValue);
                array[amountOfNodes++] = addBefore(array[nodePosition], newValue);
            }
            if (typeOfOperation == afterOperation)
            {
                int nodePosition;
                double newValue;
                scanf("%d %lf", &nodePosition, &newValue);
                array[amountOfNodes++] = addBefore(array[nodePosition], newValue);
            }
            if (typeOfOperation == delition)
            {
                int nodePosition;
                scanf("%d", &nodePosition);
                erase(array[nodePosition]);
                printf("%0.3lf\n",*array[nodePosition] );
            }
            
        }
        printf("===\n");
        for(double* step = getNext(array[-1]); getNext(step)!= array[-1]; step = getNext(step))
        {
            printf("%0.3lf\n", *step);
        }
    }
    return 0;
}