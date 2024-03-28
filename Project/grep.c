#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ahocorassic.h"
char buffer[1024];

int main(int argc, char** argv)
{
    if (argc == 1) return 1;
    char* pattern = argv[1];
    char* inputFile = argv[2];
    FILE *in = fopen(inputFile, "r");
    
    int pos = 0, length = strlen(pattern);
    char curr;
    int bufLen = 0;

    while(fscanf(in, "%c", &curr) != EOF)
    {       
        
        buffer[bufLen++] = curr;
        if (curr == '\n')
        {
            initTrie(buffer, bufLen);
            if (isInTrie(pattern, length))
            {
                printf("It is indeed here\n");
            }
            else
            {
                printf("What a pity, it`s not here\n");
            }
            memset(buffer, 0, bufLen);
            bufLen = 0;
        }
    } 
    return 0;
}