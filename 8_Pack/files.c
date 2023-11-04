#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push,1)
typedef struct{
    char name[21];
    long long size;
    char directory;
    long long created;
    long long modified;
    char hidden;
}File;
#pragma pack(pop)

void quicksort(File *array, int leftLimit, int rightLimit) {
    char sortBase[21];
    int leftStep = leftLimit;
    int rightStep = rightLimit;
 
    strcpy(sortBase, array[(leftLimit + (rightLimit-leftLimit)/2)].name);
    do {
        while (strcmp(array[leftStep].name,sortBase) < 0) {
            leftStep++;
        }
        while (strcmp(array[rightStep].name,sortBase) > 0) {
            rightStep--;
        }
        if (leftStep <= rightStep) {
            if (strcmp(array[leftStep].name,array[rightStep].name) > 0) {
                File temporaryFile = array[leftStep];
                array[leftStep] = array[rightStep];
                array[rightStep] = temporaryFile;
            }
            leftStep++;
            if (rightStep > 0) {
                rightStep--;
            }
        }
    } while (leftStep <= rightStep);
 
    if (leftStep < rightLimit) {
        quicksort(array, leftStep, rightLimit);
    }
    if (rightStep > leftLimit) {
        quicksort(array, leftLimit, rightStep);
    }
}

File files[1001];
int main()
{
    FILE *in = fopen("input.txt", "rb");
    FILE *out = fopen("output.txt", "wb");
    int amountOfFiles, currentPositiveFile = 0;
    long long creationTime,limitTime;
    fread(&amountOfFiles, sizeof(int), 1, in);
    fread(&creationTime, sizeof(long long), 1, in);
    fread(&limitTime, sizeof(long long), 1, in);
    File archive;
    for (int step = 0; step < amountOfFiles; step++)
    {
        fread(&archive, sizeof(File), 1, in);
        if (archive.directory != 1 && archive.hidden != 1 && archive.created >= creationTime && archive.modified <= limitTime)
        {
            files[currentPositiveFile++] = archive;
        }
    }
    quicksort(files, 0, currentPositiveFile);
    for (int step = 1; step <= currentPositiveFile; step++)
    {
        fwrite(&files[step], sizeof(File), 1, out);
    }
    
    fclose(in);
    fclose(out);
    return 0;
}