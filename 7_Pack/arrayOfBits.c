#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define initBitSetOfZero 0
#define getBitValue 1
#define setBitValue 2
#define intervalHasOne 3

//какой-нибудь целочисленный тип (желательно беззнаковый)
typedef unsigned int bitword ;
//инициализирует массив битов длины num, устанавливая все его биты в ноль
void bitsetZero ( bitword * arr , int num )
{
    arr = (bitword*)malloc(sizeof(bitword)*num);
    for (int step = 0; step < num; ++step)
    {
        arr[step] = 0;
    }
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

    if (left == right)
    {
        return 0;
    }
    int value;
    bitword value2 = arr[leftInd]>>(7-rightBitInd);
    if (leftInd == rightInd)
    {
        
        return 0;
    }
    
    if (leftBitInd == 0)
    {
        value = 1;
    }
    else
    {
        value = pow(2, leftBitInd);
    }
    if (arr[leftInd] >= value)
    {
        return 1;
    }
    else
    {
        leftInd ++;
    }
    
    if (rightBitInd == 0)
    {
        value = 1;
    }
    else
    {
        value = pow(2, rightBitInd);
    }
    if ((arr[rightBitInd] < value) && (arr[rightBitInd]> 0))
    {
        return 1;
    }
    else
    {
        rightInd --;
    }

    if ( leftInd > rightInd)
    {
        return 0;
    }
    while (leftInd<=rightInd)
    {
        if (arr[leftInd++]!= 0)
        {
            return 1;
        }
    }
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
            if (amountOfBits % 8 == 0)
            {
                amountOfBits = amountOfBits / 8;
            }
            else
            {
                amountOfBits = amountOfBits / 8 + 1;
            }
            if (bits != NULL)
            {
                bits = (bitword*)realloc(bits, (sizeof(bitword)*amountOfBits));
            }
            else
            {
                bits = (bitword*)malloc(sizeof(bitword)*amountOfBits);
            }
            for (int step = 0; step < amountOfBits; ++step)
                {
                    bits[step] = 0;
                }
            //bitsetZero(bits, amountOfBits);
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