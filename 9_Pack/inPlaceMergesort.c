#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void swap(int* array, int number1, int number2) 
{
    int temporary = array[number1]; 
    array[number1] = array[number2];
    array[number2] = temporary;
}

void workingSort(int* array, int left, int right, int working) {
    int mid;
    if (right - left > 1) 
    {
        mid = left + (right - left) / 2;
        merge(array, left, mid);
        merge(array, mid, right);
        workingMerge(array, left, mid, mid, right, working);
    }
    else
    {
        while (left < right)
        {
            swap(array, left++, working++);
        }
    }
}

void workingMerge(int* array, int left, int mid, int left2, int right, int working) 
{
    while (left < mid && left2 < right)
    {
        swap(array, working++, array[left] < array[left2] ? left++ : left2++);
    }
    while (left < mid)
    {
        swap(array, working++, left++);
    }
    while (left2 < right)
    {
        swap(array, working++, left2++);
    }
}  
void merge(int *array, int left, int right) 
{
    int mid, temp, working;
    if (right - left > 1) 
    {
        mid = left + (right - left) / 2;
        working = left + right - mid;
        workingSort(array, left, mid, working); /* the last half contains sorted elements */
        while (working - left > 2) 
        {
            temp = working;
            working = left + (temp - left + 1) / 2;
            workingSort(array, working, temp, left);  /* the first half of the previous working area contains sorted elements */
            workingMerge(array, left, left + temp - working, temp, right, working);
        }
        for (temp = working; temp > left; --temp)/*switch to insertion sort*/
        { 
            for (mid = temp; mid < right && array[mid] < array[mid-1]; ++mid)
            {
                swap(array, mid, mid - 1);
            }
        }
                
    }
}
void mergeSort(int* array, int left, int right, int working) {
    if (right - left > 1)
    {
        int mid = left + (right - left) / 2;//creating partition index
        merge(array, left, mid);
        merge(array, mid, right);
        workingMerge(array, left, mid, mid, right, working);
    }
    else
    {
        while (left < right)
        {
            swap(array, left++,working++);
        }
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
    merge(array, 0, arrayLength-1);
    fwrite(array, sizeof(int), arrayLength, out);
    free(array);

    return 0;
}