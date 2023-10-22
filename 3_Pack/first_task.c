#include <stdio.h>

int main(){
    int amount_of_numbers, number, lower_numbers = 0;
    scanf("%d", &amount_of_numbers);
    int numbers[100];

    for(int step = 0; step < amount_of_numbers; step++){
        scanf("%d", &number);
        numbers[step] = number;
    }
    for (int step = 0; step < amount_of_numbers; step++){
        if ((step + 1) == amount_of_numbers){
            printf("%d",lower_numbers);
            break;
        }
        else{
            for(int step2 = step + 1;step2 < amount_of_numbers; ++step2){
                if(numbers[step2] < numbers[step]){
                    lower_numbers ++;
                }
            }
            printf("%d ", lower_numbers);
            lower_numbers = 0;
        }
        
    }
    return 0;
}