#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//partitions array a[0..n-1] into two subarrays, returning value k
// the subarray a[0..k-1] must have all elements <= pivot
// the subarray a[k..n-1] must have all elements >= pivot
int partition (int *a , int n , int pivot )
{
    int leftStep = 0, rightStep = n-1;
    int leftPivot = 0, rightPivot = 0;
    while (leftStep <= rightStep)
    {
        while (a[leftStep] < pivot)
        {
            leftStep++;
        }
        while (a[rightStep] > pivot)
        {
            rightStep--;
        }
        if (leftStep <= rightStep)
        {
            int temporary = a[leftStep];
            a[leftStep] = a[rightStep];
            a[rightStep] = temporary;   
            leftStep++;
            rightStep--;
        }
    }
    int leftCounter = 0, pivotCounter = 0;
    for(int step = 0; step < n; step++)
    {
        if (a[step] < pivot)
        {
            leftCounter++;
        }
        if (a[step] == pivot)
        {
            pivotCounter++;
        }
    }
    if (pivotCounter % 2 == 1)
    {
        pivotCounter = pivotCounter/2+1;
    }
    else
    {
        pivotCounter/=2;
    }
    return leftCounter + pivotCounter;
}

int main()
{
    FILE *in = fopen("input.txt", "rb");
    FILE *out = fopen("output.txt", "wb");

    int32_t sequenceLength;
    fread(&sequenceLength, sizeof(int32_t), 1, in);

    int32_t pivotElement;
    fread(&pivotElement, sizeof(int32_t), 1, in);

    int32_t sequence[sequenceLength];
    fread(sequence, sizeof(int32_t), sequenceLength, in);
    int32_t partitionAmount = partition(sequence, sequenceLength, pivotElement);
    fwrite(&partitionAmount, sizeof(int32_t), 1, out);
    fwrite(sequence, sizeof(int32_t), sequenceLength, out);
    fclose(in);
    fclose(out);
    return 0;
}