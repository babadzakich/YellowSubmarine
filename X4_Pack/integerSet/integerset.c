#include "integerset.h"
#include<stdlib.h>
#include<string.h>

int comparator(const void *arg1, const void *arg2)
{
    return *(int*)arg1 > *(int*)arg2;
}

typedef struct IntegerSet{
    int* arr;
    int len;
}IntegerSet;

IntegerSet* CreateSet(int* arr, int len)
{
    IntegerSet* newArr = (IntegerSet*)malloc(sizeof(IntegerSet));
    newArr->arr = (int*)malloc(sizeof(int) * len);

    for(int step = 0; step < len; step++)
    {
        newArr->arr[step] = arr[step];
    }
    qsort(newArr->arr, len, sizeof(int), comparator);

    for(int step = 1; step < len; step++)
    {
        if (newArr->arr[step] == newArr->arr[step-1])
        free(newArr->arr);
        free(newArr);
        return 0;
    }
    newArr->len = len;
    return newArr;
}

int IsInSet(IntegerSet* set, int num)
{
    if (!set) return 0;
    int left = 0, right = set->len-1;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if (set->arr[mid] < num)
        {
            left = mid + 1;
        }
        else if (set->arr[mid] > num)
        {
            right = mid - 1;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}