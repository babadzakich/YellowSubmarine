#ifndef SUM_H_749837
#define SUM_H_749837
typedef struct IntegerSet IntegerSet;
IntegerSet* CreateSet(int* arr, int len);
int IsInSet(IntegerSet* set, int num);
void DeleteSet(IntegerSet* set);
#endif