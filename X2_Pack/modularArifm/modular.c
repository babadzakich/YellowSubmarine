#include"modular.h"

int inv(long long a, int module)
    {
        long long result = 1, md = module-2;
        a %= module;
        while (md > 0)
        {
            if (md & 1)
            {
                result = (result * a) % module;
            }
            a = (a * a) % module;

            md >>= 1;
        }
        return result%module;
    }

int MOD;
int pnorm(int x)
{
    return ((x % MOD)+ MOD) % MOD;
}

int padd(int x, int y)
{
    long long res = x + y;
    return ((res % MOD)+ MOD) % MOD;
}

int psub(int x, int y)
{
    long long res = x - y;
    return ((res % MOD)+ MOD) % MOD;
}

int pmul(int x, int y)
{
    long long res = ((long long)x * (long long)y)%MOD;
    return pnorm(res);
}

int pdiv(int x, int y)
{
    int a=1,b=0;
    a = inv(y, MOD);
    long long res = ((long long)x * (long long)a)%MOD;
    return (res%MOD+MOD)%MOD;
}