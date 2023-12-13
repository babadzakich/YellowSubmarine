#include <stdio.h>
#include <stdio.h>
#include <stdint.h>

uint64_t a, b, c, M;

uint64_t hash(uint64_t state)
{
  return (state * state * a + state * b + c) % M;
}

int main()
{
  scanf("%llu", &M);
  scanf("%llu %llu %llu", &a, &b, &c);
  uint64_t rabbitState, turtleState;
  rabbitState = turtleState = 1;
  rabbitState = hash(hash(rabbitState));
  turtleState = hash(turtleState);
  int counter = 0;
  while(rabbitState != turtleState)
  {
    rabbitState = hash(hash(rabbitState));
    turtleState = hash(turtleState);
  }
  rabbitState = 1;
  int leftCounter = 0;
  while(turtleState != rabbitState)
  {
    turtleState = hash(turtleState);
    rabbitState = hash(rabbitState);
    leftCounter++;
  }
  counter = leftCounter + 1;
  //turtleState = hash(turtleState);
  rabbitState = hash(turtleState);
  while(turtleState != rabbitState)
  {
    //turtleState = hash(turtleState);
    rabbitState = hash(rabbitState);
    counter ++;
  }
  printf("%d %d",leftCounter, counter);
  return 0;
}