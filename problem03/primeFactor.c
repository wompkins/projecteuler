/** Project Euler:
  Problem 3 solution. Find largest prime factor of 600851475143
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define VALUE 600851475143

uint64_t gcd(uint64_t a, uint64_t b);

// Used Pollard's rho algorithim
int main(int argc, char **argv) {
  uint64_t num = VALUE;
  fprintf(stdout, "num: %" PRIu64 "\n", num);
  uint64_t x = 2;
  uint64_t x_fixed = 2;
  uint64_t factor = 1;
  int count;
  int cycle = 999999;
  uint64_t max_factor = 1;

  while(num != 1){
    while(factor == 1) {
      for(count = 1; count <= cycle && factor <= 1; count++) {
        x = (x * x + 1) % num;
        factor = gcd(x - x_fixed, num);
      }
      cycle *= 2;
      x_fixed = x;
      if (factor > max_factor) {
        fprintf(stdout, "max factor: %" PRIu64 "\n", factor);
        max_factor = factor;
      }
      if(factor != 1) {
        num = num / factor;
        fprintf(stdout, "num now: %" PRIu64 "\n", num);
      }
    }
    factor = 1;
  }
  fprintf(stdout, "FINAL MAX FACTOR: %" PRId64 "\n", max_factor);
  return 0;
}

uint64_t gcd(uint64_t a, uint64_t b) {
  uint64_t remainder;
  while(b != 0) {
    remainder = a % b;
    a = b;
    b = remainder;
  }
  return a;
}
