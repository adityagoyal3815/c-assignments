/*Write the function itob(n,b,s) that converts the integer n into a base b character representation in the string s . In particular, itob(n,16,s) formats n as a hexadecimal integer in s .
Sample test case : 
Format : (n, b, s, <explanation>) where n, b are inputs and s is expected output
1. (42, 10, "42", "Convert positive integer to decimal")
2. (255, 16, "FF", "Convert 255 to hexadecimal")*/


#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
  int i, j;
  char c;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itob(int n, int b, char s[]) {
  int i = 0;
  int sign = 0;

  if (n < 0) {
    sign = 1;
    n = -n;
  }

  if (n == 0) {
    s[i++] = '0';
  } else {
    while (n > 0) {
      int rem = n % b;
      n /= b;

      if (rem < 10) {
        s[i++] = rem + '0';
      } else {
        s[i++] = rem - 10 + 'A';
      }
    }
  }

  if (sign)
    s[i++] = '-';

  s[i] = '\0';
  reverse(s);
}

int main() {
  char s[100];
  itob(-525232, 13, s);
  printf("%s", s);
  return 0;
}