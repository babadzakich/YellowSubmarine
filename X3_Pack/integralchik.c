#include <stdio.h>
#include <math.h>

typedef struct func{
    double c0;
    double c1;
    double c2;
    double c3;
}Func;

double function(Func x, Func y, Func z, double t, double l)
{
    double res = 0, temp = 0; 
    temp = pow(x.c1 + 2 * x.c2 * (t - l) + 3 * x.c3 * (t-l) * (t-l),2); 
    res += temp;
    
    temp = pow(y.c1 + 2 * y.c2 * (t - l) + 3 * y.c3 * (t-l) * (t-l),2);
    res += temp;

    temp = pow(z.c1 + 2 * z.c2 * (t - l) + 3 * z.c3 * (t-l) * (t-l), 2); 
    res += temp;
    return sqrt(res);
}

int main(void)
{
    int tests;
    scanf("%d", &tests);
    double simpson = 0;
    Func x, y, z;
    for (int step = 0; step < tests; step++)
    {
        double l,r;
        
        scanf("%lf %lf", &l, &r);
        scanf("%lf %lf %lf %lf", &x.c0, &x.c1, &x.c2, &x.c3);
        scanf("%lf %lf %lf %lf", &y.c0, &y.c1, &y.c2, &y.c3);
        scanf("%lf %lf %lf %lf", &z.c0, &z.c1, &z.c2, &z.c3);
        
        double leap = (r - l) / 150;
        for(int step = 0; step < 150; step++)
        {
            double a = step * leap + l, b = (step+1) * leap + l;
            simpson += (function(x,y,z, a, l) + 4 * function(x,y,z,(a+b)/2,l) + function(x,y,z,b,l)) * (b - a) / 6;
        }
    }
    printf("%.20f", simpson);
    return 0;
}

