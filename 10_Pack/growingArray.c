#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct dict_s
{
    char** words;
    int wordsInDict;
    int sizeOfDict;
}dictionary;

int main()
{
    dictionary* listOfWords = (dictionary*)malloc(sizeof(dictionary)*1000000);
    for (int step = 0; step < 1000000; step++)
    {
        listOfWords[step].wordsInDict = 0;
    }
    int amountOfWords;
    scanf("%d", &amountOfWords);
    for(int step = 0; step < amountOfWords; step++)
    {
        int key;
        char string[8];
        scanf("%d %s", &key, string);
        if(listOfWords[key].wordsInDict == 0)
        {
            listOfWords[key].words = (char**)malloc(sizeof(char*));
            listOfWords[key].words[listOfWords[key].wordsInDict] = (char*)malloc(sizeof(char)*8);
            strncpy(listOfWords[key].words[listOfWords[key].wordsInDict],string,8);
            listOfWords[key].wordsInDict++;
            listOfWords[key].sizeOfDict = 1;
        }
        else
        {
            if(listOfWords[key].wordsInDict == listOfWords[key].sizeOfDict)
            {
                listOfWords[key].words = realloc(listOfWords[key].words, sizeof(char*)*listOfWords[key].sizeOfDict*2);
                listOfWords[key].sizeOfDict *= 2;
            }
            listOfWords[key].words[listOfWords[key].wordsInDict] = (char*)malloc(sizeof(char)*7);
            strncpy(listOfWords[key].words[listOfWords[key].wordsInDict],string,8);
            listOfWords[key].wordsInDict++;
        }
    } 
    for(int step = 0; step < 1000001; step++)
    {
        if (listOfWords[step].wordsInDict > 0)
        {
            for (int step2 = 0; step2 < listOfWords[step].wordsInDict; step2++)
            {
                printf("%d %s\n", step, listOfWords[step].words[step2]);
                free(listOfWords[step].words[step2]);
            }
            free(listOfWords[step].words);
        }
    }
    free(listOfWords);
    return 0;
}