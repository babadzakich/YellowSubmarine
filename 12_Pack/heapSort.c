#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int* array, int length, int root)
{
	int largest = root;

	int left = 2 * root + 1;

	int right = 2 * root + 2;

	if (left < length && array[left] > array[largest])
	{
		largest = left;
	}
	if (right < length && array[right] > array[largest])
	{
		largest = right;
	}
	if (largest != root) 
	{
		swap(&array[root], &array[largest]);
		heapify(array, length, largest);
	}
}

void heapSort(int* array, int length)
{

	for (int step = length / 2 - 1; step >= 0; step--)
	{
		heapify(array, length, step);
	}
	for (int step = length - 1; step >= 0; step--) 
	{
		swap(&array[0], &array[step]);
		heapify(array, step, 0);
	}
}



int main()
{
    FILE *in = fopen("input.bin","rb");
    FILE *out = fopen("output.bin","wb");
    int length;
    fread(&length, sizeof(int), 1, in);
    int* array = (int*)malloc(sizeof(int) * length);
    fread(array, sizeof(int), length, in);
    heapSort(array, length);
	fwrite(array, sizeof(int), length, out);
	free(array);
	fclose(in);
	fclose(out);
    return 0;
}
