#include <stdio.h>
//int prime[15000000], numbers[500000];
int main()
{
    int amount_of_numbers, diapazon, number;
    scanf("%d %d", &diapazon, &amount_of_numbers);
    int prime[diapazon], numbers[amount_of_numbers];
    for (int step = 0; step < diapazon; step ++)
    {
        prime[step] = 1;
    }
    for (int step = 0; step < amount_of_numbers; step++)
    {
        scanf("%d", &number);
        numbers[step] = number;
    }
    prime[0] = 0;
    prime[1] = 0;

    for (int step = 2; step <= diapazon; ++step)
    {
        if (prime[step] == 1)
        {
            for (int step2 = step*2; step2 <= diapazon; step2 += step)
            {
                prime[step2] = 0;
            }
        }
    }
    for (int step = 0; step < amount_of_numbers; ++step)
    {
        if (prime[numbers[step]])
        {
            printf("%d prime\n", numbers[step]);
        }
        else
        {
            printf("%d not\n", numbers[step]);
        }
    }
    return 0;
}