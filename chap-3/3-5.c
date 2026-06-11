/*
Write a version of iota that accepts three arguments instead of two. The third argument is a minimum field width, the converted number must be padded with blanks on the left if necessary to make it wide enough.
(Refer book to check the two argument version of iota function)
Sample test case : 
Format : (arg1, arg2, arg3, <expected_output>, <explanation>)
1. (0, 10, 5, "    0", "Convert zero to decimal with a minimum field width of 5")
*/

#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
  for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    char c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void iota(int n, int b, int width) {
  int sign = 0;
  if (n < 0) {
    sign = 1;
    n = -n;
  }
  char s[100];
  int i = 0;
  while (n > 0) {
    int rem = n % b;
    n /= b;
    if (rem < 10) {
      s[i++] = rem + '0';
    } else {
      s[i++] = rem - 10 + 'A';
    }
  }
  if (sign) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
  if (width > 0) {
    while (width-- > 0) {
      printf("\t");
    }
  }
  printf("%s", s);
}

int main() {
  iota(255, 2, 6);
  return 0;
}