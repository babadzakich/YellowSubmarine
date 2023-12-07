#include <stdio.h>
#include <stdlib.h>
#define upperBit 0b1000
#define beforeUpperBit 0b0100
#define secondBit 0b0010
#define firstBit 0b0001

typedef struct Bufer_s{
    int size;
    int head;
    int tail;
    int* array;
}Bufer;

void initBufer(Bufer* bufer, int size)
{
    bufer->array = (int*)malloc(sizeof(int) * (2*size+1));
    for(int step = 0; step < size; step++)
    {
        bufer->array[step] = step+1;
    }
    for (int step = size + 1; step < 2*size+1; step++)
    {
        bufer->array[step] = size - step;
    }
    bufer->head = 0;
    bufer->tail = size+1;
}

int main()
{
    int buferLength, amountOfOperations;
    scanf("%d %d", &buferLength, &amountOfOperations);
    Bufer bufer;
    char operation;
    int flagUpper = 0, flagBU = 0;
    initBufer(&bufer, buferLength);
    for(int step = 0; step < amountOfOperations; step++)
    {
        int intOperation;
        scanf("%c", &operation);
        if(operation - '0' > 9)
        {
            intOperation = operation - 'A' + 10;
        }
        else
        {
            intOperation = operation - '0';
        }
        if ((operation & upperBit) && (operation & beforeUpperBit))
        {
            if(bufer.head > bufer.size)
            {
                continue;
            }

        }
    }

    return 0;
}