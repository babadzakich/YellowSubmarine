#include <stdio.h>

double Function(double x);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int amountOfDots;
    scanf("%d", &amountOfDots);
    double delta = 0.0000001;
    for (int step = 0; step < amountOfDots; step++)
    {
        double number;
        scanf("%lf", &number);
        double derivative;
        if (number + delta > 1)
        {
            derivative = (Function(number) - Function(number - delta)) / delta;
        }
        else
        {
            derivative = (Function(number + delta) - Function(number)) / delta;
        }
        printf("%lf\n", derivative);
    }
    return 0;
}