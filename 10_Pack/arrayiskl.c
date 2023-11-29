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
        if (array[step] > tempArray[step2])
        {
            tempArray[++step2] = array[step];
            uniqueElements++;
        }
    }
    array = realloc(array, sizeof(int)*uniqueElements+1);
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
    //duplicateDeletion(firstArray, &firstArrayLength);

    
    scanf("%d", &secondArrayLength);
    int* secondArray = (int*)malloc(sizeof(int)*secondArrayLength);
    for(int step = 0; step < secondArrayLength; step++)
    {
        scanf("%d", &secondArray[step]);
    }
    qsort(secondArray, secondArrayLength, sizeof(int), comparasion);
    //duplicateDeletion(secondArray, &secondArrayLength);


    int firstStep = 0;
    int secondStep = 0;
    int thirdLen = 0;
    int thirdCapacity = 1;
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
    int* resArray = (int*)malloc(sizeof(int)*thirdLen);
    int resLen = 0;
    for (int step = 0; step < thirdLen-1; step++)
    {
        if(thirdArray[step] != thirdArray[step+1])
        {
            resArray[resLen++] = thirdArray[step];
        }
    }
    printf("%d\n", resLen);
    for(int step = 0; step < resLen; step++)
    {
        printf("%d ", resArray[step]);
    }
    free(resArray);
    free(firstArray);
    free(secondArray);
    free(thirdArray);
    // fclose(in);
    // fclose(out);
    return 0;
}