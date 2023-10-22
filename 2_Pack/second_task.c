#include <stdio.h>
#include <string.h>

int main(){
    char curr_day[4];
    scanf("%s", &curr_day);
    if (strcmp(curr_day,"Mon") == 0){
        printf("1");
    }
    else if (strcmp(curr_day,"Tue") == 0){
        printf("2");
    }
    else if (strcmp(curr_day,"Wed") == 0){
        printf("3");
    }
    else if (strcmp(curr_day,"Thu") == 0){
        printf("4");
    }
    else if (strcmp(curr_day,"Fri") == 0){
        printf("5");
    }
    else if (strcmp(curr_day,"Sat") == 0){
        printf("6");
    }
    else{
        printf("7");
    }
    return 0;
}