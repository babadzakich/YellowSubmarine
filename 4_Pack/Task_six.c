#include <stdio.h>
#include <string.h>
#include <math.h>

int readTime(char *iStr, int *oHours, int *oMinutes, int *oSeconds)
{
    if (iStr[1] == '|' || iStr[2] == '|')
    {
        return 0;
    }
    else
    {
        sscanf(iStr, "%d:%d:%d", oHours, oMinutes, oSeconds);
        if (*oHours >= 0 && *oHours <= 23 && *oMinutes >= 0 && *oMinutes <= 59 && *oSeconds >= 0 && *oSeconds <= 59)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{

    int hours = 0, minutes = 0, seconds = 0;
    char time[15];
    scanf("%s", time);
    if (readTime(time, &hours, &minutes, &seconds) == 0)
    {
        printf("0 -1 -1 -1\n");
        printf("0 -1 -1\n");
        printf("0 -1\n");
    }
    else
    {
        printf("1 %d %d %d\n", hours, minutes, seconds);
        printf("1 %d %d\n", hours, minutes);
        printf("1 %d\n", hours);
    }

    return 0;
}
