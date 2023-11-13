#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//partitions array a[0..n-1] into two subarrays, returning value k
// the subarray a[0..k-1] must have all elements <= pivot
// the subarray a[k..n-1] must have all elements >= pivot
int partition (int *a , int n , int pivot )
{
    int lesserAmount, equalAmount, moreAmount;
    lesserAmount = equalAmount = moreAmount = 0;
    int32_t* lesserSequence = (int32_t*)malloc(sizeof(int32_t)*n);
    int32_t* equalSequence = (int32_t*)malloc(sizeof(int32_t)*n);
    int32_t* moreSequence = (int32_t*)malloc(sizeof(int32_t)*n);
    for(int step = 0; step < n; step++)
    {
        if (a[step]<pivot)
        {
            lesserSequence[lesserAmount++] = a[step];
        }
        else if(a[step] == pivot)
        {
            equalSequence[equalAmount++] = a[step];
        }
        else
        {
            moreSequence[moreAmount++] = a[step];
        }
    }
    for(int step = 0; step < n; step++)
    {
        if (step < lesserAmount)
        {
            a[step] = lesserSequence[step];
        }
        else if (step < (lesserAmount + equalAmount) && step >= lesserAmount)
        {
            a[step] = equalSequence[step - lesserAmount];
        }
        else
        {
            a[step] = moreSequence[step - lesserAmount-equalAmount];
        }
    }
    free(lesserSequence);
    free(equalSequence);
    free(moreSequence);
    return lesserAmount + equalAmount / 2;
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
    for( int step = 0; step < sequenceLength; step++)
    {
        fread(&sequence[step], sizeof(int32_t), 1, in);
    }
    int32_t partitionAmount = partition(sequence, sequenceLength, pivotElement);
    fwrite(&partitionAmount, sizeof(int32_t), 1, out);
    for (int step = 0; step < sequenceLength; step++)
    {
        fwrite(&sequence[step], sizeof(int32_t), 1, out);
    }
    return 0;
}