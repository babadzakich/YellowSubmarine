#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binarySearch(int leftLimit, int rightLimit, int* array, int call)
{
    int guess;
    if (leftLimit >= rightLimit)
    {
        guess = (leftLimit + rightLimit) / 2;
      
        int result;
        if (array[guess] == call)
        {
            result = binarySearch(guess, rightLimit, array, call);
            if (result > guess)
            {
                return result;
            }
            else{
                return guess;
            }
        }
        if (array[guess] > call)
        {
            return binarySearch(leftLimit, guess-1, array, call);
        }
        else
        {
            return binarySearch(guess+1, rightLimit, array, call);
        }
    }
    return -1;
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
        searchedIndex = binarySearch(0, arrayLength, array, currentCall);
        printf("%d\n", searchedIndex);
    }
    free(array);
    return 0;
}