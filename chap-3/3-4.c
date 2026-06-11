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