/* Adapt the ideas of “printd” fucntion to write a recursive version of iota; i.e convert an integer into a string by calling a recursive routine.
 printd: print n in decimal  
void printd(int n) 
{ 
if (n < 0) 
{ 
putchar('-'); 
n = -n; 
} 
if (n / 10) 
printd(n / 10); 

putchar(n % 10 + '0'); 
} */

#include <stdio.h>
#include <string.h>
static int i;

void itoa_recursive(int n, char s[]) {
  if (n / 10) {
    itoa_recursive(n / 10, s);
  } else {
    i = 0;
    if (n < 0) {
      s[i++] = '-';
    }
  }

  int digit = n % 10;
  if (digit < 0) {
    digit = -digit;
  }

  s[i++] = digit + '0';
  s[i] = '\0';
}

int main() {
  char s[100];

  itoa_recursive(12345, s);
  printf("Result: %s\n", s);

  itoa_recursive(-12345, s);
  printf("Result: %s\n", s);

  return 0;
}