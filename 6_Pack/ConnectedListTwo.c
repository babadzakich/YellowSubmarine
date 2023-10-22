#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char value[8];  
    int next;
}Node;

int main()
{
    int amountOfTests;
    scanf("%d", &amountOfTests);
    for (int test = 0; test < amountOfTests; ++test)
    {
        int amountOfElements, firstIndex, amountOfOperations;
        scanf("%d %d %d", &amountOfElements, &firstIndex, &amountOfOperations);
        Node array[1000000];
        for(int step = 0; step < amountOfElements; ++step)
        {
            scanf("%s %d", array[step].value, &array[step].next);
        }
        if (amountOfOperations == 0)
        {
            printf("===\n");
        }
        else
        {
            for (int step = 0; step < amountOfOperations; ++step)
            {
                int typeOfOperation, workingIndex;
                char newValue[8];
                scanf("%d", &typeOfOperation);
                if (typeOfOperation == 0)
                {
                    scanf("%d %s", &workingIndex, newValue);
                    if(workingIndex == -1)
                    {
                        int newIndex;
                        newIndex = amountOfElements++;
                        strcpy(array[newIndex].value, newValue);
                        array[newIndex].next = firstIndex;
                        firstIndex = newIndex;
                        printf("%d\n", amountOfElements-1);
                    }
                    else
                    {
                        int newIndex = amountOfElements++;
                        array[newIndex].next = array[workingIndex].next;
                        array[workingIndex].next = newIndex;
                        strcpy(array[newIndex].value,newValue);
                        printf("%d\n", newIndex);
                    }
                }
                else
                {
                    scanf("%d", &workingIndex);
                    if (workingIndex == -1)
                    {
                        printf("%s\n", array[firstIndex].value);
                        firstIndex = array[firstIndex].next;
                    }
                    else
                    { 
                        printf("%s\n", array[array[workingIndex].next].value);
                        array[workingIndex].next = array[array[workingIndex].next].next;
                    }
                }
                if (step == amountOfOperations - 1)
                {
                    printf("===\n");
                }
            }
        }
        for (int step = firstIndex; step >= 0; step = array[step].next)
        {
            printf("%s\n", array[step].value);
        }
        printf("===\n");
    }
    return 0;
}