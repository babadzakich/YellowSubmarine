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
    int bitPosition = 7-idx % 8, bitValue = bitsetGet(arr, idx);
    idx /= 8;

    if (bitValue != newval)
    {
        if (bitValue)
        {
            if (bitPosition != 0)
            {
                arr[idx] -= pow(2,bitPosition);
            }
            else
            {
                arr[idx] --;
            }
        }
        else
        {
            if (bitPosition != 0)
                {
                    arr[idx] += pow(2,bitPosition);
                }
                else
                {
                    arr[idx] ++;
                }
        }
    }
}

//возвращает 1, если среди битов с номерами k
//для left <= k < right есть единичный, и 0 иначе
int bitsetAny ( const bitword * arr , int left , int right )
{
    int step = left/8;
    int limit = right / 8;
    int bitposLimit = 7 - right % 8;
    int bitposLeft = 7 - left % 8;
    if (bitposLimit != 7)
    {
        bitword value = arr[limit];
        if (value < pow(2, bitposLimit))
        {
            return 1;
        }
        if (bitposLimit == 0)
        {
            value --;
        }
        else
        {
            value -= pow(2, bitposLimit);
        }
        if (value != 0 && value > pow(2,bitposLimit))
        {
            return 1;
        }
    }
    limit--;

    bitword value = arr[step];
    if (value >= pow(2,bitposLeft))
    {
        return 1;
    }
    if (bitposLeft == 0)
    {
        value --;
    }
    else
    {
        value -= pow(2, bitposLeft);
    }
    if (value != 0 && value < pow(2,bitposLeft))
    {
        return 1;
    }
    step ++;
    

    while (step <= limit)
        {
            if (arr[step] != 0)
            {
                return 1;
            }
            step++;
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
            if (bits != NULL)
            {
                free(bits);
                bits = NULL;
            }
            scanf("%d", &amountOfBits);
            if (amountOfBits % 8 == 0)
            {
                amountOfBits = amountOfBits / 8;
            }
            else
            {
                amountOfBits = amountOfBits / 8 + 1;
            }
            bits = (bitword*)malloc(sizeof(bitword)*amountOfBits);
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
    return 0;
}