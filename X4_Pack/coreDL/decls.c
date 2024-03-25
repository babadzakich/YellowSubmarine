#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include"decls.h"


//prints ’ECHO: ’ and all passed strings separated by ’|’
void echo_0(State *state)
{
    printf("ECHO:\n");
}
void echo_1(State *state , char *arg0)
{
    printf("ECHO: %s\n", arg0);
}
void echo_2(State *state , char *arg0 , char *arg1)
{
    printf("ECHO: %s|%s\n", arg0, arg1);
}
void echo_3(State *state , char *arg0 , char *arg1 , char *arg2)
{
    printf("ECHO: %s|%s|%s\n", arg0, arg1, arg2);
}

//prints contents of I-th register (it must not be NULL)
//[idx] contains decimal representation of I
void print_1(State *state , char *idx)
{
    int index = atoi(idx);
    if (state->regs[index]) printf("%s\n", state->regs[index]);
}

//prints all non-NULL registers with their values (sorted by register number)
void printregs_0(State *state)
{
    for(int step = 0; step < 256; step++)
    {
        if(state->regs[step])
        {
            printf("%d = %s\n", step, state->regs[step]);
        }
    }
}

//saves a copy of string [what] into I-th register
//[idx] contains decimal representation of I
void store_2(State *state , char *idx , char *what)
{
    int counter = strlen(what);
    while (what[counter] != '\0') counter++;
    int index = atoi(idx);
    if(state->regs[index]) free(state->regs[index]);
    state->regs[index] = strdup(what);
}

//copies contents of S-th register into D-th register (S-th register is not NULL)
//[dst] and [src] contain decimal representations of D and S respectively
//BEWARE: [dst] and [src] are allowed to be equal indices
void copy_2(State *state , char *dst , char *src)
{
    int destination, source;
    destination = atoi(dst);
    source = atoi(src);
    if (state->regs[source])
    {
        int length = 0;
        while(state->regs[source][length] != '\0') length++;
        if (state->regs[destination]) free(state->regs[destination]);
        state->regs[destination] = strdup(state->regs[source]);
    }
}

//assigns NULL to I-th register
//[idx] contains decimal representation of I
void clear_1(State *state , char *idx)
{
    int index = atoi(idx);
    free(state->regs[index]);
    state->regs[index] = NULL;
}