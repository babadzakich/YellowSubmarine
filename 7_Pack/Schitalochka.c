#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s
{
    int value;
    struct Node_s *next, *previous;
}Node;

Node* listInitialization(int lengthOfList)
{
    Node* firstNode = (Node*)malloc(sizeof(Node));
    firstNode->value = 1;
    firstNode->next = firstNode;
    firstNode->previous = firstNode;
    Node* previousNode = firstNode;
    for(int step = 2; step <= lengthOfList; step++)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->value = step;
        newNode->next = previousNode->next;
        newNode->previous = previousNode;
        previousNode->next->previous = newNode;
        previousNode->next = newNode;
        previousNode = newNode;
    }
    return firstNode;
}

void deleteNode(Node* currentNode)
{
    currentNode->previous->next = currentNode->next;
    currentNode->next->previous = currentNode->previous;
}

Node* listStep(Node* currentNode, int step)
{
    for (int step2 = 0; step2 < step; step2++)
    {
        currentNode = currentNode->next;
    }
    return currentNode;
}

int main()
{
    int amountOfNumbers, step;
    scanf("%d %d", &amountOfNumbers, &step);
    Node* linkedList = listInitialization(amountOfNumbers);  
    Node* step2 = (Node*)malloc(sizeof(Node));
    step2->next = linkedList;  
    step2 = listStep(step2, step); 
    while (step2->next != step2)
    {  
        printf("%d\n", step2->value);
        Node* temporaryNode = listStep(step2, step);
        deleteNode(step2);
        free(step2);
        step2 = temporaryNode;
    }
    return 0;
}