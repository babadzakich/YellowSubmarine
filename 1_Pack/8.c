#include <stdio.h>

int main()
{
    int hours, minutes, seconds, seconds_added;
    scanf("%d %d %d %d", &hours, &minutes, &seconds, &seconds_added);
    seconds += seconds_added;
    minutes += seconds / 60;
    hours += minutes / 60;
    if (minutes >= 60){
        minutes = minutes % 60;
    }
    if(seconds >= 60){
        seconds = seconds % 60;
    }
    if(hours >= 24){
        hours = hours % 24;
    }
    printf("%d %d %d", hours, minutes, seconds);
    return 0;
}
