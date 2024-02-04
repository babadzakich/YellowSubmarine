#include <stdio.h>
#include <stdlib.h>
long long binominal[2024][2024];
int main()
{
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    int module, tests;
    fscanf(in, "%d %d", &module, &tests);
    
    binominal[0][0] = 1;
    binominal[1][0] = 1;
    binominal[1][1] = 1;
    for (int step = 2; step < 2024; step++)
    {
        binominal[step][0] = 1;
        binominal[step][step] = 1;
        for (int step2 = 1; step2 < step; step2++)
        {
            binominal[step][step2] = (binominal[step-1][step2-1] + binominal[step-1][step2]) % module;
        }
    }
    for (int step = 0; step < tests; step++)
    {
        int n, k;
        fscanf(in, "%d %d", &n, &k);
        if (k < 0 || k > n)
        {
            fprintf(out, "0\n");
            continue;
        }
        fprintf(out, "%lld\n", binominal[n][k]);
    }
    fclose(in);
    fclose(out);
    return 0;
}