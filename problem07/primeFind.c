/** Project Euler:
  Problem 7 solution. 
  What is the 10 001st prime number? 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int main(int argc, char **argv) {
  int primes[10002];
  int count;
  int i;
  primes[10001] = 0;
  primes[0] = 2;
  primes[1] = 3;
  count = 2;
  i = 4;
  while(primes[10001] == 0) {
    int j;
    for(j = 0; j < count; j++) {
      if(i % primes[j] == 0) {
        j = 0;
        i++;
      }
    }
    primes[count] = i;
    printf("%d Prime   = %d\n", count + 1,  primes[count]);
    count++;
    i++;
  }
  printf("6th Prime   = %d\n", primes[5]);
  printf("10001 Prime = %d\n", primes[10001]);
  return 0;
}


