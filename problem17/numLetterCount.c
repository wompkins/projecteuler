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

char *numDigit[9] = {"one", "two", "three", "four",
  "five", "six", "seven", "eight", "nine"};
char *numTeens[10] = {"ten", "eleven", "twelve", "thirteen",
  "fourteen", "fifteen", "sixteen", "seventeen",
  "eighteen", "nineteen"};
char *numOther[8] = {"twenty", "thirty", "forty", "fifty", "sixty",
  "seventy", "eighty", "ninety"};

int numToWord(int num);

int main(int argc, char **argv) {
  int num;
  int sum;
  sum = 0;
  num = 1;
  for(; num <= 1000; num++) {
    sum += numToWord(num);
  } 
  printf("Sum = %d\n", sum);
  return 0;
}

/** 
Length:
4 = "one thousand"
3 = "hundreds place" (and) (tens place) (single place)
2 = "tens place" (single place)
Two Cases: num > 19 OR 9 < num < 20
1 = "tens place" (single place)
 */
int numToWord(int n) {
  char num[50];
  char total[100];
  int count;
  int len;
  sprintf(num, "%d", n);
  len = strlen(num);
  count = 0;
  if(len == 4) {
    sprintf(total, "%s", "onethousand");
  } else if(len == 3) {
    // hundreds place
    sprintf(total, "%s%s", numDigit[(int)num[0] - 49], "hundred");
    if(num[1] != '0') {
      if(num[1] > '1') {
        // 20 through 90
        sprintf(total, "%s%s%s", total, "and", numOther[(int)num[1] - 50]);
        if(num[2] != '0') {
          // ones place for 20 thorugh 90
          sprintf(total, "%s%s", total, numDigit[(int)num[2] - 49]);
        }
        // tens place 10 through 19  
      } else {
        sprintf(total, "%s%s%s", total, "and", numTeens[(int)num[2] - 48]);
      }
    } else if(num[2] != '0') {
      sprintf(total, "%s%s%s", total, "and", numDigit[(int)num[2] - 49]);
    }
  } else if(len == 2) {
    // num > 19
    if(num[0] > '1') {
      sprintf(total, "%s", numOther[(int)num[0] - 50]);
      if(num[1] != '0') {
        sprintf(total, "%s%s", total, numDigit[(int)num[1] - 49]);
      }
      // tens place 10 through 19  
    } else {
      sprintf(total, "%s", numTeens[(int)num[1] - 48]);
    }
  } else {
    sprintf(total, "%s", numDigit[(int)num[0] - 49]);
  }
  count += strlen(total);
  printf("Num = %s\tString = %s\tCount = %d\n", num, total, count);
  return count;
}

