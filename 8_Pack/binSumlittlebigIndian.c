#include <stdio.h>
#include<stdint.h>
#include <stdlib.h>
int32_t reverse(int32_t number)
{
    int32_t result = 0;
    for (int step = 0; step < 4; step++)
    {
        const int32_t temporaryNumber = (number >> (8*step)) & 0xff;
        result |= (temporaryNumber << (24-8*step));
    }
    return result;
    
}
int main()
{
    int flag = 0;
    FILE *in = fopen("input.txt", "rb");
    FILE *out = fopen("output.txt", "wb");
    int32_t summaryResult = 0;
    int32_t amountOfNumbers, currentNumber;
    fread(&amountOfNumbers, sizeof(int32_t), 1, in);
    if (amountOfNumbers > 10000 || amountOfNumbers < 0)
    {
        amountOfNumbers = reverse(amountOfNumbers);
        flag = 1;
        for (int step = 0; step < amountOfNumbers; step++)
        {
            fread(&currentNumber, sizeof(int32_t), 1, in);
            currentNumber = reverse(currentNumber);
            summaryResult += currentNumber;
        }
    }
    else
    {
        for (int step = 0; step < amountOfNumbers; step++)
        {
            fread(&currentNumber, sizeof(int32_t), 1, in);
            summaryResult += currentNumber;
        }
    }
    if (flag)
    {
        summaryResult = reverse(summaryResult);
    }
    fwrite(&summaryResult, sizeof(int32_t), 1, out);
    fclose(in);
    fclose(out);
    return 0;
}