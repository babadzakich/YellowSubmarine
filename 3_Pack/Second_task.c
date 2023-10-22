#include <stdio.h>
int main(){
    int amount_of_elements, element, elements[100000], sum = 0;
    scanf("%d", &amount_of_elements);
    for (int i = 0; i < amount_of_elements; ++i){
        scanf("%d", &element);
        elements[i] = element;
    }
    for (int step = 0; step < amount_of_elements; ++step){
        for (int step2 = step; step2 < amount_of_elements; step2 += (step + 1)){
            sum += elements[step2];
        }
        printf("%d \n", sum);
        sum = 0;
    }
    return 0;
}