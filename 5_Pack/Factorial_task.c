#include <stdio.h>
#include <math.h>

typedef struct Longnum_s {
    int length;
    int number[3001];
}LongNum;

void factorial_f(LongNum *factorial, int IntMultiplier, int *stepLength)
{
    int step = 0, result_index, multiply_result;
    LongNum result, multiplier;
    multiplier.length = 0;
    do
    {
        multiplier.number[step] = IntMultiplier % 10;
        IntMultiplier /= 10;
        multiplier.length ++;
        step ++;
    } while (IntMultiplier % 10 != 0 || IntMultiplier / 10 > 0);
    result.length = factorial->length + multiplier.length;
    // if (factorial->length < multiplier.length + *stepLength)
    // {
    //     factorial->length += multiplier.length - *stepLength + 1;
    //     *stepLength = multiplier.length;
    // }
    // if (multiplier.length == 1)
    // {
    //     for (int step = 0; step < factorial->length-1; step++)
    //     {
    //         factorial->number[step] *= multiplier.number[0];
    //         factorial->number[step + 1] = (factorial->number[step]/10);
    //         factorial->number[step] %= 10;
    //     }
        
    // }

    for (int step = 0; step < 3001; step++)
    {
        result.number[step] = 0;
    }
    for(int step = 0; step < multiplier.length; ++step)
    {
        for (int step2 = 0; step2 < factorial->length; ++step2)
        {
            result.number[step + step2] += factorial->number[step2] * multiplier.number[step];
            result.number[step + step2 + 1] = result.number[step + step2 + 1] + result.number[step + step2]/10;
            //printf("2: %d\n", factorial->number[step + step2 + 1]);
            result.number[step + step2] %= 10;
            //printf("3: %d\n", factorial->number[step + step2]);
        }
        
    }
    for (int step = 0; step < result.length; ++step)
    {
        factorial->number[step] = result.number[step];
        factorial->length = result.length;
    }
}

int main()
{
    LongNum factorial;
    int factorial_limit;
    
    factorial.length = 1;
    factorial.number[0] = 1;
    
    scanf("%d", &factorial_limit);
    
    if (factorial_limit == 0)
    {
        printf("1");
    }
    else{
        int stepLength = 1;
        for (int step = 1; step <= factorial_limit; ++step)
        {
            factorial_f(&factorial, step, &stepLength);
        }
        
        while (factorial.number[factorial.length - 1] == 0)
        {
            factorial.length --;
        }
        for (int step = factorial.length-1; step >= 0; --step)
        {
            printf("%d",factorial.number[step]);
        }
    }
    return 0;
}