    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>

    int fastPow(long long a, int module)
    {
        long long result = 1, md = module-2;
        a %= module;
        while (md > 0)
        {
            if (md & 1)
            {
                result = (result * a) % module;
            }
            a = (a * a) % module;

            md >>= 1;
        }
        return result;
    }

    int main()
    {
        int tests, module;
        scanf("%d %d", &tests, &module);
        for (int step = 0; step < tests; step++)
        {
            int a;
            scanf("%d", &a);
            if (a == 0)
            {
                printf("-1\n");
                continue;
            }
            int b = fastPow(a, module);
            printf("%d\n", b);
        }
        return 0;
    }