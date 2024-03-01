int fPow(int num, int power, int module);

int test_MR (int p)
{
    int a = 2;
    if(!(p%2))
    {
        return 0;
    }
    int counter = 0, power = p - 1;
    while(!(power%2))
    {
        power /= 2;
        counter ++;
    }
    a = fpow(2, power, p);
    if(a%p) return 1;
    for(int step = 0; step < counter; step++)
    {
        a *= a;
        a %= p;
    }
    if (a % p == (p - 1)) return 1;
    return 0;
}