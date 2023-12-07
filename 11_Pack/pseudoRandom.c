#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t func(uint64_t s, uint64_t a, uint64_t b, uint64_t c, uint64_t M)
{
    return ( s * s * a + s * b + c ) % M ;
}

int main()
{
    
    return 0;
}