

typedef struct Factors 
{
    int k; 
    int primes [32];
    int powers [32];
} Factors;

void Factorize(int X, Factors *res)
{
    res->k = 0;
    int x = X;
    for(int step = 2; step * step <= X; step++)
    {
        if (X%step == 0)
        {
            res->primes[res->k] = step;
            res->powers[res->k] = 0;
            while(X % step == 0)
            {
                res->powers[res->k]++; 
                X /= step;
            }
            res->k++;
        }
    }
    if (X != 1)
    {
        res->primes[res->k] = X;
        res->powers[res->k] = 1;
        res->k++;
    }
}