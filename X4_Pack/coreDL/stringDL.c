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
    state->regs[index0] = strdup(strcat(state->regs[index0], state->regs[index1]));
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
        words++;
        state->regs[words] = strdup(word);
        word = strtok(NULL, "_");
    }
    state->regs[0] = itoa(words);   
}