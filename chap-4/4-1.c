/*Write the function strrindex(s,t) where s, t are strings, which returns the position of the rightmost occurrence of t in s , or -1 if there is none.
Sample test case : 
Format : (s, t, <expected_output>, <explanation>) where s, t are strings
1. ("hello world", "o", 7, "Basic test case with 'o' in 'hello world'")
2. ("hello world", "z", -1, "Character not found in the string")
Note : Expected output is an integer. */

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