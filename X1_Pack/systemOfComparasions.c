#include <stdio.h>
#include <stdlib.h>
#define Mod 1000000007

long long inv(long long a, int module)
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
    return result;
}

long long inv2(long long a, int module)
{
    if (module == 0) return 1;
    long long result = 1;
    a %= Mod;
    while (module > 0)
    {
        if (module & 1)
        {
            result = (result * a) % Mod;
        }
        a = (a * a) % Mod;

        module >>= 1;
    }
    return result;
}


int main()
{
    
    long long variables, equations, module;
    scanf("%lld %lld %lld", &variables, &equations, &module);

    long long ** matrix = (long long **)malloc(sizeof(long long*) * equations);
    for(int step = 0; step < equations; step++)
    {
        matrix[step] = (long long*)malloc(sizeof(long long)*(variables+1));
        for (int step2 = 0; step2 <= variables; step2++)
        {
            scanf("%lld", &matrix[step][step2]);
        }
    }
    
    int currColl = 0;
    for (int step = 0; step < equations; step++)
    {
        if (matrix[step][currColl] == 0)
        {
            for (int step2 = step+1; step2 < equations; step2++)
            {
                    if (matrix[step2][currColl] != 0)
                    {
                        long long* temp = matrix[step];
                        matrix[step] = matrix[step2];
                        matrix[step2] = temp;
                    }
                    
            }
        }

        if(matrix[step][currColl] == 0)
        {
            step--;
            currColl++;
            if (currColl >= variables + 1)  break;
            continue;
        }

        for (int step2 = 0; step2 < equations; step2++)
        {
            if(step2 == step) continue;
            long long coef = (matrix[step2][currColl] * inv(matrix[step][currColl], module))%module;
            for (int step3 = 0; step3 <= variables; step3++)
            {
                matrix[step2][step3] = (matrix[step2][step3] - ((matrix[step][step3] * coef)%module) + module*2) % module;
            }
        }
        currColl++;
        if (currColl >= variables + 1) break;
    }

    int start = 0, end = equations - 1;
    while (start <= end)
    {
        int bublik = 0;
        for(int step = 0; step < variables; step++)
        {
            if(matrix[start][step] != 0) bublik = 1; 
        }

        if (!bublik)
        {
            long long* temp = matrix[end];
            matrix[end] = matrix[start];
            matrix[start] = temp;
            end--;
        }
        else start ++;
    }

    int nullstr = end + 1;

    for(int step = nullstr; step < equations; step++)
    {
        if(matrix[step][variables] != 0)
        {
            printf("0");
            return 0;
        }
    }

    long long solves = 1;
    if (nullstr != equations) 
    {
        solves = inv2(module, variables - nullstr);
    }
    if (solves != 1) 
    {
        printf("%lld", inv2(module, variables - nullstr));
    }
    else
    {
        printf("1\n");
        for(int step = 0; step < variables; step++) 
        {
            long long res = (inv(matrix[step][step], module) * matrix[step][variables])%module;
            printf("%lld\n", res);
        }
    }
    for(int step = 0; step < equations; step++)
    {
        free(matrix[step]);
    }
    free(matrix);
    return 0;
}