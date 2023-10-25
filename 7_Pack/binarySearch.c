#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binarySearch(int leftLimit, int rightLimit, int* array, int call)
{
    if (leftLimit > rightLimit)
    {
        return -1;
    }

    int guess = (leftLimit + rightLimit)/2;

    if ( array[guess] > call)
    {
        return binarySearch(leftLimit, guess-1, array, call);
    }
    else if (array[guess] < call)
    {
        return binarySearch(guess+1, rightLimit, array, call);
    }
    else
    {
        int result = guess;
        while(result != -1)
        {
            guess = result;
            result = binarySearch(result+1, rightLimit, array, call);
        }
        return guess;
    }
}

int main()
{
    int arrayLength;
    scanf("%d", &arrayLength);
    int* array = (int*)malloc(sizeof(int) * arrayLength);
    for (int step = 0; step < arrayLength; step++)
    {
        scanf("%d", &array[step]);
    }

    int amountOfOperations;
    int searchedIndex = 0;
    scanf("%d", &amountOfOperations);
    for (int step = 0; step < amountOfOperations; step++)
    {
        int currentCall;
        scanf("%d", &currentCall);
        currentCall += searchedIndex;
        searchedIndex = binarySearch(0, arrayLength-1, array, currentCall);
        printf("%d\n", searchedIndex);
    }
    free(array);
    return 0;
}