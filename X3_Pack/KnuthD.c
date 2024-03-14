#include <stdio.h>
#include <stdlib.h>

typedef struct Longnum
{
    int* number;
    int len;
}LongNum;

LongNum AlgorithmD(LongNum u, LongNum v)
{
    //D1
    int d = 9/v.number[v.len-1];

    u.len++;
    u.number = (int*)realloc(u.number, sizeof(int) * u.len);

    if (d == 1)
    {
        u.number[u.len-1] = 0;
    }
    else
    {
        for(int step = 0; step < u.len; step++)
        {
            u.number[step] *= d;
        }
        for(int step = 0; step < u.len-1; step++)
        {
            u.number[step+1] += u.number[step] / 10;
            u.number[step] %= 10;
        }
    }
    for(int step = 0; step < v.len; step++)
    {
        v.number[step] *= d;
    }
    for(int step = 0; step < v.len-1; step++)
    {
        v.number[step+1] += v.number[step] / 10;
        v.number[step] %= 10;
    }
    //D2 - D7
    for(int j = u.len - v.len - 1; j >= 0; j--)
    {
        //D3
        int q = (u.number[j + v.len] * 10 + u.number[j + v.len - 1]) / v.number[v.len-1];
        int r = (u.number[j + v.len] * 10 + u.number[j + v.len - 1]) % v.number[v.len-1];

        do 
        {
            if (q == 10 || q * v.number[v.len - 2] > 10 * r + u.number[j + v.len - 2])
            {
                q--;
                r += v.number[v.len-1];
            }
        }while(r < 10);
        //D4

        LongNum vsub;
        vsub.len = v.len + 1;
        vsub.number = (int*)malloc(sizeof(int) * vsub.len);
        for(int step = 0; step < vsub.len; step++)
        {
            vsub.number[step] = v.number[step] * q;
        }
        for(int step = 0; step < vsub.len-1; step++)
        {
            vsub.number[step+1] += vsub.number[step] / 10;
            vsub.number[step] %= 10;
        }   

        for(int k = j; k <= j + v.len; k++)
        {
            if (u.number[k])
            u.number[k] -= vsub.number[k - j];

        }
    }
}