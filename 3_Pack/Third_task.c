#include <stdio.h>
int main(){
    int amount_of_elements, element, elements[10001] = {0}, max_elem = 0;
    scanf("%d", &amount_of_elements);
    for (int counter = 0; counter < amount_of_elements; ++counter){
        scanf("%d", &element);
        elements[element] ++;
        if (element > max_elem){
            max_elem = element;
        }
    }
    for (int step = 1; step <= max_elem; ++step){
        if (elements[step] != 0){
            printf("%d: %d\n", step, elements[step]);
        }
    }
    return 0;
}