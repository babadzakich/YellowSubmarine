#include <stdio.h>

void printTime(int hours, int minutes, int seconds)
{
    printf("%02d:%02d:%02d\n", hours, minutes, seconds);
}

int main()
{
    int amount_of_times, hours[1001], minutes[1001], seconds[1001];
    scanf("%d", &amount_of_times);
    int hour, minute, second;
    for(int step = 0; step < amount_of_times; ++step)
    {
        scanf("%d %d %d", &hour, &minute, &second);
        hours[step] = hour;
        minutes[step] = minute;
        seconds[step] = second;
    }
    for (int step = 0; step < amount_of_times; ++step)
    {
        printTime(hours[step], minutes[step], seconds[step]);
    }
    return 0;
}