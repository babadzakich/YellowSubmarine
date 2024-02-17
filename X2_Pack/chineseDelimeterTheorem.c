#include<stdio.h>
#include<stdlib.h>

long long bpow(long long x, long long y)
{
    long long res = 1;
    while (y)
    {
        if (y & 1)
        {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}

long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a%b)); }

long long lcm(long long a, long long b)
{
    long long delimeter = gcd(a,b);
    long long koef = a / delimeter;
    return b*koef;
}

long long phi(long long x)
{
    long long res = 1;
    for(long long step = 2; step*step <= x; step++)
    {
        if (!(x%step)) 
        {
            res *= step-1;
            x /= step;
            while(!(x%step))
            {
                res *= step;
                x /= step;
            }
        }
    }
    if (x != 1) res *= (x-1);
    return res;
}


int Euclid(int a, int b, int* x, int* y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int gcd = Euclid(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}


int main()
{
    int modulesNumber;
    scanf("%d", &modulesNumber);
    
    long long* modules = (long long*)malloc(sizeof(long long) * modulesNumber);
    long long* remainders = (long long*)malloc(sizeof(long long) * modulesNumber);
    long long* solve = (long long*)malloc(sizeof(long long) * modulesNumber);
    
    long long delimeters = 1;
    for(int step = 0; step < modulesNumber; step++)
    {
        scanf("%lld", &modules[step]);
        delimeters *= modules[step];
    }
    
    for(int step = 0; step < modulesNumber; step++)
    {
        scanf("%lld", &remainders[step]);
    } 
    
    for(int step = 0; step < modulesNumber; step++)
    {
        solve[step] = delimeters / modules[step];
    }
    
    long long res = 0;
    for(int step = 0; step < modulesNumber; step++)
    {
        int x = 1, y = 0;
        Euclid(solve[step],modules[step], &x, &y);
        x = (x % modules[step] + modules[step]) % modules[step]; 
        res += (solve[step]*remainders[step] * (long long)x);
        res %= delimeters;
    }
    printf("%lld", res);
    return 0;
}