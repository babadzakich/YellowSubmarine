#include <stdio.h>

int main(){
    int low_limit, amount_limit, top_limit, k_element, amount_of_progressions;
    scanf("%d %d %d", low_limit, top_limit, amount_limit);
    for (low_limit; low_limit < top_limit; low_limit++)
    {
        for (int step = 1;step < top_limit - low_limit; step++)
        {
            k_element = low_limit + step * (amount_limit - 1);
            if (k_element >= top_limit && k_element + step > top_limit){
                amount_of_progressions ++;
            }
        }
        
    }
    printf("%d", amount_of_progressions);
    return 0;
}