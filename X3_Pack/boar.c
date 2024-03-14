#include<stdio.h>
#include<string.h>

Node* root;
typedef struct Node
{
    Node* link[256];
    char endOfWord;
}Node;

void add(char* stroka)
{
    Node* tree[strlen(stroka)];
    int treeStep = 0;
    Node* curr = root;
    while(*stroka)
    {
        if (*stroka == ' ')
        {
            stroka++;
            continue;
        }
        
        if(!curr->link[*stroka])
        {
            curr->link[*stroka] = tree[treeStep++];
        }
        curr = curr->link[*stroka];
        stroka++;
    }
}