#include <stdio.h>
#include <math.h>
int main(){
    int bit, digit = 0, amount_of_bits, decimal = 0;
    scanf("%s", &amount_of_bits);
    char string_of_bits[amount_of_bits];
    scanf("%s", string_of_bits);
    for(int step = 0; step < amount_of_bits; step++){
        if (string_of_bits[step] == '1'){
            bit = 1;
        }
        else{
            bit = 0;
        }        
        digit = step % 8;

        if(digit >= 1){
            decimal += bit * pow(2, digit);
        }
        else{
            decimal += bit;
        }
        
        if (digit == 7){
            printf("%d", decimal);
            decimal = 0;
        }
    }
    
    if (digit != 7){
        printf("%d", decimal);
    }
    return 0;
}