#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define maxLimit 9369319

typedef struct Node_s
{
    struct Node_s *next;
    uint64_t value;
    uint64_t counter;
}Node;


int isHere(Node** hashTable, uint64_t hash, uint64_t value) 
{
    Node* temp = hashTable[hash];
    while (temp != NULL) 
    {
        if (temp->value == value) 
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

uint64_t a, b, c, M;
uint64_t func(uint64_t s)
{
    return ( s * s * a + s * b + c ) % M;
}

int main()
{
    scanf("%llu", &M);
    scanf("%llu %llu %llu", &a, &b, &c);
    uint64_t state = 1, counter = 0;
    uint64_t hash = state % maxLimit;
    Node** hashTable = (Node**)calloc(maxLimit,sizeof(Node*));
    while(counter < M)
    {
        if(isHere(hashTable, hash, state))
        {
            break;
        }
        Node* new = (Node*)malloc(sizeof(Node));
        new->counter = counter;
        new->value = state; 
        new->next = NULL;
        if(hashTable[hash] == NULL)
        {
            hashTable[hash] = new;
        }
        else
        {
            Node* current = hashTable[hash];
            while(current->next != NULL)
            {
                current = current->next;
            }
            current->next = new;
        }
        state = func(state);
        hash = state % maxLimit;
        counter++;
    }
    
    Node* result = hashTable[hash];
    while(result->value != state)
    {
        result = result->next;
    }
    printf("%llu %llu\n", result->counter ,counter);
    for(int step = 0; step < maxLimit; step++)
    {
        if (hashTable[step]!= NULL)

        {
            Node* current = hashTable[step];
            Node* temp = NULL;
            while(current != NULL)
            {
                temp = current;
                current = current->next;
                free(temp);
            }
        }
        
    }
    free(hashTable);
    return 0;
}