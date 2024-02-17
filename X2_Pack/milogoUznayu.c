#include<stdio.h>
int main()
{
    #if defined(__clang__)
        printf("Compiler: clang\n");
    #elif defined(__TINYC__)
        printf("Compiler: TCC\n");
    #elif defined(__GNUC__) && !defined(__clang__)
        printf("Compiler: GCC\n");
    #endif

    #if defined(__x86_64__) || defined(_M_X64)
        printf("Bitness: 64\n");
    #else
        printf("Bitness: 32\n");
    #endif

    #ifdef NDEBUG
        printf("Asserts: disabled\n");
    #else
        printf("Asserts: enabled\n");
    #endif
    return 0;
}