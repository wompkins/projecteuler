/** Project Euler:
  Problem 17 solution. 
  If all the numbers from 1 to 1000 (one thousand) inclusive were
  written out in words, how many letters would be used? 
 */

// 342 = three hundred and forty-two = 23 letters

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

char *numDigit[10] = {"and", "one", "two", "three", "four",
  "five", "six", "seven", "eight", "nine"};
char *numTeens[11] = {"and", "ten", "eleven", "twelve", "thirteen",
  "fourteen", "fifteen", "sixteen", "seventeen",
  "eighteen", "nineteen"};
char *numOther[9] = {"and", "twenty", "thirty", "forty", "fifty", "sixty",
  "seventy", "eighty", "ninety"};

void numToWord(int num);

int main(int argc, char **argv) {
  int num;
  num = 1;
  for(; num <= 1000; num++) {
    printf("Printing %d:\n", num);
    numToWord(num);
  } 
  return 0;
}

void numToWord(int num) {
  char buff[500];
  if(num == 1000) {
    printf("one thousand \n");
    sprintf(buff, "one thousand");
  } else if(num > 99) {
    char tempH[50];
    char tempT[50];
    char tempS[50];
    printf("%s hundred ", numDigit[num/100]);
    sprintf(tempH, "%s hundred", numDigit[num/100]);
    num = num % 100;
    if(num > 19) {
      printf("%s %s", numOther[0], numOther[(num / 10) - 1]);
      sprintf(tempT, "%s %s", numOther[0], numOther[(num / 10) - 1]);
      num = num % 10;
      if(num > 0) {
        printf("-%s", numDigit[num]);
        sprintf(tempS, "-%s", numDigit[num]);
      }
    } else if(num > 9 && num < 20) {
      printf("%s %s", numTeens[0], numTeens[num - 9]);
      sprintf(tempT, "%s %s", numTeens[0], numTeens[num - 9]);
      num = 0;
    } 

    printf("\n");
  } else if(num > 19) {
    printf("%s", numOther[(num / 10) - 1]);
    if(num % 10 != 0) {
      printf("-%s", numDigit[num % 10]);
    }
    printf("\n");
    num = 0;
  } else if(num > 9 && num < 20) {
    printf("%s\n", numTeens[num - 9]);
    num = 0;
  } else if(num > 0){
    printf("%s\n", numDigit[num]);
  }
}

