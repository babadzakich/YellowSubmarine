#include <stdio.h>
#include <stdlib.h>
int comparasion (const int* numberOne, const int* numberTwo)
{
    return (*(int*)numberOne - *(int*)numberTwo);
}

void duplicateDeletion(int* array, int* size)
{
    int* tempArray = (int*)malloc(sizeof(int)*(*size));
    tempArray[0] = array[0];
    int step2=0, uniqueElements = 1;
    for (int step = 1; step < *size; step++)
    {
        if (array[step] != array[step - 1])
        {
            tempArray[uniqueElements++] = array[step];
        }
    }
    array = realloc(array, sizeof(int)*uniqueElements);
    for (int step = 0; step < uniqueElements; step++)
    {
        array[step] = tempArray[step];
    }
    *size = uniqueElements;
    free(tempArray);
}


int main()
{   
    int firstArrayLength, secondArrayLength;
    scanf("%d", &firstArrayLength);
    int* firstArray = (int*)malloc(sizeof(int)*firstArrayLength);
    for(int step = 0; step < firstArrayLength; step++)
    {
        scanf("%d", &firstArray[step]);
    }
    qsort(firstArray, firstArrayLength, sizeof(int), comparasion);
    duplicateDeletion(firstArray, &firstArrayLength);

    
    scanf("%d", &secondArrayLength);
    int* secondArray = (int*)malloc(sizeof(int)*secondArrayLength);
    for(int step = 0; step < secondArrayLength; step++)
    {
        scanf("%d", &secondArray[step]);
    }
    qsort(secondArray, secondArrayLength, sizeof(int), comparasion);
    duplicateDeletion(secondArray, &secondArrayLength);


    int firstStep = 0;
    int secondStep = 0;
    int thirdLen = 0;
    int* thirdArray = (int*)malloc(sizeof(int) * (firstArrayLength + secondArrayLength));

    while(firstStep < firstArrayLength && secondStep < secondArrayLength)
    {
        if (firstArray[firstStep] < secondArray[secondStep])
        {
            thirdArray[thirdLen++] = firstArray[firstStep++];
        }
        else if (firstArray[firstStep] == secondArray[secondStep])
        {
            firstStep++;
            secondStep++;  
        }
        else
        {
            secondStep++;
        }
    }
    while (firstStep < firstArrayLength)
    {
        thirdArray[thirdLen++] = firstArray[firstStep++];
    }
    //duplicateDeletion(thirdArray, &thirdLen);
    printf("%d\n", thirdLen);
    for(int step = 0; step < thirdLen; step++)
    {
        printf("%d ", thirdArray[step]);
    }
    free(firstArray);
    free(secondArray);
    free(thirdArray);
    // fclose(in);
    // fclose(out);
    return 0;
}