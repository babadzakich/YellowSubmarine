#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//partitions array a[0..n-1] into two subarrays, returning value k
// the subarray a[0..k-1] must have all elements <= pivot
// the subarray a[k..n-1] must have all elements >= pivot
int partition (int *a , int n , int pivot )
{
    int leftPivot, rightPivot;
    leftPivot = rightPivot = 0;
    int left = 0, right = n-1;
    while (left < right)
    {
        while (a[left] < pivot)
        {
            left++;
        }
        while (a[right] > pivot)
        {
            right--;
        }
        if (left < right)
        {
            if (a[left] == pivot && rightPivot - leftPivot > 1)
            {
                left++;
                leftPivot++;
            }
            else if(a[right] == pivot && leftPivot - rightPivot > 1)
            {
                right--;
                rightPivot++;
            }
            else if ( a[left] == pivot && a[right] == pivot)
            {
                if (rightPivot - leftPivot > 1)
                {
                    left++;
                    leftPivot++;
                }
                else if (leftPivot - rightPivot > 1)
                {
                    right--;
                    rightPivot++;
                }
                else
                {
                    int temporary = a[left];
                    a[left] = a[right];
                    a[right] = temporary;
                    left++;
                    right--;
                }
            }
            else if((a[left] == pivot && leftPivot - rightPivot > 1) || (a[right] == pivot && rightPivot - leftPivot > 1))
            {
                int temporary = a[left];
                a[left] = a[right];
                a[right] = temporary;
                left++;
                right--; 
            }
            else
            {
                int temporary = a[left];
                a[left] = a[right];
                a[right] = temporary;
                left++;
                right--; 
            }
        }
    }
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
    fclose(in);
    fclose(out);
    return 0;
}