#ifndef declaration
#define declaration
typedef struct State 
{
    char *regs[256]
}State;
void echo_0(State *state);
void echo_1(State *state , char *arg0);
void echo_2(State *state , char *arg0 , char *arg1);
void echo_3(State *state , char *arg0 , char *arg1 , char *arg2);
//prints contents of I-th register (it must not be NULL)
//[idx] contains decimal representation of I
void print_1(State *state , char *idx);
//prints all non-NULL registers with their values (sorted by register number)
void printregs_0(State *state);
//saves a copy of string [what] into I-th register
//[idx] contains decimal representation of I
void store_2(State *state , char *idx , char *what);
//copies contents of S-th register into D-th register (S-th register is not NULL)
//[dst] and [src] contain decimal representations of D and S respectively
//BEWARE: [dst] and [src] are allowed to be equal indices
void copy_2(State *state , char *dst , char *src);
//assigns NULL to I-th register
//[idx] contains decimal representation of I
void clear_1(State *state , char *idx);
#endif