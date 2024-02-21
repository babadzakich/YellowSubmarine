#include "primes.h"
#include <stdio.h>
#include<assert.h>


int main()
{    
    assert(findNextPrime(100) == 101);
    assert(findNextPrime(999999) == 1000003);
    assert(getPrimesCount(5, 500) == 93);
    /*Weak tests: Add test cases when x, l, and r are either prime 
    or differ from prime by 1 */
    
    assert(isPrime(5) == 1);
    assert(isPrime(11) == 1);
    assert(isPrime(3947) == 1);
    assert(isPrime(3967) == 1);
    
    assert(isPrime(6) == 0);
    assert(isPrime(14) == 0);
    assert(isPrime(15) == 0);
    assert(isPrime(16) == 0); 
    assert(isPrime(4) == 0);

    assert(findNextPrime(5) == 5);
    assert(findNextPrime(191) == 191);
    assert(findNextPrime(13) == 13);
    assert(findNextPrime(17) == 17);

    assert(findNextPrime(6) == 7);
    assert(findNextPrime(192) == 193);
    assert(findNextPrime(14) == 17);
    assert(findNextPrime(3966) == 3967);
    
    assert(getPrimesCount(5, 11) == 2);
    assert(getPrimesCount(307, 383) == 13);
    assert(getPrimesCount(5, 383) == 73);
    assert(getPrimesCount(4, 382) == 73);
    assert(getPrimesCount(5381, 5557) == 24);
    assert(getPrimesCount(5382, 5558) == 24);
    assert(getPrimesCount(3229, 3331) == 13);
    /*Weak tests: Empty interval is a special case worth checking...*/
    assert(getPrimesCount(5,5) == 0);
    assert(getPrimesCount(356,356) == 0);
    assert(getPrimesCount(400, 400) == 0);
    /* Weak tests: Did you check that small numbers from zero to two are classified properly?*/
    assert(isPrime(0) == 0);
    assert(isPrime(1) == 0);
    assert(isPrime(2) == 1);

    assert(findNextPrime(0) == 2);
    assert(findNextPrime(1) == 2);
    assert(findNextPrime(2) == 2);

    assert(getPrimesCount(0,3) == 1);

    /*Weak tests: No check for primes count on large interval... 
    And you say your implementation is well-tested? 
    Are you kidding me?! =)*/
    assert(getPrimesCount(5, 999999)==78496);
    assert(getPrimesCount(3, 999999)==78497);
    assert(getPrimesCount(0, 10000000)==664579);
    /*Weak tests: Cases with maximum possible value of x and r should be tested. 
    People often make mistakes with the last element of array.*/
    assert(isPrime(10000000) == 0);
    assert(isPrime(9999999) == 0);
    assert(findNextPrime(10000000) == 10000019);
    assert(getPrimesCount(0, 10000000)==664579);
    //printf("%d\n", findNextPrime(10000000));
}