#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    double value;
    int next;
    int previous;
}Node;
Node array[1000001];
int main()
{
    int amountOfTests;
    //Node array[1000];
    scanf("%d", &amountOfTests);
    for(int test = 1; test <= amountOfTests; ++test)
    {
        int amountOfNodes, amountOfActiveNodes, firstNode, lastNode, amountOfOperations;
        scanf("%d %d %d %d", &amountOfNodes, &firstNode, &lastNode, &amountOfOperations);
        amountOfActiveNodes = amountOfNodes;
        for (int step = 0; step < amountOfNodes; ++step)
        {
            scanf("%lf %d %d", &array[step].value, &array[step].next, &array[step].previous);
        }
        if (amountOfOperations == 0)
        {
            printf("===\n");
        }
        else
        {
            int typeOfOperation;
            for (int step = 0; step < amountOfOperations; ++step)
            {
                scanf("%d", &typeOfOperation);
                if ((typeOfOperation == 1 || typeOfOperation == -1) && amountOfActiveNodes <= 0)
                {
                    int addIndex, newIndex;
                    double newValue;
                    scanf("%d %lf", &addIndex, &newValue);
                    newIndex = amountOfNodes++;
                    array[newIndex].value = newValue;
                    amountOfActiveNodes ++;
                    firstNode = newIndex;
                    lastNode = newIndex;
                    array[newIndex].next = -1;
                    array[newIndex].previous = -1;
                    printf("%d\n", newIndex);
                }
                else if(typeOfOperation == 1) // добавление спереди
                {
                    int addIndex, newIndex;
                    double newValue;
                    scanf("%d %lf", &addIndex, &newValue);
                    
                    newIndex = amountOfNodes++;
                    array[newIndex].value = newValue;
                    amountOfActiveNodes ++;
                    if (addIndex == -1)
                    {
                        array[firstNode].previous = newIndex;
                        array[newIndex].next = firstNode;
                        array[newIndex].previous = -1;
                        firstNode = newIndex;
                        printf("%d\n", amountOfNodes - 1);
                    }
                    // else
                    // {
                    //     array[array[addIndex].next].previous = newIndex;
                    //     array[newIndex].next = array[addIndex].next;
                    //     array[addIndex].next = newIndex;
                    //     array[newIndex].previous = addIndex;
                    //     printf("%d", newIndex);
                    // }
                    else
                    {
                        if (array[addIndex].next == -1)
                        {
                            array[newIndex].next = -1;
                            array[newIndex].previous = addIndex;
                            array[addIndex].next = newIndex;
                            lastNode = newIndex;
                        }
                        else
                        {
                            array[array[addIndex].next].previous = newIndex;
                            array[newIndex].next = array[addIndex].next;
                            array[addIndex].next = newIndex;
                            array[newIndex].previous = addIndex;
                        }
                        printf("%d\n", amountOfNodes-1);
                        
                    }
                }
                else if(typeOfOperation == -1)
                {
                    int addIndex, newIndex;
                    double newValue;
                    scanf("%d %lf", &addIndex, &newValue);
                    newIndex = amountOfNodes++;
                    amountOfActiveNodes ++;
                    array[newIndex].value = newValue;
                    if (addIndex == -1)
                    {
                        array[newIndex].previous = lastNode;
                        array[lastNode].next = newIndex;
                        array[newIndex].next = -1;
                        lastNode = newIndex;
                        printf("%d\n", amountOfNodes - 1);
                    }
                     else
                    {   
                        
                        if (array[addIndex].previous == -1)
                        {
                            array[newIndex].previous = -1;
                            array[newIndex].next = addIndex;
                            array[addIndex].previous = newIndex;
                        }
                        else
                        {
                            array[array[addIndex].previous].next = newIndex;
                            array[newIndex].previous = array[addIndex].previous;
                            array[addIndex].previous = newIndex;
                            array[newIndex].next = addIndex;
                        }
                        printf("%d\n", amountOfNodes-1);
                    }
                }
                else if (typeOfOperation == 0)
                {
                    if (amountOfActiveNodes <= 0)
                    {
                        continue;
                    }
                    int deleteIndex;
                    scanf("%d", &deleteIndex);
                    amountOfActiveNodes --;
                    if(amountOfActiveNodes <= 0)
                    {
                        firstNode = -1;
                        lastNode = -1;
                        printf("%0.0lf\n", array[deleteIndex].value);
                    }
                    else
                    {
                        if (array[deleteIndex].next == -1)
                        {
                            array[array[deleteIndex].previous].next = -1;
                            lastNode = array[deleteIndex].previous;
                            printf("%0.0lf\n", array[deleteIndex].value);
                        }
                        else if(array[deleteIndex].previous == -1)
                        {
                            array[array[deleteIndex].next].previous = -1;
                            firstNode = array[deleteIndex].next;
                            printf("%0.0lf\n", array[deleteIndex].value);
                        }
                        else
                        {
                            array[array[deleteIndex].previous].next = array[deleteIndex].next;
                            array[array[deleteIndex].next].previous = array[deleteIndex].previous;
                            printf("%0.0lf\n",array[deleteIndex].value);
                        }
                    }
                }
                
            }
            printf("===\n");
        }
        int temporaryIndex;
        for(int step = firstNode; step >= 0; step = array[step].next)
        {
            printf("%0.0lf\n", array[step].value);
        }
        
        printf("===\n");
    }
    return 0;
}