#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void merge(int *array, int left, int mid, int right) {

    int lengthOne = mid - left + 1; // 1 massiv levih
    int lengthTwo = right - mid;// 2 massiv pravih
 
    int* leftArray = (int*)malloc(sizeof(int)*lengthOne);
    int* rightArray = (int*)malloc(sizeof(int)*lengthTwo);

    //filling arrays with numbers
    for (int step = 0; step < lengthOne; step++)
    {
        leftArray[step] = array[left + step];
    }

    for (int step = 0; step < lengthTwo; step++)
    {
        rightArray[step] = array[mid + 1 + step];
    }

    int leftStep = 0, rightStep = 0, arrayStep = left;
    //while arrays are full
    while (leftStep < lengthOne && rightStep < lengthTwo) 
    {
        if (leftArray[leftStep] <= rightArray[rightStep]) // if left < right we add to our result array left, else we add right
        {
            array[arrayStep++] = leftArray[leftStep++];
        }
        else 
        {
            array[arrayStep++] = rightArray[rightStep++];
        }
    }
    //when we run out of one array, we check if we have some values in another array,
    // and because of comparasion, we can add all remaining values without checking
    while (leftStep < lengthOne)
    {
        array[arrayStep++] = leftArray[leftStep++];
    }
 
    while (rightStep < lengthTwo) 
    {
        array[arrayStep++] = rightArray[rightStep++];
    }
    free(rightArray);
    free(leftArray);
}

void mergeSort(int* array, int left, int right) {
    if (left < right) 
    {
        int mid = left + (right - left) / 2;//creating partition index
 
        mergeSort(array, left, mid); //with recursion we divide one array into two 4 -> 2,2 -> 1,1,1,1, and then we merge them with merge
        mergeSort(array, mid + 1, right);
 
        merge(array, left, mid, right);
    }
}

int main()
{
    FILE *in = fopen("input.txt", "rb");
    FILE *out = fopen("output.txt", "wb");

    int arrayLength;
    fread(&arrayLength, sizeof(int), 1, in);
    int* array = (int*)malloc(sizeof(int)*arrayLength);
    fread(array, sizeof(int), arrayLength, in);
    mergeSort (array, 0, arrayLength-1);
    fwrite(array, sizeof(int), arrayLength, out);
    free(array);

    return 0;
}