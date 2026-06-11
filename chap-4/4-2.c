/* 
Extend atof to handle scientific notation of the form 123	.45e-6 where a floating-point number may be followed by e or E and an optionally signed exponent
Sample test case : 
Format : (<input>, <expected_output>, <explanantion>)
1. ("123.45e-6", 0.00012345, "Basic scientific notation with a negative exponent") */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert(char s[]) {

  char r[100];

  int i = 0, k = 0;
  int beforedecimal = 0;
  int afterdecimal = 0;

  while (s[i] != '.' && s[i] != '\0' && s[i] != 'e' && s[i] != 'E') {
    beforedecimal++;
    i++;
  }
  if (s[i] == '.')
    i++;
  while (s[i] != 'e' && s[i] != 'E' && s[i] != '\0') {
    afterdecimal++;
    i++;
  }
  int sign = (s[i + 1] == '-') ? 1 : 0;
  int power = (s[i + 1] == '-') ? s[i + 2] - '0' : s[i + 1] - '0';

  int newdot = sign ? beforedecimal - power : beforedecimal + power;
  int totaldigits = beforedecimal + afterdecimal;

  if (newdot <= 0) {
    r[k++] = '0';
    r[k++] = '.';
    for (int z = 0; z < -newdot; z++)
      r[k++] = '0';
  }

  int j = 0, count = 0;
  while (s[j] != 'e' && s[j] != 'E') {
    if (s[j] != '.') {
      if (count == newdot && newdot > 0 && newdot < totaldigits) {
        r[k++] = '.';
      }
      r[k++] = s[j];
      count++;
    }
    j++;
  }

  for (int z = totaldigits; z < newdot; z++)
    r[k++] = '0';

  r[k] = '\0';
  printf("%s", r);
}

int main() {
  convert("123.45e-6");
  printf("\n");
  convert("12321321.345e-6");
  printf("\n");
  convert("1.5e3");
  printf("\n");
  return 0;
}