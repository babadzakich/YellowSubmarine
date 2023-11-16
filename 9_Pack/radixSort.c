#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



void countingSort(int array[], int size, int place) {
    const int max = 10;
    int output[size];
    int count[max];

    for(int i = 0; i < max; ++i)
    	count[i] = 0;

    for(int i = 0; i < size; i++)
    	count[(array[i]/place)%max]++;

    for(int i = 1; i < max; i++)
    	count[i] += count[i - 1];

    for(int i = size - 1; i >= 0; i--) {
    	output[count[(array[i]/place)%10] - 1] = array[i];
    	count[(array[i]/place)%10]--;
    }

    for(int i = 0; i < size; i++)
    	array[i] = output[i];
}

void radixsort(int array[], int size) {
    int max = array[0];
    for(int i = 1; i < size; i++)
	if(array[i] > max)
		max = array[i];

    for(int place = 1; max/place > 0; place *= 10)
    	countingSort(array, size, place);
}

int main() {
    FILE *in = fopen("input.txt", "rb");
    FILE *out = fopen("output.txt", "wb");
    int arrayLength;
    fread(&arrayLength, sizeof(int), 1, in);
    radixsort(array, n);
    for(int i = 0; i < n; i++)
    	printf("%d ", array[i]);
    return 0;
}