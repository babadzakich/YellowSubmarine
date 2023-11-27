#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int findingOfLeast(int64_t *array, int length, int64_t coef) {
    int left = 0;
    int right = length - 1;
    int result = -1;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2; //finding middle index
        int64_t funcValue = array[mid] + coef * mid;// argmin at middle element

        if (mid < right && funcValue > array[mid + 1] + coef * (mid + 1)) 
        {
            left = mid + 1;
        } 
        else if (mid > left && funcValue >= array[mid - 1] + coef * (mid - 1)) 
        {
            right = mid - 1;
        } 
        else 
        {
            result = mid;
            break;
        }
    }

    return result;
}

int main() 
{
    int arrayLength;
    scanf("%d", &arrayLength);

    int64_t *array = (int64_t*)malloc(sizeof(int64_t) * arrayLength);
    for (int step = 0; step < arrayLength; step++) 
    {
        scanf("%lld", &array[step]);
    }

    int amountOfOperations;
    scanf("%d", &amountOfOperations);
    int64_t coef;
    for (int step = 0; step < amountOfOperations; step++) 
    {
        scanf("%lld", &coef);

        int result = findingOfLeast(array, arrayLength, coef);
        printf("%d\n", result);
    }

    free(array);

    return 0;
}