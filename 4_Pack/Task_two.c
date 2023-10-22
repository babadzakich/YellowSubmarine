#include <stdio.h>
#include <string.h>

void reverse(char *start, int length)
{
    char temp;
    if (length != 1)
    {
        for (int step = 0; step < (length / 2); ++step)
        {
            temp = *(start + step);
            *(start + step) = *(start + length - 1 - step);
            *(start + length - 1 - step) = temp;
        }
    }
}

int main()
{
    int length, amount_of_strings, len[1000],frst = 0, add_index = 0;
    char str[100],res[100000];
    scanf("%d", &amount_of_strings);
    for (int step = 0; step < amount_of_strings; ++step)
    {
        scanf("%s", str);
        length = strlen(str);
        reverse(str, length);
        sprintf((res+add_index), "%s", str);
        len[step] = length;
        add_index += length;
    }
    char strres[100];
    int step3 = 0, step2 = 0, passed_length = 0;
    for (int step = 0; step < add_index; ++step)
    {
        strres[step3++] = res[step];
        length = len[step2];
        if (step+1 == (length + passed_length))
        {
            printf("%s\n", strres);
            memset(strres, '\0', sizeof(strres));
            passed_length += length;
            step2 ++;
            step3 = 0;
        } 
    }
    return 0;
}