#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//partitions array a[0..n-1] into two subarrays, returning value k
// the subarray a[0..k-1] must have all elements <= pivot
// the subarray a[k..n-1] must have all elements >= pivot
int partition (int *a , int n , int pivot )
{
    int left = 0, right = n-1;
    int flag = 0; // flag shows whether we added last occured pivot to the left
    int* resultArray = (int*)malloc(sizeof(int)*n);
    for (int step = 0; step < n; step++)
    {
        if (a[step] < pivot)
        {
            resultArray[left++] = a[step];
        }
        else if(a[step] > pivot)
        {
            resultArray[right--] = a[step];
        }
        else
        {
            if(flag)
            {
                resultArray[right--] = a[step];
                flag = 0;
            }
            else
            {
                resultArray[left++] = a[step];
                flag = 1;
            }
        }
        
    }
    for (int step = 0; step < n; step++)
    {
        a[step] = resultArray[step];
    }
    free(resultArray);
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

    int32_t* sequence = (int32_t*)malloc(sizeof(int32_t)*sequenceLength);
    fread(sequence, sizeof(int32_t), sequenceLength, in);
    int32_t partitionAmount = partition(sequence, sequenceLength, pivotElement);
    fwrite(&partitionAmount, sizeof(int32_t), 1, out);
    fwrite(sequence, sizeof(int32_t), sequenceLength, out);
    free(sequence);
    fclose(in);
    fclose(out);
    return 0;
}