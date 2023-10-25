#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    int amountOfTests;
    scanf("%d", &amountOfTests);
    for (int step = 1; step <= amountOfTests; step++)
    {
        double delimeter, divider;
        uint64_t bitWord;
        scanf("%lf/%lf xor %llx", &delimeter, &divider, &bitWord);
        //printf("%lf %lf %11x\n", delimeter, divider, bitWord);
        double divisionResult = delimeter/divider;
        unsigned long long* bitDivisionResult = (unsigned long long*)&divisionResult;
        unsigned long long bitXorResult = (*bitDivisionResult) ^ bitWord;
        double xorResult = *((double*)&bitXorResult);
        printf("%0.15g\n", xorResult);
    }
    return 0;
}