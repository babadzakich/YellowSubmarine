#include <stdio.h>
#include <stdlib.h>
#define mod 1000000007
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
int memo[1001][1001];
int num;

int rec(int Sum, int Last)                                  // числа Sum и Last передаём в рекурсию
{
    long long res;
    if (memo[Sum][Last] == -1)
    {
        res = 0;
        if (Sum == num)
        {
            res = 1;
        }
        else
        {
            for (int x = 1; x <=MIN(Last, num-Sum); x++)               // перебираем все допустимые x
            {
                res = (res + rec(Sum+x, x)) % mod;
            }
        }
        memo[Sum][Last] = (int)(res % mod);
    }                                    // просто прибавляем 1 к глобальному счётчику
    return memo[Sum][Last];
}

int main(void)
{
    scanf("%d", &num);
    for(int step = 0; step <= num; step++)
    {
        for(int step2 = 0; step2 <= num; step2++)
        {
            memo[step][step2] = -1;
        }
    }
    printf("%d", rec(0, num));
    return 0;
}