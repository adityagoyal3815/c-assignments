// Write a recursive version of the function reverse(s), which reverses the string s in place.


#include <stdio.h>
#include <string.h>

void reverse(char s[], int start, int end) {
  if (start >= end)
    return;
  reverse(s, start + 1, end - 1);
  char c = s[start];
  s[start] = s[end];
  s[end] = c;
}

int main() {
  char s[] = "level kayak level";
  reverse(s, 0, strlen(s) - 1);
  printf("%s\n", s);
  return 0;
}