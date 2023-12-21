#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int (* callback )( const void * ,const void*);

int stringsFunc(const void* guess, const void* call)
{
    char *number1 = *(char **)guess;
    char *number2 = (char *)call;
    return strcmp(number1, number2);
}

int lower_boundary(void* array, int length, void* call, int size, callback func)
{
    int leftLimit = 0, rightLimit = length - 1;
    while(leftLimit < rightLimit)
    {
        int guess = (leftLimit + rightLimit)/2;
        void* guessPtr = (void*)(((char*)array) + guess * size);
        
        if (func(guessPtr, call) >= 0)
        {   
            rightLimit = guess;
        }
        else
        {
            leftLimit = guess + 1;
        }       
    }

    void *guessPtr = (void *)(((char*)array) + leftLimit*size);
    if (leftLimit < length && func(guessPtr, call) < 0)
    {
        leftLimit++;
    }
    return leftLimit;

}

int compareNum(const void* number1, const void* number2)
{
    if (*(long long*)number1 < *(long long*)number2)
    {
        return -1;
    }
    else if (*(long long*)number1 > *(long long*)number2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int compareStr(void const *line1, void const *line2) 
{ 
    char const *string1 = *(char const **)line1;
    char const *string2 = *(char const **)line2;
    return strcmp(string1, string2);
}

int main()
{
    int amountOfNumbers;
    scanf("%d", &amountOfNumbers);
    long long* numbersArray =(long long*)calloc(amountOfNumbers,sizeof(long long));
    for (int step = 0; step < amountOfNumbers; step++)
    {
        scanf("%lld", &numbersArray[step]);
    }
    
    int amountOfLines;
    scanf("%d", &amountOfLines);
    char** stringsArray = (char**)calloc(amountOfLines, sizeof(char*));
    for(int step = 0; step < amountOfLines; step++)
    {
        char* current = (char*)calloc(32, sizeof(char));
        scanf("%s", current);
        stringsArray[step] = current;
        
    }
    
    qsort(numbersArray, amountOfNumbers, sizeof(long long), compareNum);
    qsort(stringsArray, amountOfLines, sizeof(char*), compareStr);
    
    int flag = 0;
    int amountOfOperationsOnNumbers;
    scanf("%d", &amountOfOperationsOnNumbers);
    for(int step = 0; step < amountOfOperationsOnNumbers; step++)
    {
        long long current;
        scanf("%lld", &current);
        printf("%d\n", lower_boundary(numbersArray, amountOfNumbers, &current, sizeof(long long), compareNum));
    }

    flag = 1;
    int amountOfOperationsOnStrings;
    scanf("%d", &amountOfOperationsOnStrings);
    for(int step = 0; step < amountOfOperationsOnStrings; step++)
    {
        char current[32];
        scanf("%s", current);
        printf("%d\n", lower_boundary(stringsArray, amountOfLines, current, sizeof(char*), stringsFunc));
    }

    free(numbersArray);
    for(int step = 0; step  <amountOfLines; step++)
    {
        free(stringsArray[step]);
    }
    free(stringsArray);
    return 0;
}