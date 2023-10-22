#include <stdio.h>

int main(){
    int first_amount, second_amount, first_number, second_number, numbers[100001] = {0}, max_elem = 0, flag = 0, remaining_amount = 0, step2 = 0, result[10000] = {0};
    scanf("%d", &first_amount);
    for (int step = 0; step < first_amount; ++step){
        scanf("%d", &first_number);
        numbers[first_number] ++;
        if (first_number > max_elem){
            max_elem = first_number;
        }
    }
    scanf("%d", &second_amount);
    for (int step = 0; step < second_amount; ++step){
        scanf("%d", &second_number);
        numbers[second_number] = 0;
    }

    for (int step = 0; step <= max_elem; ++step){
        if (numbers[step] != 0){
            result[step2] = step;
            remaining_amount ++;
            flag = 1;
            step2++;
        }
    }
    if (flag == 0){
        printf("0");
    }
    else{
        printf("%d\n", remaining_amount);
        for (int step = 0; step < remaining_amount; ++step){
            printf("%d ", result[step]);
        }
    }
    return 0;
}