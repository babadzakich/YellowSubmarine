#include <stdio.h>
#include <stdlib.h>

const int addBehind = -1, addAfter = 1, deletion = 0;

typedef struct Node{
    int value;
    int next;
    int previous;
}Node;

void deletionF(Node *array)
{
    int deleteIndex;
    scanf("%d", &deleteIndex);
    array[array[deleteIndex].previous].next = array[deleteIndex].next;
    array[array[deleteIndex].next].previous = array[deleteIndex].previous;
    printf("%d\n",array[deleteIndex].value);
}

void addAfterF(Node *array, int *newIndex)
{
    int addIndex, newValue;
    scanf("%d %d", &addIndex, &newValue);   
    array[*newIndex].value = newValue;
    array[array[addIndex].next].previous = *newIndex;
    array[*newIndex].next = array[addIndex].next;
    array[addIndex].next = *newIndex;
    array[*newIndex].previous = addIndex;
    printf("%d\n", *newIndex);
}

void addBehindF(Node *array, int *newIndex)
{
    int addIndex, newValue;
    scanf("%d %d", &addIndex, &newValue);
    array[*newIndex].value = newValue;
    array[array[addIndex].previous].next = *newIndex;
    array[*newIndex].previous = array[addIndex].previous;
    array[addIndex].previous = *newIndex;
    array[*newIndex].next = addIndex;
    printf("%d\n", *newIndex);
}

Node array0[1000001];
Node* array = array0 + 1;
int main()
{
    int amountOfTests;
    scanf("%d", &amountOfTests);
    for (int test = 0; test < amountOfTests; test++)
    {//
        int amountOfNodes, firstNode, lastNode, amountOfOperations;
        scanf("%d %d %d %d", &amountOfNodes, &firstNode, &lastNode, &amountOfOperations);
        array[-1].previous = lastNode;
        array[-1].next = firstNode; 
        int amountOfActiveNodes = amountOfNodes;
        for (int step = 0; step < amountOfNodes; ++step)
        {
            scanf("%d %d %d", &array[step].value, &array[step].next, &array[step].previous);
        }
        if (amountOfOperations == 0)
        {
            printf("===\n");
        }
        else
        {
            int typeOfOperation;
            for (int step = 0; step < amountOfOperations; step ++)
            {
                int addIndex, newIndex, newValue;
                scanf("%d", &typeOfOperation);
                if (typeOfOperation == addBehind)
                {
                    newIndex = amountOfNodes++;
                    amountOfActiveNodes ++;
                    addBehindF(array, &newIndex);
                }
                else if (typeOfOperation == addAfter)
                {
                    newIndex = amountOfNodes++;
                    amountOfActiveNodes ++;
                    addAfterF(array, &newIndex);
                }
                else
                {
                    amountOfActiveNodes --;
                    deletionF(array);
                }
            }
            printf("===\n");
        }
        firstNode = array[-1].next;
        lastNode = array[-1].previous;
        for (int step = firstNode; step >= 0; step = array[step].next)
        {
            printf("%d\n", array[step].value);
        }
        printf("===\n");
    }
    return 0;
}