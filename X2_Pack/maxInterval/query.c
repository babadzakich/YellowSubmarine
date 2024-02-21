#include <stdint.h>

extern int64_t prefSum[100001];

int64_t Sum(int l, int r);
extern int N;
int Query(int l, int64_t sum)
{
    int left = l, right = N;
    while (left < right)
    {
        int mid = left + (right-left) / 2;
        if (Sum(l,mid) <= sum)
        {
            left = mid+1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}