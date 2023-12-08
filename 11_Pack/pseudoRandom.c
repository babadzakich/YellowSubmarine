#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t func(uint64_t s, uint64_t a, uint64_t b, uint64_t c, uint64_t M)
{
    return ( s * s * a + s * b + c ) % M ;
}

int main()
{
    int a, b, c, M;
    scanf("%d", &M);
    scanf("%d %d %d", &a, &b, &c);
    int state = 1;
    int* array = (int*)malloc(sizeof(int)* 2 * 1000001);
    for(int step = 0; step < 2000002; step++)
    {
        array[step] = 0;
    }   
    int head = -1, tail = -1;
    while (tail < 0)
    {
        int hash = func(state, a, b, c, M);
    }
    return 0;
}