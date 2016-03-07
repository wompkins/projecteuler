/** Project Euler:
      Problem 1 solution. Find sum of multiples 3 or 5 for numbers
      less than 1000
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int sum;
  int count;
  sum = 0;
  for (count = 0; count < 1000; count++) {
    if (count % 3 == 0 || count % 5 == 0) {
      sum += count;
    }
  }
  fprintf(stdout, "%d\n", sum);
  return 0;
}
