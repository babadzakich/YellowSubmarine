

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
        Y[step] = alpha * A[step] * X[step] + beta * Y[step];
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
            C[stolbec * n + stroka] = sum * alpha;
        }
    }
}