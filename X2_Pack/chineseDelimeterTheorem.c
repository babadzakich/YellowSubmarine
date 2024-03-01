#include<stdio.h>
#include<stdlib.h>
#define MOD 1000000007

long long mod(long long x, long long mod) 
{
    return ((x % mod + mod) % mod);
}

int Euclid(long long a, long long b) 
{

    long long x, y, q, r, x1 = 0, x2 = 1, y1 = 1, y2 = 0;

    if (b == 0) 
    {
        return 1;
    }

    x2 = 1, x1 = 0, y2 = 0, y1 = 1;

    while (b > 0)
    {

        q = a / b, r = a - q * b;

        x = x2 - q * x1, y = y2 - q * y1;

        a = b, b = r;

        x2 = x1, x1 = x, y2 = y1, y1 = y;

    }

    x = x2, y = y2;
    return x;

}


int main()
{
    int modulesNumber;
    scanf("%d", &modulesNumber);
    
    long long* modules = (long long*)malloc(sizeof(long long) * modulesNumber);
    long long* remainders = (long long*)malloc(sizeof(long long) * modulesNumber);
    
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
    
    
    long long res = 0;
    for(int step = 0; step < modulesNumber; step++)
    {
        long long delimeter = delimeters / modules[step];
        long long invElem = Euclid(mod(delimeter, modules[step]), modules[step]);
        
        res = mod(res + delimeter * mod(remainders[step] * invElem, modules[step]),delimeters);
    }
    printf("%lld", res);
    free(modules);
    free(remainders);
    return 0;
}