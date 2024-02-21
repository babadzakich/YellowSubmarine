
#include <stdio.h>

typedef struct Factors {
int k; //сколько различных простых в разложении
int primes [32]; //различные простые в порядке возрастания
int powers [32]; //в какие степени надо эти простые возводить
} Factors;

void Factorize(int X, Factors *res);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int amountOfCalls;
    scanf("%d", &amountOfCalls);
    int number;
    for(int step = 0; step < amountOfCalls; step++)
    {
        scanf("%d", &number);
        Factors curr;
        Factorize(number, &curr);
        if (curr.k == 0)
        {
            printf("1 = 1\n");
        }
        else
        {
            printf("%d = ", number);
            for(int step = 0; step < curr.k; step++)
            {
                printf("%d^%d", curr.primes[step], curr.powers[step]);
                if (step + 1 == curr.k)
                {
                    printf("\n");
                }
                else
                {
                    printf(" * ");
                }
            }
        }
    }
    return 0;
}