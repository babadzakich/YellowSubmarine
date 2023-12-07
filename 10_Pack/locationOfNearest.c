#include <stdio.h>
#include <stdlib.h>

int main()
{
    int amountOfCalls, intervalOfCalls;
    scanf ("%d %d", &amountOfCalls, &intervalOfCalls);
    int* array = (int*)malloc(sizeof(int)*amountOfCalls);
    int leftSide = 0;
    for (int step = 0; step < amountOfCalls; step++)
    {
        scanf("%d", &array[step]);
        while(array[step] - array[leftSide] > intervalOfCalls)
        {
            leftSide++;
        }
        printf("%d\n", step - leftSide + 1);
    }
    free(array);
    return 0;
}