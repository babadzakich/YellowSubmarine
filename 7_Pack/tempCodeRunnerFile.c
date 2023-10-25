#include <stdio.h>
#include <stdlib.h>
#define bit_zero 0
#define bit_get 1
#define bit_set 2
#define bit_any 3
// #define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c "
// #define BYTE_TO_BINARY(byte)  \
//   ((byte) & 0x80 ? '1' : '0'), \
//   ((byte) & 0x40 ? '1' : '0'), \
//   ((byte) & 0x20 ? '1' : '0'), \
//   ((byte) & 0x10 ? '1' : '0'), \
//   ((byte) & 0x08 ? '1' : '0'), \
//   ((byte) & 0x04 ? '1' : '0'), \
//   ((byte) & 0x02 ? '1' : '0'), \
//   ((byte) & 0x01 ? '1' : '0') 


//какой-нибудь целочисленный тип (желательно беззнаковый)
typedef unsigned char bitword ;
//инициализирует массив битов длины num, устанавливая все его биты в ноль
void bitsetZero ( bitword ** arr , int num ){
    if (*arr != NULL){
        free(*arr);
    }
    *arr = calloc((num/8 + 1), sizeof(bitword));
}
//возвращает значение idx-ого бита (0 или 1)
int bitsetGet (const bitword * arr , int idx ){
    int word_idx = idx/(sizeof(bitword) * 8);
    int in_word_idx = idx % (sizeof(bitword) * 8);
    bitword value = arr[word_idx] >> in_word_idx;
    return (value & 1);
}
//устанавливает значение idx-ого бита в newval (которое равно 0 или 1)
void bitsetSet ( bitword * arr , int idx , int newval ){
    if (bitsetGet(arr, idx) == newval){
        return;
    }
    int word_idx = idx/(sizeof(bitword) * 8);
    int in_word_idx = idx % (sizeof(bitword) * 8);
    arr[word_idx]^=1<<in_word_idx;
}
//возвращает 1, если среди битов с номерами k
//для left <= k < right есть единичный, и 0 иначе
int bitsetAny ( const bitword * arr , int left, int right){
    int l_word_idx = left/(sizeof(bitword) * 8);
    int l_in_word_idx = left % (sizeof(bitword) * 8);
    int r_word_idx = right/(sizeof(bitword) * 8);
    int r_in_word_idx = right % (sizeof(bitword) * 8);
    if (l_word_idx == r_word_idx){
        for(int i = l_in_word_idx; i < r_in_word_idx; i++){
            if (bitsetGet( arr, i+(l_word_idx*8)) == 1){
                return 1;
            }
        }
        return 0;
    }
    char tt = arr[l_word_idx]<<l_in_word_idx;
    char yu = arr[r_word_idx]>>(8-r_in_word_idx);
    //printf("%d %d ", bitsetGet(arr, left), bitsetGet(arr, right));
    // printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(arr[l_word_idx]));
    // printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(arr[r_word_idx]));
    // printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(tt));
    // printf( BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(yu));
    for (int i = left; i < (l_word_idx+1)*8; i++){
        if ( bitsetGet(arr, i) == 1){
            return 1;
        }
    }
    for (int i = r_word_idx*8; i < right; i++){
        if ( bitsetGet(arr, i) == 1){
            return 1;
        }
    }
    for (int i = l_word_idx+1; i < r_word_idx; i++){        
        if (arr[i] != 0){
            return 1;
        }
    }
    return 0;
}
int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    bitword *bitarr = NULL;
    for (int i = 0; i < n; i++){
        int operation;
        scanf("%d", &operation);
        if (operation == bit_zero){
            int num;
            scanf("%d", &num);
            bitsetZero(&bitarr, num);
        }
        else if (operation == bit_get){
            int index;
            scanf("%d", &index);
            printf("%d\n", bitsetGet(bitarr, index));
        }
        else if (operation == bit_set){
            int index, value;
            scanf("%d %d", &index, &value);
            bitsetSet(bitarr, index, value);
        }
        else if (operation == bit_any){
            int left, right;
            scanf("%d %d", &left, &right);
            int res = bitsetAny(bitarr, left, right);
            if (res == 1){
                printf("some\n");
            }
            else{
                printf("none\n");
            }
        }
    }
    free(bitarr);
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}