#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

int main()
{
    int amountOfOperations;
    scanf("%d", &amountOfOperations);
    for (int step = 0; step < amountOfOperations; step++)
    {
        double x;
        double resolve = 0;
        int one = -1;
        int64_t fact = 1;
        scanf("%lf", &x);
        for (int step2 = 1; step2 <= 28; step2 += 2)
        {
            fact = step2 == 1 ? 1 : fact * (step2) * (step2-1);
            one *= -1;
            resolve += one * pow(x,step2) / fact;
        }
        printf("%0.15lf\n", resolve);
    }
    return 0;
}