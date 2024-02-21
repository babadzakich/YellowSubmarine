#include "primes.h"

typedef struct primes
{
    int X;
    int amountBefore;
    int amountAfter;
}Primes;


Primes arr[10000000];
// 1 - not prime, 0 - prime
void resheto()
{
    for(long long step = 2; step < 10000000; step += 2) arr[step].X = 0;
    arr[0].X = 1;
    arr[0].amountBefore = 0;
    arr[0].amountAfter =664579; 

    arr[1].X = 1;
    arr[1].amountBefore = 0;
    arr[1].amountAfter = 664579;
    
    for(long long step = 2; step < 10000000; step ++)
    {
        if(arr[step].X != 1)
        {
            for(long long step2 = step * step; step2 <= 10000000; step2+=step)
            {
                arr[step2].X = 1;
            }
        }
    }
    
    int chislo = 10000019;
    for(int step = chislo-20; step >= 0; step --)
    {
        if(arr[step].X)
        {
            arr[step].X = chislo;
        }
        else
        {
            arr[step].X = chislo;
            chislo = step;
        }
    }
    int before = 0, after = 664579;
    for (int step = 2; step < 10000000; step++)
    {
        arr[step].amountBefore = before;
        arr[step].amountAfter = after;
        
        if(arr[step-1].X == step)
        {
            after--;
            before++;
        }
    }
    
}


int isPrime(int x)
{
    if (arr[0].X != 2) resheto();
    if(x == 0) return 0;
    if (arr[x-1].X == x) return 1;
    return 0;
}

int findNextPrime(int x)
{
    if (arr[0].X != 2) resheto();
    if(x == 10000000) return 10000019;
    if (isPrime(x))
    {
        return x;
    }
    return arr[x].X;
}

int getPrimesCount(int l, int r)
{
    if (l == r) return 0;
    if (arr[0].X != 2) resheto();
    return arr[l].amountAfter - arr[r].amountAfter;
}