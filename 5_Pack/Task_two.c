#include <stdio.h>
double binominal[1052][1052];
double binom(int row, int pos)
{
    binominal[0][0] = 1;
    binominal[1][0] = 1;
    binominal[1][1] = 1;
    for (int step = 2; step<=row; step++)
    {
        binominal[step][0] = 1;
        binominal[step][step] = 1;
        for (int step2 = 1; step2 < step; step2++)
        {
            binominal[step][step2] = binominal[step-1][step2-1] + binominal[step-1][step2];
            //printf("%0.10g", binominal[step][step2] );
        }
    }
    return binominal[row][pos];
}
int main()
{
    
    
    int row, pos, amount_of_numbers;
    scanf("%d", &amount_of_numbers);
    for (int step = 0; step < amount_of_numbers; ++step)
    {
        scanf("%d %d", &row, &pos);
        printf("%0.10g\n", binom(row, pos));
    }
    return 0;
}