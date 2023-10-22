#include <stdio.h>

int main()
{
   int end_of_sequence,sum_of_sequence=0;
   scanf("%d",&end_of_sequence);
   sum_of_sequence=end_of_sequence*(end_of_sequence+1)/2;
   printf("%d",sum_of_sequence);
   return 0;
}