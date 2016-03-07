/** Project Euler:
      Problem 3 solution. Find largest prime factor of 600851475143
*/

#include <stdio.h>
#include <stdlib.h>

#define VALUE 600851475143 

int isPrime(long d);

int main(int argc, char **argv) {
  int check;
  long factor;
  check = 0;
  factor = VALUE / 2;
  while(check != 1) {
    if(VALUE % factor == 0) {
      if(isPrime(factor)) {
        fprintf(stdout, "%ld", factor);
        break;
      }
    } 
  }
  return 0;
}

int isPrime(long d) {
  long i;
  for(i = d/2; :)
}

