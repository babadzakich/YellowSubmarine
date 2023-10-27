#include <stdio.h>
#include <stdlib.h>

void binarySearch(int leftLimit, int rightLimit, int* array, int search)
{  
    while (leftLimit < rightLimit)
    {
        int guess = (leftLimit + rightLimit) / 2;
        if (array[guess] == search || array[guess] == search + 1)
        {
            if (array[guess] == search)
            {
                printf("%d 0\n", guess);
                return;
            }
            else
            {
                binarySearch(leftLimit, guess, array, search-1);
                printf("%d 1\n", guess);
                return;
            }
        }
        else if (array[guess] < search)
        {
            leftLimit = guess + 1;
        }
        else
        {
            rightLimit = guess - 1;
        }
        
        
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
        binarySearch(0, amountOfElements-1, array, value);
    }
    return 0;
}