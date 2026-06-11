/*

Given the basic framework, it's straightforward to write the calculator. Implement a calculator with basic arithmetic operations supported. Add the modulus ( % ) operator and provisions for negative numbers.*/


#include <stdio.h>
#include <string.h>
int add(int a, int b) { return a + b; }

int subtract(int a, int b) { return a - b; }

int multiply(int a, int b) { return a * b; }

int divide(int a, int b) { return a / b; }

void calculate(char s[]) {
  int result = 0;
  char op = '+';
  int num = 0;
  int sign = 1;

  for (int i = 0; i <= strlen(s); i++) {
    if (i == 0 && s[i] == '-') {
      sign = -1;
      continue;
    }

    if (s[i] >= '0' && s[i] <= '9') {
      num = num * 10 + (s[i] - '0');
    } else {
      num *= sign;
      sign = 1;
      
      if (op == '+') result = add(result, num);
      else if (op == '-') result = subtract(result, num);
      else if (op == '*') result = multiply(result, num);
      else if (op == '/') {
        if (num == 0) {
          printf("cannot divide by zero\n");
          return;
        }
        result = divide(result, num);
      }

      if (s[i] == '\0') break;
      op = s[i];
      num = 0;
    }
  }
  printf("%d\n", result);
}

int main() {
  calculate("3+4-1");
  return 0;
}