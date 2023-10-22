#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int amountOfCalls, amountOfLines = 0;
    fscanf(stdin,"%d",&amountOfCalls);
    char **identificators = (char**)malloc((amountOfCalls) * sizeof(char*));
    
    for (int step = 0; step < amountOfCalls; ++step)
    {
        identificators[step] = NULL;
    }
    for (int step = 0; step < amountOfCalls; ++step)
    {   
        int currentCall, identifier;
        fscanf(stdin, "%d", &currentCall);
        if (currentCall == 0)
        {
            int lineLength;
            fscanf(stdin, "%d", &lineLength);
            identificators[amountOfLines] = (char*)malloc(sizeof(char) * (lineLength+1));
            fscanf(stdin, "%s", identificators[amountOfLines]);
            amountOfLines++;
        }
        else if (currentCall == 1)
        {
            fscanf(stdin, "%d", &identifier);
            free(*(identificators+identifier));
            *(identificators+identifier) = NULL;
        }
        else if (currentCall == 2)
        {
            fscanf(stdin, "%d", &identifier);
            int lineLength = strlen(identificators[identifier]);
            for (int chrpos = 0; chrpos < lineLength; ++chrpos)
            {
                fprintf(stdout, "%c", identificators[identifier][chrpos]);
            }
            fprintf(stdout, "\n");
            //fprintf(stdout, "%s\n", *(identificators+identifier));
        }
        else
        {
            char symbol;
            fscanf(stdin, "%d %c", &identifier, &symbol);
            int counter = 0, lineLength;
            lineLength = strlen(*(identificators+identifier));
            for (int step2 = 0; step2 < lineLength; step2++) 
            {
                if (identificators[identifier][step2] == symbol)
                {
                    counter ++;
                }
            }
            fprintf(stdout, "%d\n", counter);
        }
    }
    for (int step = 0; step < amountOfLines; ++step)
    {
        if (*(identificators+step) != NULL)
        {
            free(*(identificators+step));
        }
    }
    free(identificators);
    fclose(stdin);
    fclose(stdout);
    return 0;
}