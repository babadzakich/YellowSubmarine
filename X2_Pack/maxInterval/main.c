#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
int N;
//static int64_t prefSum[100001];
//extern int Sum(int l, int r);
void Init(const int *arr, int n);
int Query(int l, int64_t sum);
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int amountOfCalls;
    scanf("%d %d",&N, &amountOfCalls);
    int array[100001];
    for (int step = 0; step < N; step++)
    {
        scanf("%d", &array[step]);   
    }
    Init(array, N);
    for(int step = 0; step < amountOfCalls; step++)
    {
        int left;
        int64_t sum;
        scanf("%d %lld", &left, &sum);
        printf("%d\n", Query(left, sum));
    }
    return 0;
}