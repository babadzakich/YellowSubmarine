#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int matrixN;
    scanf("%d", &matrixN);
    
    double** matrix = (double**)malloc(sizeof(double*) * matrixN);
    for(int step = 0; step < matrixN; step++)
    {
        matrix[step] = (double*)malloc(sizeof(double)*(matrixN+1));
    }
    for (int step = 0; step < matrixN; step++)
    {
        for (int step2 = 0; step2 <= matrixN; step2++)
        {
            scanf("%lf", &matrix[step][step2]);
        }
    }

    /* converting matrix to a stepped form*/
    for (int step = 0; step < matrixN - 1; step++)
    {
        if (matrix[step][step] == 0)
        {
            for (int step2 = step+1; step2 < matrixN; step2++)
            {
                    if (matrix[step2][step] != 0)
                    {
                        for (int step3 = 0; step3 <= matrixN; step3++)
                        {
                            double temp = matrix[step][step3];
                            matrix[step][step3] = matrix[step2][step3];
                            matrix[step2][step3] = temp;
                        }
                    }
            }
        }
        for (int step2 = step+1; step2 < matrixN; step2++)
        {
            double coef = matrix[step2][step] / matrix[step][step];
            for (int step3 = 0; step3 < matrixN+1; step3++)
            {
                matrix[step2][step3] -= matrix[step][step3] * coef;
            }
        }
    }

    /*solving it*/
    for (int step = matrixN-1; step >= 0; step--)
    {
        for (int step2 = step+1; step2 < matrixN; step2++)
        {
            matrix[step][step2] *= matrix[step+1][step2];
            matrix[step][matrixN] -= matrix[step][step2];
            matrix[step][step2] = matrix[step+1][step2]; 
        }
        matrix[step][step] = matrix[step][matrixN] / matrix[step][step];
    }
    /* printing an equasion */
    for (int step = 0; step < matrixN; step++)
    {
        printf("%lf\n", matrix[0][step]);
    }
    
    /* freeing the memory */
    for(int step = 0; step < matrixN; step++)
    {
        free(matrix[step]);
    }
    free(matrix);
    return 0;
}