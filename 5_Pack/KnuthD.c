#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Longnum
{
    long long number[100];
    int len;
}LongNum;

LongNum shortDivision(LongNum* u, LongNum* v)
{
    long long b = 1000000000;
    long long divider = v->number[0];
    LongNum res;
    res.len = 0;
    long long currNum = 0;
    int step = u->len - 1;
    while (step >= 0)
    {
        currNum = currNum * b + u->number[step];
        res.number[res.len++] = currNum / divider;
        currNum %= divider;
        step--;
    } 
    return res;
}

LongNum AlgorithmD(LongNum* u, LongNum* v)
{
    //D1
    int iterator = u->len - v->len;
    long long b = 1000000000;
    long long d = b / (v->number[v->len - 1] + 1);
    u->len++;

    if (d == 1)
    {
        u->number[u->len - 1] = 0;
    }
    else
    {
        for(int step = 0; step < u->len; step++)
        {
            u->number[step] *= d;
        }
        for(int step = 0; step < u->len - 1; step++)
        {
            u->number[step+1] += u->number[step] / b;
            u->number[step] %= b;
        }
    }
    for(int step = 0; step < v->len; step++)
    {
        v->number[step] *= d;
    }
    for(int step = 0; step < v->len-1; step++)
    {
        v->number[step+1] += v->number[step] / b;
        v->number[step] %= b;
    }
    // v->number[v->len - 1] %= b;

    LongNum quotient;
    LongNum vsub;
    quotient.len = iterator + 1;
    
    //D2 - D7
    for(int j = 0; j <= iterator; j++)
    {
        //D3
        long long q = 0;
        if (u->number[u->len - 1 - j] == v->number[v->len - 1])
        {
            q = b - 1;
        }
        else
        {
            long long num1 = u->number[u->len - j - 1] * b, num2 = u->number[u->len - j - 2], num3 = v->number[v->len - 1];
            q = (num1 + num2) / num3;
        }
    
        if (v->number[v->len - 2] * q > (u->number[u->len - j - 1] * b + u->number[u->len - j - 2] - q * v->number[v->len - 1]) * b + u->number[u->len - j - 3])
        {
            q--;

            if (v->number[v->len - 2] * q > (u->number[u->len - j - 1] * b + u->number[u->len - j - 2] - q * v->number[v->len - 1]) * b + u->number[u->len - j - 3])
            {
                q--;
            }
        }
        //D4
        int minusFlag = 0;
        vsub.len = v->len + 1;
        for(int step = 0; step < v->len; step++)
        {
            vsub.number[step] = v->number[step] * q;
        }
        for(int step = 0; step < vsub.len - 1; step++)
        {
            vsub.number[step+1] += vsub.number[step] / b;
            vsub.number[step] %= b;
        }   

        for(int k = u->len - j - vsub.len; k < u->len - j; k++)
        {
            u->number[k] -= vsub.number[k - u->len  + j + vsub.len];
        }
        for(int k = u->len - j - vsub.len; k < u->len - j - 1; k++)
        {
            if (u->number[k] < 0)
            {
                u->number[k] += b;
                u->number[k+1] --;
            }
        }
        if (u->number[u->len - j - 1] < 0)
        {
            u->number[v->len + 1] += 1;
            if (u->number[v->len + 1] > b - 1)
            {
                u->number[v->len + 2] += u->number[v->len + 1] / b;
                u->number[v->len + 1] %= b; 
            }
            minusFlag = 1;
        }
        memset(vsub.number, 0, sizeof(vsub.number));
        //D6
        if(minusFlag)
        {
            q--;
            for(int step = u->len - 1 - v->len - j; step < u->len - j - 1; step++)
            {
                u->number[step] += v->number[step - (u->len - 1 - v->len - j)];
                u->number[step + 1] += u->number[step] / b;
                u->number[step] %= b;
            }
        }
        quotient.number[j] = q;
    }
    return quotient;
}


int main()
{
    char buffer[1000001];
    char temp[10];
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%s", buffer);
    LongNum delimoe;
    int len = strlen(buffer);
    delimoe.len = 0;   
    if(len <= 9)
    {
        delimoe.number[delimoe.len++] = atoll(buffer);
    }
    else
    {
        for(int step = len - 1; step >= 0; step -= 9)
        {
            for(int step2 = 0; step2 < 9; step2++)
            {
                if(step - 8 + step2 >= 0)temp[step2] = buffer[step - 8 + step2];
            }
            char* srez = temp;
            while(srez[0] == '\0') 
            {
                srez++;
            }
            delimoe.number[delimoe.len++] = atoll(srez);
            memset(temp, '\0', sizeof(temp));
        }
    }
    memset(buffer, '\0', sizeof(buffer));
    
    scanf("%s", buffer);
    len = strlen(buffer);
    LongNum delitel;
    delitel.len = 0; 
    if(len <= 9)
    {
        delitel.number[delitel.len++] = atoll(buffer);
    }
    else
    { 
        for(int step = len - 1; step >= 0; step -= 9)
        {
            for(int step2 = 0; step2 < 9; step2++)
            {
                if(step - 8 + step2 >= 0)temp[step2] = buffer[step - 8 + step2];
            }
            char* srez = temp;
            while(srez[0] == '\0') 
            {
                srez++;
            }
            delitel.number[delitel.len++] = atoll(srez);
            memset(temp, '\0', sizeof(temp));
        }
    }

    int dividerState = 0;
    if(delimoe.len < delitel.len)
    {
        dividerState = 1;
    }
    else if (delimoe.len == delitel.len)
    {
        for(int step = delitel.len - 1; step >= 0; step--)
        {
            if (delitel.number[step] < delimoe.number[step])
            {
                break;
            }
            else if(delitel.number[step] > delimoe.number[step])
            {
                dividerState = 1;
                break;
            }
            if (step == 0)
            {
                dividerState = 2;
            }
        }
    }

    LongNum result;

    switch (dividerState)
    {
    case 2:
        printf("1");
        break;
    
    case 1:
        printf("0");
        break;
    default:
        if (delitel.len > 1) 
        {
            result = AlgorithmD(&delimoe, &delitel);
        }
        else 
        {
            result = shortDivision(&delimoe, &delitel);
        }
        int step = 0;
        while (result.number[step] == 0) step++;
        int dia = step;
        for (step; step < result.len; step++)
        {
            if (step == dia)
            {
                printf("%lld", result.number[step]);
                continue;
            }
            printf("%09lld", result.number[step]);
        }
        break;
    }
    return 0;
}