#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#define replacementChar 0xFFFD

//i delete numbers that are presented in mask leaving only numbers that can be instead of x 
void deletionOfMaskedPart(int *array, int *secondArray, int positionOne, int positionTwo)
{
    for (int step = positionTwo; step < 8; step++)
    {
        array[positionOne + step - positionTwo] = secondArray[step];
    }
}

int zeroPos(int *inputValue)//finding, where the zeroes in number start(11001100 zeropos = 2)
{
    for (int step = 0; step < 8; step++)
    {
        if (inputValue[step] == 0)
        {
            return step;
        }
    }
}

int *binMake(uint8_t number)//transforming number into binary representation
{
    int *array = malloc(sizeof(int) * 8);
    for (int step = 0; step < 8; step++)
    {
        array[7 - step] = (number % 2);
        number >>= 1;
    }
    return array;
}

int *initialize(int size) // creating an array
{
    int *array = (int *)malloc(size * sizeof(int));
    for (int step = 0; step < size; step++)
    {
        array[step] = 0;
    }
    return array;
}

void lightMistakes(int *array, FILE *out, int size)//we locate light mistakes, but if no mistakes occur, we just print number
{
    if (array == NULL)
    {
        return;
    }
    unsigned int temporary = 0;
    for (int step = 0; step < size; step++)
    {
        temporary <<= 1;
        temporary += array[step];
    }

    if (temporary > 0x10FFFF) // more than utf
    {
        temporary = replacementChar;
    }
    if (temporary >= 0xD800 && temporary <= 0xDFFF)//in range of bad interval
    {
        temporary = replacementChar;
    }// next we have check for overlong coding(if we have leading 0`s too much it`s it)
    if (size == 21 && array[0] == 0 && array[1] == 0 && array[2] == 0 && array[3] == 0 && array[4] == 0)
    {
        temporary = replacementChar;
    }
    if (size == 16 && array[0] == 0 && array[1] == 0 && array[2] == 0 && array[3] == 0 && array[4] == 0)
    {
        temporary = replacementChar;
    }
    if (size == 11 && array[0] == 0 && array[1] == 0 && array[2] == 0 && array[3] == 0)
    {
        temporary = replacementChar;
    }

    fwrite(&temporary, sizeof(uint32_t), 1, out);
    free(array);
    }


int main()
{
    FILE* in = fopen("input.txt", "rb");
    FILE* out = fopen("output.txt", "wb");

    uint8_t input;
    int size = 0;
    int position=0;
    int neededBits = 0; // if i have 5 bits i need 6 more for mask k == 2
    int* maskedBinArray = NULL; // array where i store numbers without a mask (01010101 becomes 1010101)

    while(fread(&input, sizeof(uint8_t), 1, in) != 0)
    {
        int* binArray = binMake(input);
        int zeroPosition = zeroPos(binArray);
        if(neededBits != 0)
        {
            if (zeroPosition == 1)
            {
                deletionOfMaskedPart(maskedBinArray, binArray, position, 2);
                position += 6;
                neededBits -= 6;
            }
            else
            {
                fclose(in);
                fclose(out);
                return 0;
            }
        }
        else
        {
            if (zeroPosition == 0)
            {
                lightMistakes(maskedBinArray, out, size);
                size = 7;
                maskedBinArray = initialize(size);
                position = 7;
                deletionOfMaskedPart(maskedBinArray, binArray, 0, 1);
                neededBits = 0;
            }
            else if (zeroPosition == 2)
            {
                lightMistakes(maskedBinArray,out,size);
                size = 11;
                maskedBinArray = initialize(size);
                deletionOfMaskedPart(maskedBinArray, binArray, 0, 3);
                position = 5;
                neededBits = 6;
            }
            else if(zeroPosition == 3)
            {
                lightMistakes(maskedBinArray, out, size);
                size = 16;
                maskedBinArray = initialize(size);
                position = 4;
                deletionOfMaskedPart(maskedBinArray, binArray, 0, 4);
                neededBits = 12;
            }
            else if (zeroPosition == 4)
            {
                lightMistakes(maskedBinArray, out, size);
                size = 21;
                maskedBinArray = initialize(size);
                deletionOfMaskedPart(maskedBinArray, binArray, 0, 5);
                position = 3;
                neededBits = 18;
            }
            else
            {
                lightMistakes(maskedBinArray,out,size);
                fclose(in);
                fclose(out);
                return 0;
            }
        }
        free(binArray);
    }

    if (neededBits == 0 && position != 0)
    {
        lightMistakes(maskedBinArray, out, size);
    }
    fclose(in);
    fclose(out);
    return 0;
}