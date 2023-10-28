#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    FILE* in = fopen("input.txt", "rb");
    FILE* out = fopen("output.txt", "wb");
    int32_t number1;
    int32_t number2;
    fread(&number1, sizeof(int32_t), 1, in);
    fread(&number2, sizeof(int32_t), 1, in);
    int64_t number3 = (int64_t)number1 + (int64_t)number2;
    if((number3 < 0) && (number3 % 2 != 0))
    {
        number3 = number3 / 2 - 1;
    }
    else
    {
        number3 /= 2;
    }
    int32_t result = number3;   
    fwrite(&result, sizeof(int32_t), 1, out);
    fclose(in);
    fclose(out);
    return 0;
}