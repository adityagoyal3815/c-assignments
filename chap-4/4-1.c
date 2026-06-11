#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t) {
  for (int i = strlen(s) - 1; i > 0; i--) {
    if (s[i] == t) {
      return i;
    }
  }
  return -1;
}

int main() {
  char s[] = "hello world";
  char t = 'o';
  printf("%d", strrindex(s, t));
  return 0;
}