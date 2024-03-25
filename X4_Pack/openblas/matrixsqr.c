#include <math.h>
#include "cblas.h"
void MatrixSqr(int n, const double *A, double *R)
{
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, n, n, n, 1, A, n, A, n, 1, R, n);
    for(int step = 0; step < n; step++)
    {
        for(int step2 = 0; step2 < n; step2++)
        {
            double num = R[step * n + step2];
            if(fabs(num) > 0 && fabs(num) < 0.0000000000001)
            {
                R[step * n + step2] = 0;
            }
        }
    }
}