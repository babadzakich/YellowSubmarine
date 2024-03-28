#include <stdlib.h>
#include "ahocorassic.h"
#include <string.h>

vector tree;
Node* root = NULL;

typedef struct Vector
{
    Node* array;
    int cap;
    int top;
}vector;

void vector_add(vector* array, Node vertex)
{
    if(array->cap == 0)
    {
        array->cap = 1;
        array->array = (Node*)malloc(sizeof(Node));
    }
    if (array->cap == array->top)
    {
        array->cap *= 2;
        array->array = (Node*)realloc(array->array, sizeof(Node) * array->cap);
    }
    array->array[array->top++] = vertex;
}

Node makeTrieVertex()
{
    Node vertex;
    memset(vertex.nextLetter, 255, sizeof(vertex.nextLetter));
    vertex.isWord = 0;
    return vertex;
}

void initTrie(char* str, int strlen)
{
    Node** tree = (Node**)calloc(strlen, sizeof(Node*));
    int nextNode = 1;
    root = tree[0];
    Node* cur = root; 
    for (int step = 0; step < strlen; step++)
    {
        if (str[step] = ' ')
        {
            cur->isWord = 1;
            cur = root;
            continue;
        }
        Node* temp = cur->nextLetter[str[step] - 'a'];
        if (temp == NULL)
        {
            temp = tree[nextNode++];
        }
        temp->parent = cur;
        temp->isWord = 0;
        cur = temp;
   }
}
int isInTrie(char* pattern, int len)
{
    Node* curr = root;
    for(int step = 0; step < len; step++)
    {
        if (curr->nextLetter[pattern[step] - 'a'] == NULL) return 0;
        curr = curr->nextLetter[pattern[step] - 'a'];
    }
    return 1;
}