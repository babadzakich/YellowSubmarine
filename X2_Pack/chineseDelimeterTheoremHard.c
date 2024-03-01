#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct LongNum
{
    int length;
    int *digits;
    int sign;
}LongNum;

void LongNumClearNulls(LongNum* num) 
{
    while (num->digits[num->length - 1] == 0 && num->length > 1) num->length--;
}

LongNum LongNumconstruct(char* str)
{
    LongNum number;
    if(str[0] == '-')
    {
        number.sign = -1;
        number.length = strlen(str)-1;
    }
    else
    {
        number.sign = 1;
        number.length = strlen(str);
    }
    number.digits = (int*)calloc(number.length, sizeof(int));
    for(int step = 0; step < number.length; step++)
    {
        number.digits[number.length - step - 1] = str[step] - '0'; 
    }
    return number;
}

LongNum summary(LongNum a, LongNum b)
{
    LongNum c;
    if(a.sign == -1 && b.sign == -1)
    { 
        c.sign = -1;
    }
    else if (a.sign == -1)
    {
        a.sign = 1;
        return substraction(b,a);
    }
    else if (b.sign == -1)
    {
        b.sign = 1;
        return substraction(a,b);
    }
    else
    {
        c.sign = 1;
    }
    

    int temp = 0, Bcnt = 0;
    if(a.length > b.length)
    {
        Bcnt = a.length;
    }
    else{
        Bcnt = b.length;
    }
    
    c.length = Bcnt;
    
    for(int step = 0; step < Bcnt; ++step)
    {
        if (step < b.length && step < a.length)
        {
            c.digits[step] = (a.digits[step] + b.digits[step] + temp) % 10;
            temp = (a.digits[step] + b.digits[step] + temp) / 10;
        }
        else if (step >= b.length && step < a.length)
        {
            c.digits[step] = (a.digits[step] + temp) % 10;
            temp = (a.digits[step] + temp) / 10;
        }
        else if (step < b.length && step >= a.length)
        {
            c.digits[step] = (b.digits[step] + temp) % 10;
            temp = (b.digits[step] + temp) / 10;
        }
    }
    if (temp != 0)
    {
        c.digits[Bcnt] = temp;
        c.length ++;
    }
    LongNumClearNulls(&c);
    return c;
}

LongNum substraction (LongNum a, LongNum b)
{
    LongNum c;
    if(a.sign == 1 && b.sign == -1)
    { 
        b.sign = 1;
        return summary(a, b);
    }
    else if (a.sign == -)
    {
        a.sign = 1;
        return substraction(b,a);
    }
    else if (b.sign == -1)
    {
        b.sign = 1;
        return substraction(a,b);
    }
    else
    {
        c.sign = 1;
    }
}

int main()
{

}