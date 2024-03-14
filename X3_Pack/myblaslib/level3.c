#include "myblas.h"
//вычислить матрицу (alpha*A*B + beta*C) и записать её в C
//здесь A –- матрица размера m на k, B –- матрица размера k на n,
// C –- матрица размера m на n
void dgemm(
int m, int n, int k,
double alpha , const double *A, const double *B,
double beta , double *C
)
{
    for(int stolbec = 0; stolbec < m; stolbec++)
    {
        for (int stroka = 0; stroka < n; stroka++)
        {
            double sum = 0;
            for(int step = 0; step < k; step++)
            {
                sum += A[stolbec * k + step] * B[step * n + stroka];
            }
            C[stolbec*n + stroka] *= beta;
            C[stolbec * n + stroka] += sum * alpha;
        }
    }
}