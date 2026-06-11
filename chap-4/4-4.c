#include <stdio.h>
#include <string.h>

int stack[100];

int top = -1;

void push(int stack[], int c) { stack[++top] = c; }

void pop(int stack[]) { stack[top--] = '\0'; }

void printTop(int stack[]) { printf("%d\n", stack[top]); }

void duplicate(int stack[], int copy[], int top) {
  for (int i = 0; i <= top; i++) {
    copy[i] = stack[i];
  }
}

void swap(int stack[]) {
  if (top < 1) {
    printf("not enough elements to swap\n");
    return;
  }
  int temp = stack[top];
  stack[top] = stack[top - 1];
  stack[top - 1] = temp;
}

void clearStack() {
  top = -1;
  printf("stack cleared\n");
}

void displayStack(int stack[]) {
  if (top == -1) {
    printf("empty stack\n");
    return;
  }
  for (int i = 0; i <= top; i++) {
    printf("%d ", stack[i]);
  }
  printf("\n");
}

int main() {
  int stack[100];
  push(stack, 1);
  push(stack, 2);
  push(stack, 3);
  printTop(stack);
  swap(stack);
  printTop(stack);
  pop(stack);
  int copy[100];
  duplicate(stack,copy,top);
  displayStack(copy);
  printTop(stack);
  displayStack(stack);
  clearStack();
  displayStack(stack);
  return 0;
}