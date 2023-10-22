#include <stdio.h>
typedef struct LongNum_s{
    int len;
    int arr[500];
} LongNum;

LongNum sum(LongNum a, LongNum b)
{
    int temp = 0, Bcnt = 0;
    if(a.len > b.len)
    {
        Bcnt = a.len;
    }
    else{
        Bcnt = b.len;
    }
    LongNum c;
    c.len = Bcnt;
    
    for(int step = 0; step < Bcnt; ++step)
    {
        if (step < b.len && step < a.len)
        {
            c.arr[step] = (a.arr[step] + b.arr[step] + temp) % 10;
            temp = (a.arr[step] + b.arr[step] + temp) / 10;
        }
        else if (step >= b.len && step < a.len)
        {
            c.arr[step] = (a.arr[step] + temp) % 10;
            temp = (a.arr[step] + temp) / 10;
        }
        else if (step < b.len && step >= a.len)
        {
            c.arr[step] = (b.arr[step] + temp) % 10;
            temp = (b.arr[step] + temp) / 10;
        }
    }
    if (temp != 0)
    {
        c.arr[Bcnt] = temp;
        c.len ++;
    }
    return c;
}

LongNum fib (LongNum a, LongNum b, int n)
{
    if (n <= 2)
    {
        return b;
    }
    else 
    {
        return fib(b, sum(a, b), (n-1));
    }
}

int main()
{
    LongNum number1, number2,result;
    int number;
    number1.arr[0] = 1;
    number1.len = 1;
    number2.arr[0] = 1;
    number2.len = 1;
    scanf("%d", &number);
    result = fib(number1, number2, number);
    for (int step = result.len-1; step >= 0; --step)
    {
        printf("%d", result.arr[step]);
    }
    // scanf("%d", &number);
    // number = fib(number1.arr, number2.arr, number);
    // printf("%d", number);
    return 0;
}