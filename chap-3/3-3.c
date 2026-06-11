/* Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2 . Allow for
letters of either case and digits, and be prepared to handle cases like a-b-c
and a-z0-9 and -a-z . Arrange that a leading or trailing - is taken literally.
Sample test cases :
Input/s (s1): "a-z"
Output  (s2): "abcdefghijklmnopqrstuvwxyz"
Explanation : "Basic letter range expansion" */

#include <stdio.h>
#include <string.h>
void expand(char s1[], char s2[]) {
  int i, j;
  for (i = 0, j = 0; s1[i] != '\0'; i++) {
    if ((i == 0 || i == strlen(s1) - 1) && s1[i] == '-')
      continue;
    if (s1[i] == '-') {
      char left = s1[i - 1];
      char right = s1[i + 1];
      for (char k = left + 1; k <= right; k++) {
        s2[j++] = k;
      }
      i++;
    } else {
      s2[j++] = s1[i];
    }
  }
  s2[j] = '\0';
}
int main() {
  char s1[] = "-a-cde2-5A-Z";
  char s2[100];
  expand(s1, s2);
  printf("%s", s2);
  return 0;
}