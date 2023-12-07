#include <stdio.h>
#include <stdlib.h>

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
        
    }
}

int main()
{
    int buferLength, amountOfOperations;
    scanf("%d %d", &buferLength, &amountOfOperations);
    Bufer bufer;
    initBufer(&bufer, buferLength);
    

    return 0;
}