#include <stdio.h>

void swapping(int* a, int* b)
{
    int temporary_number = *a;
    *a = *b;
    *b = temporary_number;
}

int partition(int array[], int low, int high)
{
    int comparasion_number = array[high], index_cnumber = low - 1;
    for (int step = low; step <= high - 1; ++step)
    {
        if (array[step] <= comparasion_number)
        {
            index_cnumber ++;
            swapping(&array[index_cnumber],&array[step]);

        }
    }
    swapping(&array[index_cnumber + 1], &array[high]);
    return (index_cnumber + 1);
}

void quicksort(int Array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(Array, low, high);
        quicksort(Array, low, pi-1);
        quicksort(Array, pi + 1, high);
    }
}

int main()
{
    int amount_of_elements, elements[10001] = {0}, element;
    
    scanf("%d", &amount_of_elements);
    
    for (int step = 0; step < amount_of_elements; ++step)
    {
        scanf("%d", &element);
        elements[step] = element;
    }

    quicksort(elements, 0, amount_of_elements - 1);
    
    for (int step = 0; step < amount_of_elements; ++step)
    {
        printf("%d ", elements[step]);
    }
    return 0;
}