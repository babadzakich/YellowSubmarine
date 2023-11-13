#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//partitions array a[0..n-1] into two subarrays, returning value k
// the subarray a[0..k-1] must have all elements <= pivot
// the subarray a[k..n-1] must have all elements >= pivot
int partition (int *a , int n , int pivot )
{
    int left = 0, right = n-1;
    int leftPivot = 0, rightPivot = 0;
    do 
    {
        while (a[left] < pivot)
        {
            left++;
        }
        while (a[right] > pivot)
        {
            right--;
        }
        if (left <= right)
        {
            if (a[left] > a[right])
            {
                int temporary = a[left];
                a[left] = a[right];
                a[right] = temporary;   
            }
            left++;
            right--;
        }
        
    }while (left <= right);
    return left;
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