#include <stdio.h>

int main()
{
    int input_a,input_b,division_result,division_remainder;
    scanf("%d %d", &input_a, &input_b);

    division_result = input_a / input_b;
    division_remainder = input_a % input_b;

    if(input_a >= 0 && division_remainder != 0){
        printf("%d %d %d %d", division_result, division_result + 1, division_result, division_remainder);
    }

    else if(division_remainder == 0){
        printf("%d %d %d %d", division_result, division_result, division_result, division_remainder);
    }

    else if(input_a < 0 && division_remainder != 0){
        printf("%d %d %d %d", division_result - 1, division_result, division_result, division_remainder);
    }
    
    return 0;
}