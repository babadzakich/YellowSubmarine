#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define notInList 1000000008
#define limit 1000007

typedef struct Node_s
{
    struct Node_s *next;
    int32_t value;
}Node;

int hash(int number)
{
    if (number < 0)
    {
        number *= -1;
    }
    return number % limit;
}

int main()
{
    FILE *in = fopen("input.bin","rb");
    FILE *out = fopen("output.bin","wb");

    int32_t amountOfNumbers;
    int32_t newAmountOfNumbers = 0;
    fread(&amountOfNumbers, sizeof(int32_t), 1, in);
    int* input = (int*)malloc(sizeof(int)*amountOfNumbers);
    fread(input, sizeof(int32_t), amountOfNumbers, in);
    
    Node** array = (Node**)malloc(sizeof(Node*) * limit);
    for (int step = 0; step < limit; step++)
    {
        array[step] = NULL;
    }

    for (int step = 0; step < amountOfNumbers; step++)
    {
        int32_t number = hash(input[step]);
        
        if(array[number] == NULL)
        {
            array[number] = (Node*)malloc(sizeof(Node));
            array[number]->value = input[step];
            array[number]->next = NULL;
            newAmountOfNumbers++;
        }
        else
        {
            Node* temp = array[number];
            while(1)
            {
                if(temp->value == input[step])
                {
                    break;
                }
                if(temp->next == NULL)
                {
                    break;
                }
                
                temp = temp->next;
            }
            if(temp->value == input[step])
            {
                continue;
            }
            else
            {
                Node* new = (Node*)malloc(sizeof(Node));
                new->next = NULL;
                new->value = input[step];
                temp->next = new;
                newAmountOfNumbers++;
            }
        }
    }
    int* output = (int*)malloc(sizeof(int)*newAmountOfNumbers);
    int outputTop = 0;
    for (int step = 0; step < amountOfNumbers; step++)
    {
        int number = hash(input[step]);
        if(array[number] != NULL && array[number]->value == input[step])
        {
            output[outputTop++] = array[number]->value;
            Node* temp = array[number]->next;
            free(array[number]);
            array[number] = temp;
        }
    }
    fwrite(&outputTop, sizeof(int), 1, out);
    fwrite(output, sizeof(int), outputTop, out);
    free(input);
    free(array);
    free(output);
    fclose(in);
    fclose(out);
    return 0;
}