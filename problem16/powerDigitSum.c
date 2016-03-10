/** Project Euler:
  Problem 16 solution. 

  What is the sum of the digits of the number 2^1000? 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int main(int argc, char **argv) {
  int sum;
  int num[500];
  int i, j, k;
  int overflow;
  int prevOverflow;
  overflow = 0;
  prevOverflow = 0;
  num[0] = 1;
  sum = 0;
  for(i = 1; i < 500; i++) {
    num[i] = 0;
  }
  for(i = 0; i < 1000; i++) {
    for(j = 0; j < 500; j++) {
      overflow = (num[j] * 2) / 10;
      num[j] = ((num[j] * 2) % 10) + prevOverflow;
      prevOverflow = overflow;
    }
  }
  for(k = 0; k < 500; k++) {
    sum += num[k];
  }
  printf("Sum = %d\n\n", sum);
  return 0;
}


