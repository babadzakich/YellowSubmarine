#include <stdio.h>
#include <stdlib.h>
#define additionBefore -1
#define additionAfter 1
#define deletion 0

typedef struct Node_s {
struct Node_s * prev , * next ;
void * value ;
} Node ;

//List –- вспомогательный узел, являющийся головой списка
typedef Node List ;

//инициализирует поля структуры *list значениями для пустого списка
void initList ( List * list )
{
    list->prev = list;
    list->next = list;
}

//создаёт новый узел со значением ptr и вставляет его после узла node
//возвращает указатель на созданный узел
Node * addAfter ( Node * node , void * ptr )
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    node->next->prev = newNode;
    newNode->next = node->next;
    node->next = newNode;
    newNode->prev = node;
    newNode->value = ptr;
    return newNode;
}

//создаёт новый узел со значением ptr и вставляет его перед узлом node
//возвращает указатель на созданный узел
Node * addBefore ( Node * node , void * ptr )
{
    Node *newNode = (Node*)malloc(sizeof(Node)); 
    newNode->prev = node->prev;
    node->prev->next = newNode;
    newNode->next = node;
    node->prev = newNode; 
    newNode->value = ptr;  
    return newNode;
}

//удаляет заданный узел, возвращая значение, которое в нём лежало
void * erase ( Node * node )
{
    node->next->prev = node->prev;
    node->prev->next = node->next;
    void* value = node->value;
    free(node);
    return value;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Node** array0 = (Node**)malloc(sizeof(Node*)*1000001);
    Node** array = (array0 + 1);
    
    for (int step = 0; step < 1000001; ++step)
    {
        array0[step] = NULL;
    }

    int Tests, amountOfOperations;
    scanf("%d", &Tests);
    for (int test = 1; test <= Tests; test++)
    {
        List *linkedList = (List*)malloc(sizeof(List));
        initList(linkedList);
        array[-1] = linkedList;
        int amountOfNodesInArray = 0;
        scanf("%d", &amountOfOperations);
        
        for (int operation = 1; operation <= amountOfOperations; ++operation)
        {
            int typeOfOperation, operationalIndex;
            scanf("%d %d", &typeOfOperation, &operationalIndex);
            Node *currentNode = array0[operationalIndex+1];
            //scanf("%d", &value);
            if (typeOfOperation == additionAfter)
            {
                int value;
                void *valueP = malloc(sizeof(int));
                
                scanf("%d", &value);
                *((int*)valueP) = value;
                array[amountOfNodesInArray++] = addAfter(currentNode, valueP);
            }
            else if (typeOfOperation == additionBefore)
            {
                int value;
                void *valueP = malloc(sizeof(int));
                scanf("%d", &value);
                *((int*)valueP) = value;
                array[amountOfNodesInArray++] = addBefore(currentNode, valueP);
            }
            else
            {
                free(erase(currentNode));
            }
        }
        for (Node* step = linkedList->next; step != linkedList; step = step->next)
        {
            printf("%d\n", *((int*)step->value));
        }
        printf("===\n");
        // for(int step = 0; step < 1000001; ++step)
        // {
        //     if (array0[step] != NULL)
        //     {
        //         free(array0[step]);
        //         array0[step] = NULL;
        //     }
        // }
        Node* step = linkedList->next;
        while(step != linkedList)
        {
            Node *temporaryNode = step->next;
            free(step->value);
            free(step);
            step = temporaryNode;
        }
        free(linkedList);

    }
    free(array0);
    fclose(stdin);
    fclose(stdout);
    return 0;
}