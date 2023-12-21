#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include <math.h>

typedef struct Avalanche_struct
{
    uint32_t testsAmount;
    uint32_t badTests;
}Avalanche;


long long unsigned A, B, M, R, S;
uint32_t hashFunc(uint32_t x)
{
    return (((A * x + B) % M) % R) / S;
}


int main()
{
    scanf("%llu", &A);
    scanf("%llu", &B);
    scanf("%llu", &M);
    scanf("%llu", &R);
    scanf("%llu", &S);
    Avalanche avalanche[32][32];

    uint32_t testNumber, randNum, initHash, avalancheStep, newHash, bit;
    for(int step = 0; step < 32; step++)
    {
        for(int step2 = 0; step2 < 32; step2++)
        {
            avalanche[step][step2].badTests = 0;
            avalanche[step][step2].testsAmount = 0;
        }
    }


    for(int tests = 0; tests < 100000; tests++)
    {
        randNum = rand();
        //randNum *= 65536;
        testNumber = randNum << 16;
        randNum = rand();
        testNumber += randNum;
        initHash = hashFunc(testNumber);
        for (int step = 0; step < 32; step++)
        {
            bit = 1;
            for (int step2 = 0; step2 < 32; step2++)
            {
                avalanche[step][step2].testsAmount++;
                avalancheStep = testNumber ^ bit;
                newHash = hashFunc(avalancheStep);
                if(newHash >> step2 & bit >> step2 == initHash >> step2 & bit >> step2)
                {
                    avalanche[step][step2].badTests++;
                }
                bit *= 2;
            }
        }
    }


    for (int step = 0; step < 32; step++)
        {
            for (int step2 = 0; step2 < 32; step2++)
            {
                printf("%d ", 100 - (int)round(avalanche[step][step2].badTests * 100.0 / avalanche[step][step2].testsAmount));
            }
            printf("\n");
        }
    return 0;
}