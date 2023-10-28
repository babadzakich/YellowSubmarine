#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binarySearch(int leftLimit, int rightLimit, int* array, int search)
{  
    int guess = (leftLimit + rightLimit)/2;
    if (leftLimit >= rightLimit)
    {
        return leftLimit;
    }
    
    if(search < array[guess] && (abs(array[guess] - search) >= abs(array[guess-1] - search)))
    { 
        return binarySearch(leftLimit, guess, array, search); 
    }
    else if(search > array[guess] && (abs(array[guess] - search) >= abs(array[guess+1]-search)))
    { 
        return binarySearch(guess+1, rightLimit, array, search); 
    }
    else
    { 
        return guess; 
    } 
} 
    

int main()
{
    int amountOfElements;
    scanf("%d", &amountOfElements);
    int* array = (int*)malloc(sizeof(int)*amountOfElements);
    for (int step = 0; step < amountOfElements; step++)
    {
        scanf("%d", &array[step]);
    }
    
    int amountOfOperations;
    scanf("%d", &amountOfOperations);
    for(int step = 0; step < amountOfOperations; step++)
    {
        int value;
        scanf("%d", &value);
        int index = binarySearch(0, amountOfElements-1, array, value);
        printf("%d %d\n", index, abs(value - array[index]));
    }
    free(array);
    return 0;
}