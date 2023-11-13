#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int comparasion (const int* numberOne, const int* numberTwo)
{
    return *numberOne - *numberTwo;
}

int main()
{
    // FILE *in = fopen("input.txt", "rb");
    // FILE *out = fopen("output.txt", "wb");

    int arrayLength;
    scanf("%d", &arrayLength);
    int array[arrayLength];
    for (int step = 0; step < arrayLength; step++)
    {
        scanf("%d", &array[step]);
    }
    qsort(array, arrayLength, sizeof(int), (int(*) (const void *, const void *))comparasion);
    
    int64_t sum = 0;
    for (int step = 0; step < arrayLength-1; step++)
    {
        sum += (int64_t)array[step] * (int64_t)(arrayLength-step-1);

    }
    printf("%lld", sum);
    return 0;
}