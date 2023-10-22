#include <stdio.h>
#include <math.h>
int main()
{
    int input_number,i=2,divider=0;
    double division_remainder;
    scanf("%d", &input_number);
    
    division_remainder=sqrt(input_number);
    
    while(i<=division_remainder && divider==0){
        if(input_number%i==0){
            divider+=1;
        }
        i++;
    }
    if(divider>0 || input_number==1){
        printf("NO");
    }
    else{
        printf("YES");
    }
    return 0;
}