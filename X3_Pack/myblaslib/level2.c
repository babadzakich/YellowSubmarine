#include "myblas.h"
//вычислить вектор (alpha*A*X + beta*Y) длины m, и записать его в Y
//здесь A –- матрица размера m на n, X –- вектор длины n, а Y –- вектор длины m
void dgemv (
int m , int n ,
double alpha , const double *A , const double *X ,
double beta , double * Y
)
{
    for(int step = 0; step < m; step++)
    {
        double sum = 0;
        for(int step2 = 0; step2 < n; step2++)
        {
            sum += A[step * n + step2] * X[step2];
        }
        Y[step] *= beta;
        Y[step] += (sum * alpha);
    }
}

//вычислить матрицу (alpha*X*Yt + A) и записать её в A
//здесь Yt –- это транспонированный вектор Y, то есть записанный как вектор-строка
// A –- матрица размера m на n, X –- вектор длины m, а Y –- вектор длины n
void dger (
int m , int n ,
double alpha , const double *X , const double *Y ,
double *A
)
{
    for (int stroka = 0; stroka < m; stroka++)
    {
        for (int stolbec = 0; stolbec < n; stolbec++)
        {
            A[stroka * n + stolbec] += alpha * X[stroka] * Y[stolbec];
        }
    }
}