#include <stdio.h>

int main()
{
   int amount_of_numbers,number_in_sequence,summary=0,division_remainder;
   scanf("%d", &amount_of_numbers);
   
   for(int i=0;i<amount_of_numbers;i++){
       scanf("%d",&number_in_sequence);
       
       division_remainder=number_in_sequence%2;
       
       if(division_remainder==0){
           summary+=number_in_sequence;
       }
   }
   printf("%d",summary);
   return 0;
}