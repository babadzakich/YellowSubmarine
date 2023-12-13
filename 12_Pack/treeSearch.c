#include <stdio.h>

typedef struct Tree
{
    struct Tree *left, *right;
    int value;
    int height;
}Root;

int main()
{
    FILE *in = fopen("input.bin","rb");
    FILE *out = fopen("output.bin","wb");
    int length;
    fread(&length, sizeof(int), 1, in);
    int* array = (int*)malloc(sizeof(int) * length);
    fread(array, sizeof(int), length, in);
    treeSort(array, length);
	fwrite(array, sizeof(int), length, out);
	free(array);
	fclose(in);
	fclose(out);
    return 0;
}