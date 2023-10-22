#include <stdio.h>

int main(){
    int amount_of_numbers, number_in_sequence;
    double numbers_below_zero, zero, numbers_after_zero;
    
    scanf("%d", &amount_of_numbers);
    
    for(int step=0; step < amount_of_numbers; step++){
        scanf("%d", &number_in_sequence);
        if(number_in_sequence < 0){
            numbers_below_zero ++;
        }
        else if( number_in_sequence == 0){
            zero ++;
        }
        else{
            numbers_after_zero ++;
        }
    }

    printf("%0.5lf %0.5lf %0.5lf", numbers_below_zero / amount_of_numbers, zero / amount_of_numbers, numbers_after_zero / amount_of_numbers);
    return 0;
}