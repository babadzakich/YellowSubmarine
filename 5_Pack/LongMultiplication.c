#include <stdio.h>
#include <string.h>

typedef struct Longnum_s {
    int length;
    int number[5001];
}LongNum;

LongNum transform(char *stringNumber)
{
    LongNum LongNumber;
    LongNumber.length = strlen(stringNumber);
    for (int step = LongNumber.length - 1; step >= 0; step--)
    {
        LongNumber.number[LongNumber.length - step - 1] = stringNumber[step] - '0';
    }
    return LongNumber;
}

LongNum multiplication(LongNum firstMultiplier, LongNum secondMultiplier)
{
    LongNum result;
    result.length = firstMultiplier.length + secondMultiplier.length;

    for (int step = 0; step < result.length; step++)
    {
        result.number[step] = 0;
    }

    for(int step = 0; step < secondMultiplier.length; ++step)
    {
        for (int step2 = 0; step2 < firstMultiplier.length; ++step2)
        {
            result.number[step + step2] += firstMultiplier.number[step2] * secondMultiplier.number[step];
            result.number[step + step2 + 1] = result.number[step + step2 + 1] + result.number[step + step2]/10;
            result.number[step + step2] %= 10;
        }
    }
    return result;
}

int main()
{
    LongNum LNfirstMultiplier, LNsecondMultiplier, result;
    char firstMultiplier[1001], secondMultiplier[1001];
    scanf("%s\n", firstMultiplier);
    scanf("%s", secondMultiplier);
    LNfirstMultiplier = transform(firstMultiplier);
    LNsecondMultiplier = transform(secondMultiplier);
    result = multiplication(LNfirstMultiplier, LNsecondMultiplier);
    while(result.number[result.length-1] == 0)
    {
        result.length --;
    }
    for (int step = result.length-1; step >= 0; --step)
    {
        printf("%d", result.number[step]);
    }
}