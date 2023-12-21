#include <stdio.h>
#include <stdlib.h>

int main()
{
    int amountOfCountings;
    scanf("%d", &amountOfCountings);
    for (int step = 0; step < amountOfCountings; step++)
    {
        double summer = 1;
        double sum = 1;
        double number;
        scanf("%lf", &number);
        if (number < 0)
        {
            number *= -1;
            for(int step2 = 1; (summer != 0); step2++)
            {
                summer *= number/step2;
                sum += summer;
            }
            sum = 1/sum;
        }
        else
        {
            for(int step2 = 1; (summer != 0); step2++)
            {
                summer *= number/step2;
                sum += summer;
            }
        }
        printf("%0.15g\n", sum);
    }
    return 0;
}