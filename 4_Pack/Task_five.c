#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int length(char* string)
{
    int step = 0, len = 0;
    while (string[step] != '\0')
    {
        step ++;
        len ++;
    }
    return len;
}

int counter(char *str, int length)
{
    int upper_counter = 0;
    for (int step = 0; step < length; ++step)
    {
        if(str[step] >= 'A' && str[step] <= 'Z')
        {
            ++upper_counter;
        }
    }
    return upper_counter;
}

int main()
{
    int flag = 0, step2 = 0;
    char line[1000001], res[100001];
    scanf("%s", line);
    int len = length(line);
    for (int step = 0; step < len; ++step)
    {
        if (line[step] != '.' && line[step] != ';' && line[step] != ',' && line[step] != ':')
        {
            flag = 1;
            res[step2++] = line[step];
        }
        else 
        {
            if (flag)
            {
                int upper = counter(res, step2);
                printf("%d/%d ", upper, step2);
                printf("%s\n", res);
                // memset(res, '\0', strlen(res));
                for (int i = 0; i < step2; ++i)
                {
                    res[i] = '\0';
                }
                step2 = 0;
            }
            flag = 0;
        }
    }
    if (flag)
    {
        int upper = counter(res, step2);
        printf("%d/%d ", upper, step2);
        printf("%s\n", res);
    }
    return 0;
}   