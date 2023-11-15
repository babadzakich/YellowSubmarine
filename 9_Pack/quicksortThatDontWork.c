#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <conio.h>
#include <time.h>


int randomNum(const int left, const int right) 
{
    return rand() % (right - left + 1) + left;
}

void quicksort(int* array, int leftStart, int rightStart)
{
    if (leftStart > rightStart)
    {
        return;
    }
    int left = leftStart, right = rightStart;
    srand(time(NULL));
    int pivot = array[rand() % (right - left + 1) + left];

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
            int temporary = array[left];
            array[left] = array[right];
            array[right] = temporary;   
            left++;
            right--;
        }
    }
    quicksort(array, leftStart, right);
    quicksort(array, left, rightStart);
    
}

int main()
{
    // int a[] = {1,2,2,2,1};
    // quicksort(a,0,4);
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d ",a[i]);
    // }
    
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