#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

int main()
{
    FILE *in = fopen("input.txt","rb");
    FILE *out = fopen("output.txt","wb");
    int32_t amountOfWords;
    fread(&amountOfWords, sizeof(int32_t), 1, in);
    int16_t* wordsArray[amountOfWords];
    for (int word = 0; word < amountOfWords; word++)
    {
        int32_t amountOfBits;
        fread(&amountOfBits, sizeof(int32_t), 1, in);
        wordsArray[word] = (int16_t*)malloc(sizeof(int16_t) * amountOfBits);
        for (int step = 0; step < amountOfBits; step++)
        {
            uint8_t letter;
            fread(&letter, sizeof(uint8_t), 1, in);
        }
    }
    int32_t lengthOfText;
    fread(&lengthOfText, sizeof(int32_t), 1, in);
    int16_t bitwordArray[8];
    
    for (int step = 0; step < lengthOfText; step++)
    {
        uint8_t result = 0;
        int16_t word;
        fread(&word, sizeof(int16_t), 1, in);
        int32_t length = _msize(wordsArray[word])/sizeof(int16_t);
        for (int step2 = 0; step2 < length; step2++)
        {
            if (step2 != 0 && step2 % 8 == 0)
            {
                fwrite(&result, sizeof(uint8_t), 1, out);
                result = 0;
            }
            else
            {
                result <<= 1;
                result += wordsArray[word][step2];
            }
        }
    }

    if (result != 0)
    {
        fwrite(&result, sizeof(uint8_t), 1, out);
    }
    for (int step = 0; step < amountOfWords; step++)
    {
        free(wordsArray[step]);
    }
    fclose(in);
    fclose(out);
    return 0;
}