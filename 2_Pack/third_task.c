#include <stdio.h>

int main(){
    int main_a_side, main_b_side, first_a_side, first_b_side, second_a_side, second_b_side, main_area, first_area, second_area;
    scanf("%d %d %d %d %d %d", &main_a_side, &main_b_side, &first_a_side, &first_b_side, &second_a_side, &second_b_side);

    main_area = main_a_side * main_b_side;
    
    first_area = first_a_side * first_b_side;
    
    second_area = second_a_side * second_b_side;
    
    if (main_area < (first_area + second_area)){
        printf("NO");
    }
    else if (main_a_side >= (first_a_side + second_a_side) && main_b_side >= first_b_side && main_b_side >= second_b_side){
        printf("YES");
    }
    else if (main_a_side >= (first_a_side + second_b_side) && main_b_side >= first_b_side && main_b_side >= second_a_side){
        printf("YES");
        }
    else if (main_a_side >= first_b_side + second_a_side && main_b_side >= first_a_side && main_b_side >= second_b_side){
        printf("YES");
    }
    else if (main_a_side >= first_b_side + second_b_side && main_b_side >= first_a_side && main_b_side >= second_a_side){
        printf("YES");
    }
    else if (main_b_side >= first_a_side + second_a_side && main_a_side >= first_b_side && main_a_side >= second_b_side){
        printf("YES");
    }
    else if (main_b_side >= first_a_side + second_b_side && main_a_side >= first_b_side && main_a_side >= second_a_side){
        printf("YES");
        }
    else if (main_b_side >= first_b_side + second_a_side && main_a_side >= first_a_side && main_a_side >= second_b_side){
        printf("YES");
    }
    else if (main_b_side >= first_b_side + second_b_side && main_a_side >= first_a_side && main_a_side >= second_a_side){
        printf("YES");
    }
    else {
        printf("NO");
    }
    return 0;
}