void cblas_dgemm(int Order, int TransA, int TransB, int M, int N, int K, const double alpha, const double *A, const int lda, const double *B, const int ldb, const double beta, double *C, const int ldc)
{   
    for(int stolbec = 0; stolbec < M; stolbec++)
    {
        for (int stroka = 0; stroka < N; stroka++)
        {
            double sum = 0;
            for(int step = 0; step < K; step++)
            {
                sum += A[stolbec * K + step] * B[step * N + stroka];
            }
            C[stolbec * N + stroka] *= beta;
            C[stolbec * N + stroka] = sum * alpha;
        }
    }
}