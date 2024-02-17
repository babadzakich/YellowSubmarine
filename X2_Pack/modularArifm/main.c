#include "modular.h" //в этом хедере должны быть объявления
#include <assert.h>
#include<stdio.h>
int main() 
{
    MOD = 13; //устанавливаем глобальный модуль
    int a = 45;
    a = pnorm(a);
    assert(a == 6);
    int x = pmul(padd(7, psub(2, 3)), 5);
    assert(x == 4);
    int y = pdiv(7, x);
    assert(pmul(x, y) == 7);
    MOD = 2; //меняем модуль на другой
    assert(pnorm (5) == 1);
    assert(pnorm(-5) == 1);
    MOD = 3;
    assert(padd(2,2) == 1);
    assert(psub(1, 2) == 2);
    MOD = 479001599;
    assert(pmul(479001598, 200000000) == 279001599);
    
    long long large_a = 1000006;
    long long large_b = 1000006;
    long long r1 = pdiv(large_a,large_b);
    assert(r1 ==1);
    return 0;
}