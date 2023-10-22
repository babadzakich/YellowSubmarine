#include <stdio.h>

int main(){
    int elements[5000], element, amount_of_elements, sum = 0, max_sum = 0, left_elem = 0, right_elem = 0, minus = -1;
    scanf("%d", &amount_of_elements);

    for (int step = 0; step < amount_of_elements; ++step){
        scanf("%d", &element);
        elements[step] = element;
    }

    max_sum = elements[0];
    for (int step = 0; step < amount_of_elements; ++step)
    {
        sum += elements[step];
        if (sum > max_sum)
        {
            max_sum = sum;
            left_elem = minus + 1;
            right_elem = step;
        }
        if (sum < 0)
        {
            sum = 0;
            minus = step;
        }
    } 
    printf("%d %d %d", left_elem, right_elem, max_sum);
    
    return 0;
}