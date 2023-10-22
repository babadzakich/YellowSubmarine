#include <stdio.h>

int main()
{
    int flat_number, known_flat_number, entrance_number, flat_floor, floor_amount, floors_passed, flats_on_floor;
    
    scanf("%d", &flat_number);
    scanf("%d %d %d %d", &known_flat_number, &entrance_number, &flat_floor, &floor_amount);
    
    floors_passed = floor_amount * (entrance_number - 1) + flat_floor;
    flats_on_floor = ((floors_passed - known_flat_number % floors_passed) + known_flat_number) / floors_passed;
    flat_number = flat_number / flats_on_floor;
    
    printf("%d %d", flat_number / floor_amount + 1, flat_number % floor_amount);
    return 0;
}