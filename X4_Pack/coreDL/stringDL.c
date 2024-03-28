#include "decls.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//loads string A from I-th register ([idx0] contains its index)
//loads string B from J-th register ([idx1] contains its index)
//then stores concatenation of A and B into I-th register
//BEWARE: [idx0] and [idx1] are allowed to be equal indices
void concat_2 ( State * state , char * idx0 , char * idx1 )
{
    int index0 = atoi(idx0);
    int index1 = atoi(idx1);
    if (index1 == index0)
    {
        char* temp = (char*)malloc(strlen(state->regs[index0]) + 1);
        strcpy(temp, state->regs[index0]);
        state->regs[index0] = realloc(state->regs[index0], strlen(state->regs[index0]) * 2 + 1);
        strcat(state->regs[index0], temp); 
        free(temp); 
    }
    else
    {
        if(state->regs[index1] != NULL && state->regs[index0] == NULL)
        {
            state->regs[index0] = (char*)malloc(strlen(state->regs[index1] + 1));
            strcpy(state->regs[index0], state->regs[index1]);
        }
        else if(state->regs[index1] != NULL)
        {
            state->regs[index0] = realloc(state->regs[index0], strlen(state->regs[index1])+strlen(state->regs[index0])+2); 
            strcat(state->regs[index0], state->regs[index1]);
        }
    }

}
//extracts sequence of tokens/words separated by underscore character from string [arg]
//puts K –- number of tokens into 0-th register
//puts the tokens into 1-th, 2-th, ..., K-th registers (in correct order)
void tokenize_1 ( State * state , char * arg )
{
    int words = 0;
    char* word = strtok(arg, "_");
    while(word != NULL)
    {
        state->regs[++words] = strdup(word);
        word = strtok(NULL, "_");
    }
    char num[100];
    sprintf(num, "%d", words);
    state->regs[0] = strdup(num);   
}