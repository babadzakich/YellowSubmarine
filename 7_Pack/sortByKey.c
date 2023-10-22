#include <stdio.h>
#include <stdlib.h>

#define INSERTIONCHECK(a, b) ((a) > (b))
typedef struct dict_s{
    int key;
    char line[8];
}dict;

void insertionSort(dict dictionary[], int amountOfElements)
{
    dict temporaryVariable;
    for(int step = 1; step < amountOfElements; step++)
    {
        if (INSERTIONCHECK(dictionary[step-1].key, dictionary[step].key) )
        {
            int step2 = step;
            while ( INSERTIONCHECK(dictionary[step2-1].key, dictionary[step2].key) && step2 > 0)
            {
                temporaryVariable = dictionary[step2-1];
                dictionary[step2-1] = dictionary[step2];
                dictionary[step2--] = temporaryVariable;
            }
        }
    }
}
int main()
{
    int amountOfElements;
    scanf("%d", &amountOfElements);
    dict* dictionary = (dict*)malloc(sizeof(dict)*amountOfElements);

    for (int step = 0; step < amountOfElements; ++step)
    {
        scanf("%d %s", &dictionary[step].key, dictionary[step].line);
    }
    insertionSort(dictionary, amountOfElements);
    //printf("===\n");
    for( int step = 0; step < amountOfElements; ++step)
    {
        printf("%d %s\n", dictionary[step].key, dictionary[step].line);
    }
    return 0;
}