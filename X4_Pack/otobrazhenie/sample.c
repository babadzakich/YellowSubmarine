#include "hashmap.h"
#include <assert.h>
#include <string.h>
#define INTOF(ptr) (*(int*)(ptr))
int IntEqualFunc(cpvoid a, cpvoid b) {
    return (INTOF(a) - INTOF(b)) % 1000 == 0;
}
uint32_t IntHashFunc(cpvoid key) {
    int t = INTOF(key) % 1000;
    if (t < 0)
    t += 1000;
    return t * 0xDEADBEEF;
}
int main() {
    int data[] = {13, 174, 1013, -987, 0, 1};
    HashMap h = HM_Init(IntEqualFunc , IntHashFunc , 5);
    HM_Set (&h, &data[0], "hello");
    HM_Set (&h, &data[1], "world");
    assert(strcmp(HM_Get (&h, &data [2]), "hello") == 0);
    assert(strcmp(HM_Get (&h, &data [3]), "hello") == 0);
    HM_Set (&h, &data[4], "zero");
    assert(strcmp(HM_Get (&h, &data [4]), "zero") == 0);
    assert(strcmp(HM_Get (&h, &data [1]), "world") == 0);
    assert(HM_Get (&h, &data [5]) == 0);
    HM_Set (&h, &data[5], "one");
    //note: one empty cell left => cannot add more!
    HM_Destroy (&h);
    h = HM_Init(IntEqualFunc , IntHashFunc , 100000); //create larger table
    assert(HM_Get (&h, &data [5]) == 0);
    HM_Set (&h, &data[1], "newtable");
    HM_Set (&h, &data[1], "newtableX");
    assert(strcmp(HM_Get (&h, &data [1]), "newtableX") == 0);
}