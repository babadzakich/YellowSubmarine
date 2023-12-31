#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//merges sorted arrays a[0..ak-1] and b[0..bk-1] into
//one sorted array res[0..rk-1], returning rk from function
int merge ( const int *a , int ak , const int *b , int bk , int * res )
{
    int32_t resultLength = ak+bk;
    int32_t resultStep, aStep, bStep;
    resultStep = aStep = bStep = 0;
    
    while (aStep < ak && bStep < bk)
    {
        if (a[aStep] > b[bStep])
        {
            res[resultStep++] = b[bStep++];
        }
        else
        {
            res[resultStep++] = a[aStep++];
        }
    }

    while (aStep < ak)
    {
        res[resultStep++] = a[aStep++];
    }
    while (bStep < bk)
    {
        res[resultStep++] = b[bStep++];
    }
    
    return resultLength;
}


int main()
{
    FILE *in = fopen("input.txt","rb");
    FILE *out = fopen("output.txt","wb");

    int32_t firstSequenceLength;
    fread(&firstSequenceLength, sizeof(int32_t), 1, in);
    int32_t* firstSequence = (int32_t*)malloc(sizeof(int32_t) *firstSequenceLength);   

    int32_t secondSequenceLength; 
    fread(&secondSequenceLength, sizeof(int32_t), 1, in);
    int32_t* secondSequence = (int32_t*)malloc(sizeof(int32_t) * secondSequenceLength);

    fread(firstSequence, sizeof(int32_t), firstSequenceLength, in);

    fread(secondSequence, sizeof(int32_t), secondSequenceLength, in);

    int32_t *mergedSequence = (int32_t*)malloc(sizeof(int32_t)*(secondSequenceLength+firstSequenceLength));

    int32_t mergedSequenceLength = merge(firstSequence, firstSequenceLength, secondSequence, secondSequenceLength, mergedSequence);
    //qsort(mergedSequence, mergedSequenceLength, sizeof(int32_t),compare);

    fwrite(mergedSequence, sizeof(int32_t), mergedSequenceLength, out);
    
    free(firstSequence);
    free(secondSequence);
    free(mergedSequence);
    fclose(in);
    fclose(out);
    return 0;
}