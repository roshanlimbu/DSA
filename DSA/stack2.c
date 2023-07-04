#include <conio.h>
#include <stdio.h>
#include <string.h>
#define MAX 10
#define TRUE 1
#define FALSE 0
#define NUlL 0
#include <stdlib.h>

typedef struct {
  char items[MAX];
  int tos;
} stack;
int IsEmpty(stack *sp) {
  if (sp->tos == 1) {
    return TRUE;
  } else {
    return FALSE;
  }
}
int IsFull(stack *sp) {
  if (sp->tos == MAX - 1) {
    return TRUE;
  } else {
    return FALSE;
  }
}
void pop(stack *sp) {
  if (IsEmpty(sp)) {
    printf("\nStack Underflow");
    exit(0);
  }
  sp->tos--;
}
void push(stack *sp, char ch) {
  if (IsFull(sp)) {
    printf("Stack is full.");
    exit(0);
  }
  sp->items[++sp->tos] = ch; // pushing after increasing the stack by 1
}
char peek(stack *sp) {
  if (IsEmpty(sp)) {
    return 0;
  } else {
    return sp->items[sp->tos];
  }
}
int main() {
  stack s;
  int i, valid = TRUE, ch;
  char exp[MAX];
  s.tos = -1; // empty stack
  printf("Enter your expression: ");
  fgets(exp, MAX, stdin);
  for (i = 0; i < strlen(exp); i++) {
    if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(') { // if opener
      push(&s, exp[i]);
    } else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')') { // if closer
      if (IsEmpty(&s)) {
        valid == FALSE;
        break;
      } else {
        ch = peek(&s);
        if ((ch == '[' && exp[i] != ']') || (ch == '{' && exp[i] != '}') ||
            (ch == '(' && exp[i] != ')')) {
          valid = FALSE;
          break;
        }
      }
    }
  }
  if (IsEmpty(&s) == FALSE) {
    valid = FALSE;
  }
  if (valid == TRUE) {
    printf("\nExpression is invalid");
  } else {
    printf("\n Expression is valid");
  }
}
