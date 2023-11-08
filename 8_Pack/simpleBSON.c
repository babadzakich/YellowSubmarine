#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define doubleOperation 1
#define stringOperation 2
#define boolOperation 8
#define nullOperation 10
#define int32Operation 16
#define int64Operation 18

int main()
{
    FILE *in = fopen("input.txt","rb");
    FILE *out = fopen("output.txt","w");
    int sizeOfFile;
    fread(&sizeOfFile, sizeof(int), 1, in);
    sizeOfFile -= sizeof(int);
    
    fprintf(out, "{\n");

    while (sizeOfFile > 1)
    {
        unsigned char operationByte = 0;
        fread(&operationByte, sizeof(unsigned char), 1, in);
        sizeOfFile -= sizeof(unsigned char);
        
        char currentByte;
        fprintf(out, "    \"");
        do 
        {
            
            fread(&currentByte, sizeof(char), 1, in);
            sizeOfFile -= sizeof(char);
            if (currentByte != 0)
            {
                fprintf(out, "%c", currentByte);
            }
            
        }while (currentByte != 0);
        fprintf(out, "\": ");

        if (operationByte == doubleOperation)
        {
            double doubleValue;
            fread(&doubleValue, sizeof(double), 1, in);
            fprintf(out, "%0.15g", doubleValue);
            sizeOfFile -= sizeof(double);
        }
        
        else if (operationByte == stringOperation)
        {
            int32_t sizeOfString;
            fread(&sizeOfString, sizeof(int32_t), 1, in);
            sizeOfFile -= sizeof(int32_t);
            
            char stringSymbol[sizeOfString];
            fread(&stringSymbol, sizeof(stringSymbol), 1, in);
            sizeOfFile -= sizeof(stringSymbol);
            fprintf(out, "\"%s\"", stringSymbol);
        }

        else if (operationByte == boolOperation)
        {
            char boolByte;
            fread(&boolByte, sizeof(unsigned char), 1, in);
            sizeOfFile -= sizeof(unsigned char);
            if (boolByte == 1)
            {
                fprintf(out, "true");
            }
            else
            {
                fprintf(out, "false");
            }
        }

        else if (operationByte == nullOperation)
        {
            fprintf(out, "null");
        }

        else if (operationByte == int32Operation)
        {
            int32_t intValue;
            fread(&intValue, sizeof(int32_t), 1, in);
            sizeOfFile -= sizeof(int32_t);
            fprintf(out, "%d", intValue);
        }

        else if (operationByte == int64Operation)
        {
            int64_t llValue;
            fread(&llValue, sizeof(int64_t), 1, in);
            sizeOfFile -= sizeof(int64_t);
            fprintf(out, "%lld", llValue);
        }

        
        if(sizeOfFile > 1)
        {
            fprintf(out, ",");
        }
        fprintf(out, "\n");
    }
    fprintf(out, "}");
    fclose(in);
    fclose(out);
    return 0;
}