#include <stdio.h>

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a%b)); }

int main()
{
    int tests;
    scanf("%d", &tests);
    for (int step = 0; step < tests; step++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a,b));
    }
    return 0;
}