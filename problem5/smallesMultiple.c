/** Project Euler:
  Problem 5 solution. 

  What is the smallest positive number that is evenly divisible 
  by all of the numbers from 1 to 20? 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int main(int argc, char **argv) {
  int multiple;
  int i;
  int check;
  multiple = 20;
  check = 0;
  while(check == 0) {
    for(i = 1; i <= 20; i++) {
      if(multiple % i != 0) {
        i = 1;
        multiple += 20;
      } 
    }
    check = 1;
  }
  printf("Smallest factor = %d\n", multiple);
  return 0;
}


