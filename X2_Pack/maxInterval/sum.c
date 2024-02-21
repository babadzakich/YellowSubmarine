#include <stdint.h>

int64_t prefSum[100001];
void Init(const int *arr , int n)
{
    prefSum[0] = arr[0];
    for(int step = 1; step < n; step++)
    {
        prefSum[step] = arr[step] + prefSum[step-1];
    }
}

int64_t Sum(int l, int r)
{
    if (l == 0)
    {
        return prefSum[r];
    }
    else
    {
        return prefSum[r] - prefSum[l - 1];
    }
}