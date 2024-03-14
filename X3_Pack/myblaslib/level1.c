#include "myblas.h"
void dcopy (int n , const double *X , double *Y )
{
    for (int step = 0; step < n; step++) Y[step] = X[step];
}

//обменять местами содержимое векторов X и Y
void dswap (int n , double *X , double *Y )
{
    for(int step = 0; step < n; step++)
    {
        double temp = X[step];
        X[step] = Y[step];
        Y[step] = temp;
    }
}

//домножить вектор X на коэффициент alpha
void dscal (int n , double alpha , double *X )
{
    for(int step = 0; step < n; step++) X[step] *= alpha;
}

//прибавить к вектору Y вектор X, умноженный на коэффициент alpha
void daxpy (int n , double alpha , const double *X , double *Y )
{
    for(int step = 0; step < n; step++) Y[step] += (X[step] * alpha);
}
//вычислить скалярное произведение векторов X и Y
double ddot (int n , const double *X , const double * Y )
{
    double sum = 0;
    for(int step = 0; step < n; step++)
    {
        sum += (X[step] * Y[step]);
    }
    return sum;
}