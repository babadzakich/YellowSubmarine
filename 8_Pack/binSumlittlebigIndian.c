#include <stdio.h>
#include<stdint.h>
#include <stdlib.h>
int32_t reverse(int32_t number)
{
    int32_t result = 0;
    for (int32_t step = 0; step < 4; step++)
    {
        int32_t temporaryNumber = (number >> (8*step)) & 0xff;
        result |= number << (24-8*step);
    }
    return result;
    
}
int main()
{
    FILE *in = fopen("input.txt", "rb");
    FILE *out = fopen("output.txt", "wb");
    int32_t summaryResult = 0;
    int32_t amountOfNumbers, currentNumber;
    fread(&amountOfNumbers, sizeof(int32_t), 1, in);
    fread(&currentNumber, sizeof(int32_t), 1, in);
    if (currentNumber > 10000 || currentNumber < 0)
    {
        currentNumber = reverse(currentNumber);
        summaryResult += currentNumber;
        for (int step = 1; step < amountOfNumbers; step++)
        {
            fread(&currentNumber, sizeof(int32_t), 1, in);
            currentNumber = reverse(currentNumber);
            summaryResult += currentNumber;
        }
    }
    else
    {
        summaryResult += currentNumber;
        for (int step = 1; step < amountOfNumbers; step++)
        {
            fread(&currentNumber, sizeof(int32_t), 1, in);
            summaryResult += currentNumber;
        }
    }
    fwrite(&summaryResult, sizeof(int32_t), 1, out);
    fclose(in);
    fclose(out);
    return 0;
}