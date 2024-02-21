int nextPrimeFind(int x)
{
    int y = x+1;
    while (1)
    {
        int isPrime = 1;
        for(int step = 2; step *step < y; step++ )
        {
            if (y % step == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) break;
        y++;
    }
    return y;
}

int arr[10000000];
// 1 - not prime, 0 - prime
void resheto()
{
    arr[0] = 1;
    arr[1] = 1;
    for(long long step = 2; step < 10000000; step++)
    {
        if(arr[step] != 1)
        {
            for(long long step2 = 2 * step; step2 < 10000000; step2+=step)
            {
                arr[step2] = 1;
            }
        }
    }
    int chislo = 10000003;
    for(int step = chislo-4; step >= 0; step --)
    {
        if(arr[step])
        {
            arr[step] = chislo;
        }
        else
        {
            arr[step] = chislo;
            chislo = step;
        }
    }
}