/** Project Euler:
  Problem 4 solution. Find largest palindrome from two 3-digit integers
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char *num);

int main(int argc, char **argv) {
  int x;
  int y;
  int len;
  int n;
  int product;
  int maxPalindrome;
  maxPalindrome = 0;
  x = 999;
  y = 999;
  while(x > 99) {
    n = 10;
    len = 1;
    product = x * y;
    while(product % n != product) {
      len++;
      n *=10;
    }
    char buff[len];
    sprintf(buff, "%d", product);
    if(isPalindrome(buff)) {
      if(product > maxPalindrome) {
        printf("x = %d\ty = %d\n", x, y);
        maxPalindrome = product;
      }
    }
    if(y > 99) {
      y--;
    } else {
      y = 999;
      x--;
    }
  }
  printf("Max Palindrome = %d\n", maxPalindrome);
  return 0;
}

int isPalindrome(char *num) {
  int len = strlen(num);
  int i, end, start;
  start = 0;
  end = len - 1;
  for(i = 0; i < len; i++) {
    if(num[start] != num[end]) {
      return 0;
    }
    start++;
    end--;
  }
  return 1;
}
