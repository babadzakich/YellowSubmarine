#include <stdio.h>
#include <time.h>
#define SIZE 100000000


 

struct Node 
{
  long num;
  struct Node *next;
};

static struct Node array [SIZE];
int main () {
  long i, time1, time2, loopnode;
  struct Node *ptr1, *ptr2;

  for (i=0; i<SIZE-1; i++) {
    array [i].num = i+1;
    array [i].next = &array[i+1];
  }
  array [SIZE-1].num = SIZE-1;
  array [SIZE-1].next = &array[1];

  time1 = clock();

  ptr1 = &array[1];
  ptr2 = &array[2];

  while ((ptr2 != NULL) && 
        (ptr2->next != NULL) && 
        (ptr1 != ptr2)) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next->next;
  }
    
  if (ptr1 != ptr2)
    loopnode = 0;
  else {
    ptr1 = &array[0];
    while (ptr1 != ptr2) {
      ptr1 = ptr1->next;   
      ptr2 = ptr2->next;
    }
    loopnode = ptr1->num;
  }
   
  time2 = clock();
  
  printf ("Loopnode is %ld, time is %ld\n", 
          loopnode, time2-time1);
  
  return 0;

}