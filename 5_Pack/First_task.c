#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int year, month, day;
    int hours, minutes, seconds;
} timedate;

int compare(timedate dt1, timedate dt2)
{
    if (dt1.year < dt2.year)
    {
        return 1;
    }
    else if (dt1.year == dt2.year)
    {
        if (dt1.month < dt2.month)
        {
            return 1;
        }
        else if (dt1.month == dt2.month)
        {
            if (dt1.day < dt2.day)
            {
                return 1;
            }   
            else if (dt1.day == dt2.day)
            {
                if (dt1.hours < dt2.hours)
                {
                    return 1;
                }
                else if (dt1.hours == dt2.hours)
                {
                    if (dt1.minutes < dt2.minutes)
                    {
                        return 1;
                    }
                    else if (dt1.minutes == dt2.minutes)
                    {
                        if (dt1.seconds < dt2.seconds)
                        {
                            return 1;
                        }
                        
                    }
                }
            }
        }
    }
    return 0;
}

timedate min(const timedate *arr, int cnt)
{
    timedate m = {100000,100000,1000000,100000,1000000,1000000};
    for (int step = 0; step < cnt; step++)
    {
        if (compare(arr[step], m))
        {
            m = arr[step];
        }
    }
    return m;
}
int main()
{
    int amount_of_dates, y, m, d, h, mn, s;
    timedate tmd;
    scanf("%d", &amount_of_dates);
    timedate* arr = (timedate*)malloc(sizeof(timedate)*amount_of_dates);
    
    
    for (int step = 0; step < amount_of_dates; step++)
    {
        scanf("%d %d %d %d %d %d", &y, &m, &d, &h, &mn, &s);
        timedate tmd ={y, m, d, h, mn, s};
        arr[step] = tmd;
    }
    timedate result = min(arr, amount_of_dates);
    free(arr);
    printf("%d %d %d %d %d %d", result.year, result.month, result.day, result.hours, result.minutes, result.seconds);
    return 0;
}
