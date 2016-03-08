/** Project Euler:
  Problem 6 solution. 

  Find the difference between the sum of the squares of the first 
  one hundred natural numbers and the square of the sum. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int main(int argc, char **argv) {
  uint64_t sumSquare;
  uint64_t squareSum;
  int i;
  sumSquare = 0;
  squareSum = 0;
  for(i = 1; i <= 100; i++) {
    squareSum += i;
    sumSquare += (i * i);
  }
  squareSum *= squareSum;
  printf("Difference = %" PRIu64 "\n", squareSum - sumSquare);
  return 0;
}


