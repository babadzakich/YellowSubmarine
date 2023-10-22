#include <stdio.h>
#include <string.h>
int main(){
    int amount_of_words = 0, len_of_line, flag = 1; // flag смотрит, есть ли у нас точки до нынешнего символа
    char line[10001];
    
    scanf("%s", &line);
    for (int curr_sym = 0; curr_sym <= 10001; curr_sym ++ ) {

        if (line[curr_sym] == '\0'){
            break;
        }
        else if (line[curr_sym] != '.' && flag == 1){
            amount_of_words ++;
            flag = 0;
        }
        else if (line[curr_sym] != '.' && flag == 0){
            continue;
        }
        else if (line[curr_sym] == '.' && flag == 0){
            flag = 1;
        }
        else if (line[curr_sym] == '.' && flag == 1){
            continue;
        }
    } 
    printf("%d", amount_of_words);
    return 0;
}