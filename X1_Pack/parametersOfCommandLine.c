#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define mod(X, Y) ((((X) % (Y))+(Y))%(Y))
//#include <math.h>

int main(int argc, char** argv)
{
    if (argc == 6)
    {
        if (strcmp(argv[1], "-m") == 0)
        {
            long long module = atoll(argv[2]), numberOne = atoll(argv[4]), numberTwo = atoll(argv[5]);
            
            if (strcmp(argv[3], "add") == 0)
            {
                printf("%lld", mod((numberOne + numberTwo), module));
            }
            
            else if(strcmp(argv[3], "sub") == 0)
            {
                printf("%lld", mod((numberOne - numberTwo), module));
            }
            
            else if (strcmp(argv[3], "mul") == 0)
            {
                printf("%lld", mod((mod(numberOne, module) * mod(numberTwo, module)), module));
            }
        }
        
        else if (strcmp(argv[4], "-m") == 0)
        {
            long long module = atoll(argv[5]), numberOne = atoll(argv[2]), numberTwo = atoll(argv[3]);
            
            if (strcmp(argv[1], "add") == 0)
            {
                long long result = mod((numberOne + numberTwo), module);
                printf("%lld", mod((numberOne + numberTwo), module));
            }
            
            else if(strcmp(argv[1], "sub") == 0)
            {
                printf("%lld", mod((numberOne  - numberTwo),module));
            }
            
            else if (strcmp(argv[1], "mul") == 0)
            {
                printf("%lld", mod((mod(numberOne, module) * mod(numberTwo, module)), module));
            }
        }
    }
    else if (argc == 4)
    {
        long long numberOne = atoll(argv[2]), numberTwo = atoll(argv[3]);    
        if (strcmp(argv[1], "add") == 0)
        {
            printf("%lld", numberOne + numberTwo);
        }
        
        else if(strcmp(argv[1], "sub") == 0)
        {
            printf("%lld", numberOne - numberTwo);
        }
        
        else if (strcmp(argv[1], "mul") == 0)
        {
            printf("%lld", numberOne * numberTwo);
        }
    }
    else
    {
        fprintf(stderr, "No parameters specified.");
        return 13;
    }
    return 0;
}