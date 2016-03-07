/** Project Euler:
      Problem 2 solution. Find sum of even-valued Fibonacci numbers
      that do not exceed 4 million
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 4000000

int main(int argc, char **argv) {
  int fib_new;
  int fib_prev0;
  int fib_prev1;
  int sum;
  fib_new = 2;
  fib_prev0 = 1;
  fib_prev1 = 2;
  sum = 0;
  while(fib_new < MAX_VALUE) {
    if (fib_new % 2 == 0) {
      sum += fib_new;
    }
    fib_new = fib_prev1 + fib_prev0;
    fib_prev0 = fib_prev1;
    fib_prev1 = fib_new;
  }
  fprintf(stdout, "%d\n", sum);
  return 0;
}
