#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    int amountOfMasks;
    scanf("%d", &amountOfMasks);
    uint64_t* masks = (uint64_t*)malloc(sizeof(uint64_t)*amountOfMasks);
    for (int step = 0; step < amountOfMasks; step++)
    {
        
        scanf("%llx", &masks[step]);
        //printf("%llx ", masks[step]);
    }
    int counter = 0;
    for (int step = 0; step < amountOfMasks-1;step++)
    {
        for (int step2 = step+1; step2 < amountOfMasks; step2++)
        {
            if ((masks[step] & masks[step2]) == 0)
            {
                counter++;
            }
        }
        
    }
    printf("%d", counter);
    return 0;
}