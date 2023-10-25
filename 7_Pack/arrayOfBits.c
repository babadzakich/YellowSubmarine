#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define initBitSetOfZero 0
#define getBitValue 1
#define setBitValue 2
#define intervalHasOne 3

//какой-нибудь целочисленный тип (желательно беззнаковый)
typedef unsigned char bitword ;
//инициализирует массив битов длины num, устанавливая все его биты в ноль
void bitsetZero ( bitword ** arr , int num )
{
    if (*arr != NULL)
    {
        free(*arr);
    }
    *arr = calloc(num, sizeof(bitword));
}

//возвращает значение idx-ого бита (0 или 1)
int bitsetGet ( const bitword * arr , int idx )
{
    int bitPosition = idx%(sizeof(bitword) *8);
    idx /= (sizeof(bitword)*8);
    bitword temporaryValue = arr[idx];

    return ((temporaryValue>>bitPosition)&1);
}

//устанавливает значение idx-ого бита в newval (которое равно 0 или 1)
void bitsetSet ( bitword * arr , int idx , int newval )
{
    int bitPosition = idx % (sizeof(bitword)*8), bitValue = bitsetGet(arr, idx);
    idx /= (sizeof(bitword)*8);

    if (bitValue != newval)
    {
        arr[idx] ^= (1<<bitPosition);
    }
}

//возвращает 1, если среди битов с номерами k
//для left <= k < right есть единичный, и 0 иначе
int bitsetAny ( const bitword * arr , int left , int right )
{
    int leftInd = left / (sizeof(bitword)*8);
    int rightInd = right / (sizeof(bitword)*8);
    int leftBitInd = left % (sizeof(bitword)*8);
    int rightBitInd = right % (sizeof(bitword)*8);

    if (leftInd == rightInd)
    {
        for (int step = leftBitInd; step < rightBitInd; step++)
        {
            if(bitsetGet(arr, step+(leftInd*8)))
            {
                return 1;
            }
        }
        return 0;
    }
    for (int step = left; step < (leftInd+1)*8; step++)
    {
        if (bitsetGet(arr, step))
        {
            return 1;
        }
    }
    for (int step = rightInd*8; step < right; step++)
    {
        if (bitsetGet(arr, step))
        {
            return 1;
        }
    }
    
    for(int step = leftInd+1; step < rightInd; step++)
    {
        if(arr[step] != 0)
        {
            return 1;
        }
    }
    // while (leftInd < rightInd)
    // {
    //     if (arr[leftInd++]!= 0)
    //     {
    //         return 1;
    //     }
    // }
    return 0;
}

int main()
{
    int amountOfOperations;
    scanf("%d", &amountOfOperations);
    bitword* bits = NULL;
    for (int step = 0; step < amountOfOperations; ++step)
    {
        int typeOfOperation;
        scanf("%d", &typeOfOperation);
        if (typeOfOperation == initBitSetOfZero)
        {
            int amountOfBits;
            scanf("%d", &amountOfBits);
            amountOfBits = amountOfBits / 8 + 1;
            
            bitsetZero(&bits, amountOfBits);
        }
        else if (typeOfOperation == getBitValue)
        {
            int index;
            scanf("%d", &index);
            printf("%d\n", bitsetGet(bits, index));
        }
        else if (typeOfOperation == setBitValue)
        {
            int index, newval;
            scanf("%d %d", &index, &newval);
            bitsetSet(bits, index, newval);
        }
        else if (typeOfOperation == intervalHasOne)
        {
            int leftLimit, rightLimit;
            scanf("%d %d", &leftLimit, &rightLimit);
            if (bitsetAny(bits, leftLimit, rightLimit))
            {
                printf("some\n");
            }
            else
            {
                printf("none\n");
            }
        }
    }
    free(bits);
    return 0;
}