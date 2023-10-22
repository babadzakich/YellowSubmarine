#include <stdio.h>
#include <string.h>

int calcLetters(char *iStr, int *oLowerCnt, int *oUpperCnt, int *oDigitsCnt)
{
    int len = 0;
    while (*iStr != '\0' && *iStr != '\n')
    {
        if ((*iStr) >=65 && (*iStr) <= 90)
        {
            ++*oUpperCnt;
            ++len;
        }
        else if ((*iStr) >= 97 && *(iStr) <= 122)
        {
            ++len;
            ++*oLowerCnt;
        }
        else if ((*iStr) >= 48 && (*iStr) <= 57)
        {
            ++*oDigitsCnt;
        }
        iStr ++;
    }
    return len;
}
int main()
{
    int line_number = 0, amount_of_letters = 0;
    char line[100000000], *str;

    while(fgets(line, 400, stdin) != NULL)
    {
        int upper = 0, lower = 0, digits = 0, len = 0;
        len = strlen(line) - 1;  
        amount_of_letters = calcLetters(line, &lower, &upper, &digits);
        printf("Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n", ++line_number, len, amount_of_letters, lower, upper, digits);
    }
    return 0;
}