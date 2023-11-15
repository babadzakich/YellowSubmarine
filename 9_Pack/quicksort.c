#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <conio.h>


int randomNum(const int left, const int right) 
{
    return rand() % (right - left + 1) + left;
}

void quicksort(int* array, int leftStart, int rightStart)
{
    int left = leftStart, right = rightStart;
    int pivot = array[randomNum(leftStart,rightStart-1)];

    while (left <= right)
    {
        while (array[left] < pivot)
        {
            left++;
        }
        while (array[right] > pivot)
        {
            right--;
        }
        if (left <= right)
        {
            if (array[left] > array[right])
            {
                int temporary = array[left];
                array[left] = array[right];
                array[right] = temporary; 
                  
            }  
            left++;
            if (right > 0)
            {
                right--;
            }
        }
    }
    if (left < rightStart)
    {
        quicksort(array, left, rightStart);
    }
    if (right > leftStart)
    {
        quicksort(array, leftStart, right);
    }
}

int main()
{
    FILE *in = fopen("input.txt", "rb");
    FILE *out = fopen("output.txt", "wb");

    int32_t arrayLength, maxNum = 0;
    fread(&arrayLength, sizeof(int), 1, in);

    int32_t* array = (int32_t*)malloc(sizeof(int32_t) * arrayLength);

    fread(array, sizeof(int32_t), arrayLength, in);
    
    quicksort(array, 0, arrayLength-1);
    
    fwrite(array, sizeof(int), arrayLength, out);
    
    free(array);
    fclose(in);
    fclose(out);
    return 0;
}