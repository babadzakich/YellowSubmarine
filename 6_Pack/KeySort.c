#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char value[7];
    struct Node* next;
}Node;

typedef struct ListLen{
    int *length;
    Node *firstNode;
    Node *lastNode;
}LinkedList;

//LinkedList *linkedList[1000001];

int main()
{
    int amountOfElements, key;
    Node *temporaryList;
    LinkedList* linkedList = (LinkedList*)malloc(sizeof(LinkedList)*1000001);
    char line[7];
    scanf("%d", &amountOfElements);
    for (int step = 0; step < 1000001; ++step)
    {
        linkedList[step].length = 0;
        linkedList[step].firstNode = NULL;
        linkedList[step].lastNode = NULL;
    }
    for (int step = 0; step < amountOfElements; ++step)
    {
        scanf("%d %s", &key, line);
        temporaryList = (Node*)malloc(sizeof(Node));
        temporaryList->next = NULL;
        strcpy(temporaryList->value, line);
        if (linkedList[key].length == 0)
        {
            linkedList[key].firstNode = temporaryList;
            linkedList[key].lastNode = temporaryList;
        }
        else
        {
            //linkedList[key].lastNode = temporaryList;
            linkedList[key].lastNode->next = temporaryList;
            temporaryList->next = NULL;
            linkedList[key].lastNode = temporaryList;
        }
        linkedList[key].length ++;
    }
    for (int step = 0; step < 1000001; ++step)
    {
        if (linkedList[step].firstNode != NULL)
        {
            temporaryList = linkedList[step].firstNode;
            while (temporaryList != NULL)
            {
                printf("%d %s\n",step, temporaryList->value);
                temporaryList = temporaryList->next;
            }
        }
    }
    for (int step = 0; step < 1000001; ++step)
    {
        if (linkedList[step].length > 0)
        {
            temporaryList = linkedList[step].firstNode;
            while (temporaryList != NULL)
            {
                Node *temporaryList2 = temporaryList->next;
                free(temporaryList);
                temporaryList = temporaryList2;

            }
        }
    }
    free(linkedList);
    return 0;
}