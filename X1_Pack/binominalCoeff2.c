#include <stdio.h>

#define Module 1000000007
long long factorials[1000001];

int fastPow(long long a)
{
    long long result = 1, md = Module-2;
    a %= Module;
    while (md > 0)
    {
        if (md & 1)
        {
            result = (result * a) % Module;
        }
        a = (a * a) % Module;

        md >>= 1;
    }
    return result;
}

int main()
{
    int tests;
    scanf("%d", &tests);
 
    factorials[0] = 1;
    for(int step = 1; step < 1000001; step++)
    {
        factorials[step] = (step * factorials[step-1]) % Module;
    }
    
    for (int step = 0; step < tests; step++)
    {
        int k, n;
        scanf("%d %d", &n, &k);
        printf("%lld\n", (factorials[n]*fastPow(factorials[k] * factorials[n-k]))%Module);
    }
    return 0;
}