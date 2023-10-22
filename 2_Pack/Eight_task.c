#include <stdio.h>

int main(){
    int date, month, year, days_passed, step;
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    
    scanf("%d %d %d %d", &date, &month, &year, &days_passed);
    
    date += days_passed;
    step = days[month-1];
    
    while (date > step)
    {
        if (month == 2 )
        { 
            if (year % 400 == 0 || (year % 4 ==0 && year % 100 != 0))
            {
                step = 29;
            }
            else
            {
                step = 28;
            }
        }
        date -= step;
        month++;
        if (month != 12)
        {
            year += month / 12;
            month %= 12;
        }
        step = days[month-1];
    }
    
    printf("%d %d %d",date, month, year);
    return 0;
}