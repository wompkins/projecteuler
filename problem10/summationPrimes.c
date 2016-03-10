/** Project Euler:
  Problem 10 solution. 
  Find the sum of all the primes below two million.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int main(int argc, char **argv) {
  int prime[1000000];
  int count;
  long sum;
  int num;
  prime[0] = 2;
  sum = 0;
  count = 1;
  num = 3;
  while(prime[count -1] < 2000000) {
    int i;
    if(prime[count -1] < 2000000) {
      sum += prime[count -1];
    }
    for(i = 0; i < count; i++) {
      if(num % prime[i] == 0) {
        i = 0;
        num+=2;
      }
    }
    prime[count] = num;
    num+=2;
    count++;
  }
  printf("Prime[%d] = %d\n", count, prime[count - 1]);
  printf("Sum = %ld\n", sum);
  return 0;
}


