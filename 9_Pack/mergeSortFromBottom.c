#include <stdio.h>
#include <stdlib.h>

void merge(int* array, int* temporary, int left, int right, int mid)
{
    int leftStep = left, rightStep = mid+1, resStep = leftStep;
    while (leftStep <= mid && rightStep <= right)
    {
        if (array[leftStep] < array[rightStep])
        {
            temporary[resStep++] = array[leftStep++];
        }
        else
        {
            temporary[resStep++] = array[rightStep++];
        }
    }

    while (leftStep <= mid) temporary[resStep++] = array[leftStep++];
    while (rightStep <= right) temporary[resStep++] = array[rightStep];
    for(int step = left; left <= right; step++) array[step] = temporary[step];
    
}

int main()
{
    FILE *in = fopen("input.txt","rb");
    FILE *out = fopen("output.txt","wb");
    int arrayLength;
    fread(&arrayLength, sizeof(int), 1, in);
    int* array = (int*)malloc(sizeof(int)*arrayLength);
    int* temporaryArray = (int*)malloc(sizeof(int)*arrayLength);
    fread(array, sizeof(int), arrayLength, in);
    int baseSize = 1;
    while (baseSize < arrayLength)
    {
        for (int step = baseSize; step < arrayLength; step += (baseSize*2))
        {
            int right = step + baseSize;
            int left = step - baseSize;
            right = right > arrayLength ? arrayLength : right;
            merge(array, temporaryArray,left, right-1, step-1);
        }
        baseSize*=2;
    }
    fwrite(array, sizeof(int), arrayLength, out);
    free(array);
    free(temporaryArray);
    fclose(in);
    fclose(out);
    return 0;
}